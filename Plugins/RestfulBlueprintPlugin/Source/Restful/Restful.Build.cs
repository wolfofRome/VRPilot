/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, October 2022
 */

using UnrealBuildTool;
using System.IO;

public class Restful : ModuleRules
{
    public Restful(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivatePCHHeaderFile = "Private/RestfulPrivatePCH.h";

        PublicIncludePaths.Add(
            Path.Combine(ModuleDirectory, "Public")
            );

        PrivateIncludePaths.Add(
            Path.Combine(ModuleDirectory, "Private")
            );

        AddEngineThirdPartyPrivateStaticDependencies(Target, "OpenSSL");

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
            "Core", "CoreUObject", "Projects", "Engine", "HTTP", "SSL"
            }
            );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
            }
            );


        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
            }
            );

        bEnableExceptions = true;
    }
}
