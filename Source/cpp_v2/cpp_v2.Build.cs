// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class cpp_v2 : ModuleRules
{
	public cpp_v2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"cpp_v2",
			"cpp_v2/Variant_Platforming",
			"cpp_v2/Variant_Platforming/Animation",
			"cpp_v2/Variant_Combat",
			"cpp_v2/Variant_Combat/AI",
			"cpp_v2/Variant_Combat/Animation",
			"cpp_v2/Variant_Combat/Gameplay",
			"cpp_v2/Variant_Combat/Interfaces",
			"cpp_v2/Variant_Combat/UI",
			"cpp_v2/Variant_SideScrolling",
			"cpp_v2/Variant_SideScrolling/AI",
			"cpp_v2/Variant_SideScrolling/Gameplay",
			"cpp_v2/Variant_SideScrolling/Interfaces",
			"cpp_v2/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
