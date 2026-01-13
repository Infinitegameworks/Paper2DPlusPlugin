#include "CharacterDataJsonImporter.h"
#include "DesktopPlatformModule.h"
#include "IDesktopPlatform.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "UObject/SavePackage.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Misc/PackageName.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"
#include "Framework/Application/SlateApplication.h"
#include "Editor.h"

#define LOCTEXT_NAMESPACE "CharacterDataJsonImporter"

// Helper function to sanitize Content Browser paths
static FString SanitizePackagePath(const FString& InPath)
{
	FString Result = InPath;

	// UE5 Content Browser returns virtual paths like "/All/Game/..."
	// We need actual package paths like "/Game/..."
	if (Result.StartsWith(TEXT("/All/")))
	{
		Result = Result.RightChop(4); // Remove "/All"
	}

	// Also handle "/All" without trailing content
	if (Result == TEXT("/All"))
	{
		Result = TEXT("/Game");
	}

	// Validate it's a proper package path
	if (!Result.StartsWith(TEXT("/")))
	{
		Result = TEXT("/Game");
	}

	// Final validation
	if (!FPackageName::IsValidLongPackageName(Result, false))
	{
		UE_LOG(LogTemp, Warning, TEXT("CharacterDataImporter: Invalid path '%s', defaulting to /Game"), *InPath);
		Result = TEXT("/Game");
	}

	UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter: Sanitized path '%s' -> '%s'"), *InPath, *Result);
	return Result;
}

void FCharacterDataJsonImporter::ShowImportDialog()
{
	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	if (!DesktopPlatform) return;

	// Show file picker
	TArray<FString> SelectedFiles;
	const bool bOpened = DesktopPlatform->OpenFileDialog(
		FSlateApplication::Get().FindBestParentWindowHandleForDialogs(nullptr),
		TEXT("Import Character Data"),
		FPaths::ProjectContentDir(),
		TEXT(""),
		TEXT("JSON Files (*.json)|*.json"),
		EFileDialogFlags::None,
		SelectedFiles
	);

	if (bOpened && SelectedFiles.Num() > 0)
	{
		const FString& JsonFilePath = SelectedFiles[0];
		FString AssetName = FPaths::GetBaseFilename(JsonFilePath);

		// Get current Content Browser path
		FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
		TArray<FString> SelectedPaths;
		ContentBrowserModule.Get().GetSelectedPathViewFolders(SelectedPaths);

		FString DestinationPath = TEXT("/Game");
		if (SelectedPaths.Num() > 0)
		{
			DestinationPath = SanitizePackagePath(SelectedPaths[0]);
		}

		FString ErrorMessage;
		UPaper2DPlusCharacterDataAsset* NewAsset = ImportFromFile(JsonFilePath, DestinationPath, AssetName, ErrorMessage);

		if (NewAsset)
		{
			// Select the new asset in Content Browser
			TArray<UObject*> AssetsToSync;
			AssetsToSync.Add(NewAsset);
			ContentBrowserModule.Get().SyncBrowserToAssets(AssetsToSync);
		}
		else
		{
			// Show error dialog
			FMessageDialog::Open(EAppMsgType::Ok,
				FText::Format(LOCTEXT("ImportFailed", "Failed to import character data:\n{0}"),
				FText::FromString(ErrorMessage)));
		}
	}
}

