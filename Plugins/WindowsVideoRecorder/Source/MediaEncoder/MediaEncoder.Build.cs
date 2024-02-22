// Copyright 2023,Obitodaitu. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

[SupportedPlatforms("Win64")]
public class MediaEncoder : ModuleRules
{
	public MediaEncoder(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        // NOTE: General rule is not to access the private folder of another module,
        // but to use the ISubmixBufferListener interface, we  need to include some private headers
        PrivateIncludePaths.Add(System.IO.Path.Combine(Directory.GetCurrentDirectory(), "./Runtime/AudioMixer/Private"));

		PrivateDependencyModuleNames.AddRange(new string[]
		{
            "Core",
            "Engine",
			"CoreUObject",
            "ApplicationCore",
            "RenderCore",
			"RHI",
			"SlateCore",
			"Slate",
			"HTTP",
			"Json",
			"AVEncoder",

        });

		if (Target.Platform == UnrealTargetPlatform.Win64)
		{
			PrivateDependencyModuleNames.Add("D3D11RHI");
			AddEngineThirdPartyPrivateStaticDependencies(Target, "DX11");

			PublicDelayLoadDLLs.Add("mfplat.dll");
			PublicDelayLoadDLLs.Add("mfuuid.dll");
			PublicDelayLoadDLLs.Add("Mfreadwrite.dll");
		}
	}
}

