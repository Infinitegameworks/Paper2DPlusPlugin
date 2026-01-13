using UnrealBuildTool;

public class Paper2DPlus : ModuleRules
{
	public Paper2DPlus(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"Json",
			"JsonUtilities",
			"Paper2D"
		});
	}
}