UPaper2DPlusCharacterDataAsset* FCharacterDataJsonImporter::ImportFromFile(
	const FString& JsonFilePath,
	const FString& DestinationPath,
	const FString& AssetName,
	FString& OutErrorMessage)
{
	// Read file
	FString JsonString;
	if (!FFileHelper::LoadFileToString(JsonString, *JsonFilePath))
	{
		OutErrorMessage = FString::Printf(TEXT("Failed to read file: %s"), *JsonFilePath);
		return nullptr;
	}

	// Parse JSON
	TArray<FAnimationHitboxData> Animations;
	if (!ParseJsonToCharacterData(JsonString, Animations, OutErrorMessage))
	{
		return nullptr;
	}

	// Create the asset
	FString PackagePath = DestinationPath / AssetName;
	UPackage* Package = CreatePackage(*PackagePath);
	if (!Package)
	{
		OutErrorMessage = FString::Printf(TEXT("Failed to create package: %s"), *PackagePath);
		return nullptr;
	}

	UPaper2DPlusCharacterDataAsset* NewAsset = NewObject<UPaper2DPlusCharacterDataAsset>(Package, *AssetName, RF_Public | RF_Standalone);
	if (!NewAsset)
	{
		OutErrorMessage = TEXT("Failed to create asset object");
		return nullptr;
	}

	// Populate the asset
	NewAsset->DisplayName = AssetName;
	NewAsset->Animations = Animations;
	NewAsset->SourceFilePath = JsonFilePath;
	NewAsset->LastImportTime = FDateTime::Now();

	// Mark dirty and save
	NewAsset->MarkPackageDirty();
	FAssetRegistryModule::AssetCreated(NewAsset);

	// Save the package
	FString PackageFilename = FPackageName::LongPackageNameToFilename(PackagePath, FPackageName::GetAssetPackageExtension());
	FSavePackageArgs SaveArgs;
	SaveArgs.TopLevelFlags = RF_Public | RF_Standalone;
	UPackage::SavePackage(Package, NewAsset, *PackageFilename, SaveArgs);

	return NewAsset;
}

bool FCharacterDataJsonImporter::ImportToExistingAsset(
	const FString& JsonFilePath,
	UPaper2DPlusCharacterDataAsset* Asset,
	FString& OutErrorMessage)
{
	if (!Asset)
	{
		OutErrorMessage = TEXT("Invalid asset");
		return false;
	}

	if (!FPaths::FileExists(JsonFilePath))
	{
		OutErrorMessage = FString::Printf(TEXT("File not found: %s"), *JsonFilePath);
		return false;
	}

	// Read file
	FString JsonString;
	if (!FFileHelper::LoadFileToString(JsonString, *JsonFilePath))
	{
		OutErrorMessage = FString::Printf(TEXT("Failed to read file: %s"), *JsonFilePath);
		return false;
	}

	// Parse JSON
	TArray<FAnimationHitboxData> Animations;
	if (!ParseJsonToCharacterData(JsonString, Animations, OutErrorMessage))
	{
		return false;
	}

	// Preserve Flipbook references and dimension data
	TMap<FString, TSoftObjectPtr<UPaperFlipbook>> ExistingFlipbooks;
	TMap<FString, TSoftObjectPtr<UTexture2D>> ExistingTextures;
	TMap<FString, FIntPoint> ExistingDimensions;
	for (const FAnimationHitboxData& Anim : Asset->Animations)
	{
		if (!Anim.Flipbook.IsNull())
		{
			ExistingFlipbooks.Add(Anim.AnimationName, Anim.Flipbook);
		}
		if (!Anim.SourceTexture.IsNull())
		{
			ExistingTextures.Add(Anim.AnimationName, Anim.SourceTexture);
		}
		if (Anim.SpriteDimensions != FIntPoint::ZeroValue)
		{
			ExistingDimensions.Add(Anim.AnimationName, Anim.SpriteDimensions);
		}
	}

	// Update the asset
	Asset->Animations = Animations;
	Asset->SourceFilePath = JsonFilePath;
	Asset->LastImportTime = FDateTime::Now();

	// Restore preserved data
	for (FAnimationHitboxData& Anim : Asset->Animations)
	{
		if (TSoftObjectPtr<UPaperFlipbook>* Flipbook = ExistingFlipbooks.Find(Anim.AnimationName))
		{
			Anim.Flipbook = *Flipbook;
		}
		if (TSoftObjectPtr<UTexture2D>* Texture = ExistingTextures.Find(Anim.AnimationName))
		{
			Anim.SourceTexture = *Texture;
		}
		if (FIntPoint* Dims = ExistingDimensions.Find(Anim.AnimationName))
		{
			Anim.SpriteDimensions = *Dims;
		}
	}

	Asset->MarkPackageDirty();

	return true;
}

bool FCharacterDataJsonImporter::ReimportAsset(UPaper2DPlusCharacterDataAsset* Asset, FString& OutErrorMessage)
{
	if (!Asset)
	{
		OutErrorMessage = TEXT("Invalid asset");
		return false;
	}

	if (Asset->SourceFilePath.IsEmpty())
	{
		OutErrorMessage = TEXT("No source file path stored");
		return false;
	}

	return ImportToExistingAsset(Asset->SourceFilePath, Asset, OutErrorMessage);
}

