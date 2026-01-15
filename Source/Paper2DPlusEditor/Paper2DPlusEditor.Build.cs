using UnrealBuildTool;

public class Paper2DPlusEditor : ModuleRules
{
	public Paper2DPlusEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"UnrealEd",
			"Paper2DPlus",
			"Slate",
			"SlateCore",
			"Paper2D",
			"Json",
			"JsonUtilities",
			"AssetTools",
			"AssetRegistry",
			"ContentBrowser",
			"InputCore",
			"PropertyEditor",
			"EditorFramework",
			"ToolMenus",
			"DesktopPlatform"
		});
	}
}
