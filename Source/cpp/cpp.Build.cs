// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class cpp : ModuleRules
{
	public cpp(ReadOnlyTargetRules Target) : base(Target)
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
			"cpp",
			"cpp/Variant_Platforming",
			"cpp/Variant_Platforming/Animation",
			"cpp/Variant_Combat",
			"cpp/Variant_Combat/AI",
			"cpp/Variant_Combat/Animation",
			"cpp/Variant_Combat/Gameplay",
			"cpp/Variant_Combat/Interfaces",
			"cpp/Variant_Combat/UI",
			"cpp/Variant_SideScrolling",
			"cpp/Variant_SideScrolling/AI",
			"cpp/Variant_SideScrolling/Gameplay",
			"cpp/Variant_SideScrolling/Interfaces",
			"cpp/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