bool FCharacterDataJsonImporter::ParseJsonToCharacterData(
	const FString& JsonString,
	TArray<FAnimationHitboxData>& OutAnimations,
	FString& OutErrorMessage)
{
	TSharedPtr<FJsonObject> RootObject;
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonString);

	if (!FJsonSerializer::Deserialize(Reader, RootObject) || !RootObject.IsValid())
	{
		OutErrorMessage = FString::Printf(TEXT("Failed to parse JSON: %s"), *Reader->GetErrorMessage());
		return false;
	}

	OutAnimations.Empty();

	UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter: Parsing JSON with %d root entries"), RootObject->Values.Num());

	// Check for new schema with _meta and flipbooks
	TSharedPtr<FJsonObject> FlipbooksContainer = RootObject;
	if (RootObject->HasField(TEXT("_meta")))
	{
		UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter: Detected new schema with _meta"));

		const TSharedPtr<FJsonObject>* FlipbooksObject;
		if (RootObject->TryGetObjectField(TEXT("flipbooks"), FlipbooksObject))
		{
			FlipbooksContainer = *FlipbooksObject;
			UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter: Found flipbooks container with %d entries"), FlipbooksContainer->Values.Num());
		}
		else
		{
			OutErrorMessage = TEXT("JSON has _meta but no flipbooks object");
			return false;
		}
	}

	// Iterate through flipbooks/animations
	for (const auto& RootPair : FlipbooksContainer->Values)
	{
		const FString& AnimationName = RootPair.Key;
		const TSharedPtr<FJsonValue>& Value = RootPair.Value;

		if (Value->Type != EJson::Object) continue;

		TSharedPtr<FJsonObject> AnimationObject = Value->AsObject();

		FAnimationHitboxData AnimData;
		AnimData.AnimationName = AnimationName;

		UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter: Processing animation '%s'"), *AnimationName);

		// Check for new format with "flipbook" and "frames" fields
		if (AnimationObject->HasField(TEXT("frames")))
		{
			// New format: { "AnimationName": { "flipbook": "...", "frames": { "frame1": {...} } } }
			UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter: '%s' using new format (has 'frames' field)"), *AnimationName);

			// Auto-link flipbook if specified
			FString FlipbookName;
			if (AnimationObject->TryGetStringField(TEXT("flipbook"), FlipbookName))
			{
				UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter: '%s' has flipbook hint '%s'"), *AnimationName, *FlipbookName);
				AnimData.Flipbook = FindFlipbookByName(FlipbookName);
			}

			// Check for dimension fields (new Paper2DPlus schema)
			FString SourceTexturePath;
			if (AnimationObject->TryGetStringField(TEXT("sourceTexture"), SourceTexturePath))
			{
				UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter: '%s' has sourceTexture '%s'"), *AnimationName, *SourceTexturePath);
				AnimData.SourceTexture = TSoftObjectPtr<UTexture2D>(FSoftObjectPath(SourceTexturePath));
			}

			const TArray<TSharedPtr<FJsonValue>>* DimensionsArray;
			if (AnimationObject->TryGetArrayField(TEXT("spriteDimensions"), DimensionsArray) && DimensionsArray->Num() >= 2)
			{
				AnimData.SpriteDimensions.X = (int32)(*DimensionsArray)[0]->AsNumber();
				AnimData.SpriteDimensions.Y = (int32)(*DimensionsArray)[1]->AsNumber();
				UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter: '%s' has dimensions %dx%d"), *AnimationName, AnimData.SpriteDimensions.X, AnimData.SpriteDimensions.Y);
			}

			const TSharedPtr<FJsonObject>* FramesObject;
			if (AnimationObject->TryGetObjectField(TEXT("frames"), FramesObject))
			{
				for (const auto& FramePair : (*FramesObject)->Values)
				{
					if (FramePair.Value->Type == EJson::Object)
					{
						FFrameHitboxData FrameData = ParseFrameFromJson(FramePair.Key, FramePair.Value->AsObject());
						AnimData.Frames.Add(FrameData);
						UE_LOG(LogTemp, Verbose, TEXT("CharacterDataImporter: '%s' added frame '%s' (%d hitboxes, %d sockets)"),
							*AnimationName, *FrameData.FrameName, FrameData.Hitboxes.Num(), FrameData.Sockets.Num());
					}
				}
			}

			if (AnimData.Frames.Num() > 0)
			{
				UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter: '%s' complete with %d frames"), *AnimationName, AnimData.Frames.Num());
				OutAnimations.Add(AnimData);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("CharacterDataImporter: '%s' has no frames, skipping"), *AnimationName);
			}
		}
		else
		{
			// Legacy format: check if children are frames directly
			UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter: '%s' checking legacy format"), *AnimationName);
			bool bHasFrameData = false;
			for (const auto& ChildPair : AnimationObject->Values)
			{
				if (ChildPair.Value->Type == EJson::Object)
				{
					TSharedPtr<FJsonObject> ChildObj = ChildPair.Value->AsObject();
					if (ChildObj->HasField(TEXT("hitboxes")) || ChildObj->HasField(TEXT("sockets")))
					{
						bHasFrameData = true;
						FFrameHitboxData FrameData = ParseFrameFromJson(ChildPair.Key, ChildObj);
						AnimData.Frames.Add(FrameData);
					}
				}
			}

			if (bHasFrameData && AnimData.Frames.Num() > 0)
			{
				UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter: '%s' (legacy grouped) complete with %d frames"), *AnimationName, AnimData.Frames.Num());
				OutAnimations.Add(AnimData);
			}
			else if (AnimationObject->HasField(TEXT("hitboxes")) || AnimationObject->HasField(TEXT("sockets")))
			{
				// Flat format: root-level frames without animation grouping
				UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter: '%s' using flat format, adding to 'Default' animation"), *AnimationName);
				FAnimationHitboxData* DefaultAnim = nullptr;
				for (FAnimationHitboxData& Anim : OutAnimations)
				{
					if (Anim.AnimationName == TEXT("Default"))
					{
						DefaultAnim = &Anim;
						break;
					}
				}

				if (!DefaultAnim)
				{
					FAnimationHitboxData NewAnim;
					NewAnim.AnimationName = TEXT("Default");
					OutAnimations.Add(NewAnim);
					DefaultAnim = &OutAnimations.Last();
					UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter: Created 'Default' animation for flat format frames"));
				}

				FFrameHitboxData FrameData = ParseFrameFromJson(AnimationName, AnimationObject);
				DefaultAnim->Frames.Add(FrameData);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("CharacterDataImporter: '%s' has no recognizable frame data, skipping"), *AnimationName);
			}
		}
	}

	// Summary
	UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter: === Import Summary ==="));
	UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter: Total animations: %d"), OutAnimations.Num());
	for (const FAnimationHitboxData& Anim : OutAnimations)
	{
		UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter:   - '%s': %d frames, Flipbook: %s, Dims: %dx%d"),
			*Anim.AnimationName,
			Anim.Frames.Num(),
			Anim.Flipbook.IsNull() ? TEXT("(none)") : *Anim.Flipbook.GetAssetName(),
			Anim.SpriteDimensions.X, Anim.SpriteDimensions.Y);
	}
	UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter: ======================"));

	return true;
}

