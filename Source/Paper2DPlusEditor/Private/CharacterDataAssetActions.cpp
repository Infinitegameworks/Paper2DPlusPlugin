#include "CharacterDataAssetActions.h"
#include "CharacterDataJsonImporter.h"
#include "CharacterDataAssetEditor.h"
#include "ToolMenuSection.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "HAL/PlatformFileManager.h"
#include "Misc/Paths.h"
#include "Misc/MessageDialog.h"
#include "DesktopPlatformModule.h"
#include "Framework/Application/SlateApplication.h"

#define LOCTEXT_NAMESPACE "CharacterDataAssetActions"

void FCharacterDataAssetActions::GetActions(const TArray<UObject*>& InObjects, FToolMenuSection& Section)
{
	TArray<TWeakObjectPtr<UPaper2DPlusCharacterDataAsset>> Assets;
	for (UObject* Object : InObjects)
	{
		if (UPaper2DPlusCharacterDataAsset* Asset = Cast<UPaper2DPlusCharacterDataAsset>(Object))
		{
			Assets.Add(Asset);
		}
	}

	Section.AddMenuEntry(
		"CharacterData_Import",
		LOCTEXT("Import", "Import from JSON..."),
		LOCTEXT("ImportTooltip", "Import hitbox data from a JSON file"),
		FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.Import"),
		FUIAction(FExecuteAction::CreateSP(this, &FCharacterDataAssetActions::ExecuteImportFromJson, Assets))
	);

	Section.AddMenuEntry(
		"CharacterData_Reimport",
		LOCTEXT("Reimport", "Reimport from JSON"),
		LOCTEXT("ReimportTooltip", "Reimport hitbox data from the source JSON file"),
		FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.Refresh"),
		FUIAction(
			FExecuteAction::CreateSP(this, &FCharacterDataAssetActions::ExecuteReimport, Assets),
			FCanExecuteAction::CreateLambda([Assets]()
			{
				for (const auto& Asset : Assets)
				{
					if (Asset.IsValid() && !Asset->SourceFilePath.IsEmpty() && FPaths::FileExists(Asset->SourceFilePath))
						return true;
				}
				return false;
			})
		)
	);

	Section.AddMenuEntry(
		"CharacterData_ShowSource",
		LOCTEXT("ShowSource", "Show Source File"),
		LOCTEXT("ShowSourceTooltip", "Open the folder containing the source JSON file"),
		FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.FolderOpen"),
		FUIAction(
			FExecuteAction::CreateSP(this, &FCharacterDataAssetActions::ExecuteShowInExplorer, Assets),
			FCanExecuteAction::CreateLambda([Assets]()
			{
				for (const auto& Asset : Assets)
				{
					if (Asset.IsValid() && !Asset->SourceFilePath.IsEmpty() && FPaths::FileExists(Asset->SourceFilePath))
						return true;
				}
				return false;
			})
		)
	);
}

void FCharacterDataAssetActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	for (UObject* Object : InObjects)
	{
		if (UPaper2DPlusCharacterDataAsset* Asset = Cast<UPaper2DPlusCharacterDataAsset>(Object))
		{
			FCharacterDataAssetEditorToolkit::OpenEditor(Asset);
		}
	}
}

void FCharacterDataAssetActions::ExecuteImportFromJson(TArray<TWeakObjectPtr<UPaper2DPlusCharacterDataAsset>> Objects)
{
	if (Objects.Num() == 0) return;

	IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	if (!DesktopPlatform) return;

	TArray<FString> OutFiles;
	void* ParentWindowHandle = FSlateApplication::Get().GetActiveTopLevelWindow().IsValid()
		? FSlateApplication::Get().GetActiveTopLevelWindow()->GetNativeWindow()->GetOSWindowHandle()
		: nullptr;

	if (DesktopPlatform->OpenFileDialog(ParentWindowHandle, TEXT("Select JSON File"), FPaths::ProjectContentDir(), TEXT(""), TEXT("JSON Files (*.json)|*.json"), EFileDialogFlags::None, OutFiles) && OutFiles.Num() > 0)
	{
		for (const auto& AssetPtr : Objects)
		{
			if (UPaper2DPlusCharacterDataAsset* Asset = AssetPtr.Get())
			{
				FString ErrorMessage;
				if (FCharacterDataJsonImporter::ImportToExistingAsset(OutFiles[0], Asset, ErrorMessage))
				{
					Asset->MarkPackageDirty();
				}
				else
				{
					FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(FString::Printf(TEXT("Failed to import: %s"), *ErrorMessage)));
				}
				break;
			}
		}
	}
}

void FCharacterDataAssetActions::ExecuteReimport(TArray<TWeakObjectPtr<UPaper2DPlusCharacterDataAsset>> Objects)
{
	for (const auto& AssetPtr : Objects)
	{
		if (UPaper2DPlusCharacterDataAsset* Asset = AssetPtr.Get())
		{
			if (!Asset->SourceFilePath.IsEmpty() && FPaths::FileExists(Asset->SourceFilePath))
			{
				FString ErrorMessage;
				if (FCharacterDataJsonImporter::ReimportAsset(Asset, ErrorMessage))
				{
					Asset->MarkPackageDirty();
				}
				else
				{
					FMessageDialog::Open(EAppMsgType::Ok, FText::FromString(FString::Printf(TEXT("Failed to reimport: %s"), *ErrorMessage)));
				}
			}
		}
	}
}

void FCharacterDataAssetActions::ExecuteShowInExplorer(TArray<TWeakObjectPtr<UPaper2DPlusCharacterDataAsset>> Objects)
{
	for (const auto& AssetPtr : Objects)
	{
		if (UPaper2DPlusCharacterDataAsset* Asset = AssetPtr.Get())
		{
			if (!Asset->SourceFilePath.IsEmpty() && FPaths::FileExists(Asset->SourceFilePath))
			{
				FPlatformProcess::ExploreFolder(*FPaths::GetPath(Asset->SourceFilePath));
				break;
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
