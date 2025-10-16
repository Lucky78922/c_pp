// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class c_pp : ModuleRules
{
	public c_pp(ReadOnlyTargetRules Target) : base(Target)
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
			"c_pp",
			"c_pp/Variant_Platforming",
			"c_pp/Variant_Platforming/Animation",
			"c_pp/Variant_Combat",
			"c_pp/Variant_Combat/AI",
			"c_pp/Variant_Combat/Animation",
			"c_pp/Variant_Combat/Gameplay",
			"c_pp/Variant_Combat/Interfaces",
			"c_pp/Variant_Combat/UI",
			"c_pp/Variant_SideScrolling",
			"c_pp/Variant_SideScrolling/AI",
			"c_pp/Variant_SideScrolling/Gameplay",
			"c_pp/Variant_SideScrolling/Interfaces",
			"c_pp/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
