#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"
#include "Paper2DPlusCharacterDataAsset.h"

/**
 * Asset type actions for Paper2DPlusCharacterDataAsset.
 */
class FCharacterDataAssetActions : public FAssetTypeActions_Base
{
public:
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "CharacterDataAsset", "Paper2D+ Character Data"); }
	virtual FColor GetTypeColor() const override { return FColor(100, 200, 255); }
	virtual UClass* GetSupportedClass() const override { return UPaper2DPlusCharacterDataAsset::StaticClass(); }
	virtual uint32 GetCategories() override { return EAssetTypeCategories::Misc; }
	virtual bool HasActions(const TArray<UObject*>& InObjects) const override { return true; }
	virtual void GetActions(const TArray<UObject*>& InObjects, struct FToolMenuSection& Section) override;
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;

private:
	void ExecuteImportFromJson(TArray<TWeakObjectPtr<UPaper2DPlusCharacterDataAsset>> Objects);
	void ExecuteReimport(TArray<TWeakObjectPtr<UPaper2DPlusCharacterDataAsset>> Objects);
	void ExecuteShowInExplorer(TArray<TWeakObjectPtr<UPaper2DPlusCharacterDataAsset>> Objects);
};
