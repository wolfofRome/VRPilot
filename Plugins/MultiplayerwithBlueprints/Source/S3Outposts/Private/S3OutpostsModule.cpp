/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#include "S3OutpostsModule.h"
#include "S3OutpostsGlobals.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#if WITH_EDITOR
#include "Misc/Paths.h"
#include "Misc/MessageDialog.h"
#include "HAL/PlatformProcess.h"
#endif

#define LOCTEXT_NAMESPACE "FS3OutpostsModule"

#if WITH_EDITOR
void* FS3OutpostsModule::S3OutpostsLibraryHandle = nullptr;
#endif

void FS3OutpostsModule::StartupModule()
{
    LOG_S3OUTPOSTS_NORMAL("Starting S3OutpostsClient Module...");
#if WITH_EDITOR
#if PLATFORM_WINDOWS && PLATFORM_64BITS
	const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
	LOG_S3OUTPOSTS_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

	const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("S3OutpostsClientLibrary"), TEXT("Win64"),  TEXT("Editor"));
	LOG_S3OUTPOSTS_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

	static const FString S3OutpostsDLLName = "aws-cpp-sdk-s3outposts";
	const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, S3OutpostsDLLName, S3OutpostsLibraryHandle);
	if (!bDependencyLoaded)
	{
		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("Name"), FText::FromString(S3OutpostsDLLName));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
		FreeDependency(S3OutpostsLibraryHandle);
	}
#elif PLATFORM_MAC
    const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
    LOG_S3OUTPOSTS_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

    const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("S3OutpostsClientLibrary"), TEXT("Mac"),  TEXT("Editor"));
    LOG_S3OUTPOSTS_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

    static const FString S3OutpostsDLLName = "libaws-cpp-sdk-s3outposts";
    const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, S3OutpostsDLLName, S3OutpostsLibraryHandle);
    if (!bDependencyLoaded)
    {
        FFormatNamedArguments Arguments;
        Arguments.Add(TEXT("Name"), FText::FromString(S3OutpostsDLLName));
        FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
        FreeDependency(S3OutpostsLibraryHandle);
    }
#elif PLATFORM_IOS
#endif
#endif
}

void FS3OutpostsModule::ShutdownModule()
{
#if WITH_EDITOR
	FreeDependency(S3OutpostsLibraryHandle);
#endif
	LOG_S3OUTPOSTS_NORMAL("Shutting down S3Outposts Module...");
}

#if WITH_EDITOR
bool FS3OutpostsModule::LoadDependency(const FString& Dir, const FString& Name, void*& Handle)
{
	FString Lib = Name + TEXT(".") + FPlatformProcess::GetModuleExtension();
	FString Path = Dir.IsEmpty() ? *Lib : FPaths::Combine(*Dir, *Lib);

	Handle = FPlatformProcess::GetDllHandle(*Path);

	if (Handle == nullptr)
	{
		LOG_S3OUTPOSTS_ERROR(FString::Printf(TEXT("Dependency %s failed to load in directory %s"), *Lib, *Dir));
		return false;
	}

	LOG_S3OUTPOSTS_NORMAL(FString::Printf(TEXT("Dependency %s successfully loaded from directory %s"), *Lib, *Dir));
	return true;
}

void FS3OutpostsModule::FreeDependency(void*& Handle)
{
#if !PLATFORM_LINUX && !PLATFORM_ANDROID && !PLATFORM_IOS
	if (Handle != nullptr)
	{
		FPlatformProcess::FreeDllHandle(Handle);
		Handle = nullptr;
	}
#endif
}
#endif

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FS3OutpostsModule, S3Outposts)
