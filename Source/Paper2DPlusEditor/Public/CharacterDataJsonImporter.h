#pragma once

#include "CoreMinimal.h"
#include "Paper2DPlusCharacterDataAsset.h"

/**
 * Handles importing character data from JSON files into UPaper2DPlusCharacterDataAsset.
 */
class PAPER2DPLUSEDITOR_API FCharacterDataJsonImporter
{
public:
	/**
	 * Show the import dialog and create a new Paper2DPlusCharacterDataAsset
	 */
	static void ShowImportDialog();

	/**
	 * Import a JSON file and create a new asset
	 * @param JsonFilePath Path to the JSON file
	 * @param DestinationPath Content Browser path for the new asset
	 * @param AssetName Name for the new asset
	 * @param OutErrorMessage Error message if import fails
	 * @return The created asset, or nullptr if failed
	 */
	static UPaper2DPlusCharacterDataAsset* ImportFromFile(
		const FString& JsonFilePath,
		const FString& DestinationPath,
		const FString& AssetName,
		FString& OutErrorMessage
	);

	/**
	 * Import JSON file into an existing asset
	 * @param JsonFilePath Path to the JSON file
	 * @param Asset The asset to import into
	 * @param OutErrorMessage Error message if import fails
	 * @return True if successful
	 */
	static bool ImportToExistingAsset(
		const FString& JsonFilePath,
		UPaper2DPlusCharacterDataAsset* Asset,
		FString& OutErrorMessage
	);

	/**
	 * Reimport an existing asset from its source file
	 * @param Asset The asset to reimport
	 * @param OutErrorMessage Error message if reimport fails
	 * @return True if successful
	 */
	static bool ReimportAsset(UPaper2DPlusCharacterDataAsset* Asset, FString& OutErrorMessage);

	/**
	 * Parse JSON string into character data
	 * @param JsonString The JSON content
	 * @param OutAnimations Parsed animation data
	 * @param OutErrorMessage Error message if parsing fails
	 * @return True if successful
	 */
	static bool ParseJsonToCharacterData(
		const FString& JsonString,
		TArray<FAnimationHitboxData>& OutAnimations,
		FString& OutErrorMessage
	);

private:
	static EHitboxType ParseHitboxType(const FString& TypeString);
	static FHitboxData ParseHitboxFromJson(const TSharedPtr<class FJsonObject>& JsonObject);
	static FSocketData ParseSocketFromJson(const TSharedPtr<class FJsonObject>& JsonObject);
	static FFrameHitboxData ParseFrameFromJson(const FString& FrameName, const TSharedPtr<class FJsonObject>& JsonObject);

	/** Find a PaperFlipbook asset by name for auto-linking */
	static TSoftObjectPtr<UPaperFlipbook> FindFlipbookByName(const FString& FlipbookName);
};
