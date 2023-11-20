// Fill out your copyright notice in the Description page of Project Settings.

using System.Collections.Generic;
using UnrealBuildTool;

public class TMS_Platformer : ModuleRules
{
	public TMS_Platformer(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "AIModule","GameplayTasks","NavigationSystem"  });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.AddRange(new string[]
			{
				"TMS_Platformer/Platforms",
				"TMS_Platformer/Components",
				"TMS_Platformer/Character",
				"TMS_Platformer/AI",
				"TMS_Platformer/AI/Services"
			}
		);

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
