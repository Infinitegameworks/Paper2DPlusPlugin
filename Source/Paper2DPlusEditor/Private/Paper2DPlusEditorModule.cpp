#include "Paper2DPlusEditorModule.h"
#include "AssetToolsModule.h"
#include "IAssetTools.h"
#include "CharacterDataAssetActions.h"
#include "ContentBrowserModule.h"
#include "ToolMenus.h"
#include "Paper2DPlusCharacterDataAsset.h"
#include "CharacterDataJsonImporter.h"
#include "SpriteExtractorWindow.h"

#define LOCTEXT_NAMESPACE "FPaper2DPlusEditorModule"

void FPaper2DPlusEditorModule::StartupModule()
{
	RegisterAssetTools();
	RegisterMenuExtensions();
	FSpriteExtractorActions::RegisterMenus();
}

void FPaper2DPlusEditorModule::ShutdownModule()
{
	UnregisterAssetTools();
	FSpriteExtractorActions::UnregisterMenus();
}

void FPaper2DPlusEditorModule::RegisterAssetTools()
{
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

	// Register asset type actions for Paper2DPlusCharacterDataAsset
	TSharedPtr<IAssetTypeActions> CharacterDataActions = MakeShareable(new FCharacterDataAssetActions());
	AssetTools.RegisterAssetTypeActions(CharacterDataActions.ToSharedRef());
	RegisteredAssetTypeActions.Add(CharacterDataActions);
}

void FPaper2DPlusEditorModule::UnregisterAssetTools()
{
	FAssetToolsModule* AssetToolsModule = FModuleManager::GetModulePtr<FAssetToolsModule>("AssetTools");
	if (AssetToolsModule)
	{
		IAssetTools& AssetTools = AssetToolsModule->Get();
		for (TSharedPtr<IAssetTypeActions>& Actions : RegisteredAssetTypeActions)
		{
			AssetTools.UnregisterAssetTypeActions(Actions.ToSharedRef());
		}
	}
	RegisteredAssetTypeActions.Empty();
}

void FPaper2DPlusEditorModule::RegisterMenuExtensions()
{
	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateLambda([]()
	{
		// Add "Import Character Data" to Content Browser context menu
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("ContentBrowser.AddNewContextMenu");
		if (Menu)
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("ContentBrowserImportBasic");
			Section.AddMenuEntry(
				"ImportCharacterData",
				LOCTEXT("ImportCharacterData", "Import Paper2D+ Character Data"),
				LOCTEXT("ImportCharacterDataTooltip", "Import character data from a JSON file"),
				FSlateIcon(FAppStyle::GetAppStyleSetName(), "ClassIcon.DataAsset"),
				FUIAction(FExecuteAction::CreateStatic(&FCharacterDataJsonImporter::ShowImportDialog))
			);
		}
	}));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPaper2DPlusEditorModule, Paper2DPlusEditor)