EHitboxType FCharacterDataJsonImporter::ParseHitboxType(const FString& TypeString)
{
	if (TypeString.Equals(TEXT("hurtbox"), ESearchCase::IgnoreCase))
	{
		return EHitboxType::Hurtbox;
	}
	else if (TypeString.Equals(TEXT("collision"), ESearchCase::IgnoreCase))
	{
		return EHitboxType::Collision;
	}
	return EHitboxType::Attack;
}

FHitboxData FCharacterDataJsonImporter::ParseHitboxFromJson(const TSharedPtr<FJsonObject>& JsonObject)
{
	FHitboxData Hitbox;
	if (!JsonObject.IsValid()) return Hitbox;

	FString TypeStr;
	if (JsonObject->TryGetStringField(TEXT("type"), TypeStr))
	{
		Hitbox.Type = ParseHitboxType(TypeStr);
	}

	const TArray<TSharedPtr<FJsonValue>>* RectArray;
	if (JsonObject->TryGetArrayField(TEXT("rect"), RectArray) && RectArray->Num() >= 4)
	{
		Hitbox.X = (int32)(*RectArray)[0]->AsNumber();
		Hitbox.Y = (int32)(*RectArray)[1]->AsNumber();
		Hitbox.Width = (int32)(*RectArray)[2]->AsNumber();
		Hitbox.Height = (int32)(*RectArray)[3]->AsNumber();
	}

	// Check for stats object (new schema) or flat damage/knockback (old schema)
	const TSharedPtr<FJsonObject>* StatsObject;
	if (JsonObject->TryGetObjectField(TEXT("stats"), StatsObject))
	{
		// New schema: stats nested in object
		Hitbox.Damage = (int32)(*StatsObject)->GetNumberField(TEXT("damage"));
		Hitbox.Knockback = (int32)(*StatsObject)->GetNumberField(TEXT("knockback"));
	}
	else
	{
		// Old schema: flat fields
		Hitbox.Damage = (int32)JsonObject->GetNumberField(TEXT("damage"));
		Hitbox.Knockback = (int32)JsonObject->GetNumberField(TEXT("knockback"));
	}

	return Hitbox;
}

