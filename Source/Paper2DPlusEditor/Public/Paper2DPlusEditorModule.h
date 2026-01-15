#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "AssetTypeCategories.h"

class FPaper2DPlusEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/** Get the custom asset category for Paper2D+ assets */
	static EAssetTypeCategories::Type GetAssetCategory() { return Paper2DPlusAssetCategory; }

private:
	void RegisterAssetTools();
	void UnregisterAssetTools();
	void RegisterMenuExtensions();

	TArray<TSharedPtr<class IAssetTypeActions>> RegisteredAssetTypeActions;

	/** Custom asset category for Paper2D+ assets */
	static EAssetTypeCategories::Type Paper2DPlusAssetCategory;
};
