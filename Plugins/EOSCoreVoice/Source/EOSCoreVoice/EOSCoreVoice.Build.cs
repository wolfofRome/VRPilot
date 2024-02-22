/**
* Copyright (C) 2017-2021 | eelDev
*/

using UnrealBuildTool;

public class EOSCoreVoice : ModuleRules
{
	public EOSCoreVoice(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"EOSVoiceChat",
				"VoiceChat",
				"Json",
				"HTTP",
				"Projects"
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore", 
			}
			);
	}
}