FSocketData FCharacterDataJsonImporter::ParseSocketFromJson(const TSharedPtr<FJsonObject>& JsonObject)
{
	FSocketData Socket;
	if (!JsonObject.IsValid()) return Socket;

	JsonObject->TryGetStringField(TEXT("name"), Socket.Name);

	const TArray<TSharedPtr<FJsonValue>>* PosArray;
	if (JsonObject->TryGetArrayField(TEXT("pos"), PosArray) && PosArray->Num() >= 2)
	{
		Socket.X = (int32)(*PosArray)[0]->AsNumber();
		Socket.Y = (int32)(*PosArray)[1]->AsNumber();
	}

	return Socket;
}

FFrameHitboxData FCharacterDataJsonImporter::ParseFrameFromJson(const FString& FrameName, const TSharedPtr<FJsonObject>& JsonObject)
{
	FFrameHitboxData FrameData;
	FrameData.FrameName = FrameName;

	if (!JsonObject.IsValid()) return FrameData;

	const TArray<TSharedPtr<FJsonValue>>* HitboxArray;
	if (JsonObject->TryGetArrayField(TEXT("hitboxes"), HitboxArray))
	{
		for (const TSharedPtr<FJsonValue>& HitboxValue : *HitboxArray)
		{
			if (HitboxValue->Type == EJson::Object)
			{
				FHitboxData Hitbox = ParseHitboxFromJson(HitboxValue->AsObject());
				FrameData.Hitboxes.Add(Hitbox);
			}
		}
	}

	const TArray<TSharedPtr<FJsonValue>>* SocketArray;
	if (JsonObject->TryGetArrayField(TEXT("sockets"), SocketArray))
	{
		for (const TSharedPtr<FJsonValue>& SocketValue : *SocketArray)
		{
			if (SocketValue->Type == EJson::Object)
			{
				FSocketData Socket = ParseSocketFromJson(SocketValue->AsObject());
				FrameData.Sockets.Add(Socket);
			}
		}
	}

	return FrameData;
}

TSoftObjectPtr<UPaperFlipbook> FCharacterDataJsonImporter::FindFlipbookByName(const FString& FlipbookName)
{
	if (FlipbookName.IsEmpty())
	{
		return nullptr;
	}

	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	IAssetRegistry& AssetRegistry = AssetRegistryModule.Get();

	// Search for PaperFlipbook assets
	TArray<FAssetData> FlipbookAssets;
	AssetRegistry.GetAssetsByClass(UPaperFlipbook::StaticClass()->GetClassPathName(), FlipbookAssets);

	for (const FAssetData& Asset : FlipbookAssets)
	{
		if (Asset.AssetName.ToString().Equals(FlipbookName, ESearchCase::IgnoreCase))
		{
			UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter: Auto-linked flipbook '%s' -> %s"), *FlipbookName, *Asset.GetObjectPathString());
			return TSoftObjectPtr<UPaperFlipbook>(Asset.ToSoftObjectPath());
		}
	}

	UE_LOG(LogTemp, Log, TEXT("CharacterDataImporter: No flipbook found matching '%s'"), *FlipbookName);
	return nullptr;
}

#undef LOCTEXT_NAMESPACE
