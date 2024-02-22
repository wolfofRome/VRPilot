/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#include "TransferModule.h"
#include "TransferGlobals.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#if WITH_EDITOR
#include "Misc/Paths.h"
#include "Misc/MessageDialog.h"
#include "HAL/PlatformProcess.h"
#endif

#define LOCTEXT_NAMESPACE "FTransferModule"

#if WITH_EDITOR
void* FTransferModule::TransferLibraryHandle = nullptr;
#endif

void FTransferModule::StartupModule()
{
    LOG_TRANSFER_NORMAL("Starting TransferClient Module...");
#if WITH_EDITOR
#if PLATFORM_WINDOWS && PLATFORM_64BITS
    {
        const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
        LOG_TRANSFER_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

        const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("TransferClientLibrary"), TEXT("Win64"),  TEXT("Editor"));
        LOG_TRANSFER_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

        static const FString TransferDLLName = "aws-cpp-sdk-transfer";
        const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, TransferDLLName, TransferLibraryHandle);
        if (!bDependencyLoaded)
        {
            FFormatNamedArguments Arguments;
            Arguments.Add(TEXT("Name"), FText::FromString(TransferDLLName));
            FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
            FreeDependency(TransferLibraryHandle);
        }
    };
#elif PLATFORM_MAC
    {
        const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
        LOG_TRANSFER_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));
    
        const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("TransferClientLibrary"), TEXT("Mac"),  TEXT("Editor"));
        LOG_TRANSFER_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));
    
        static const FString TransferDLLName = "libaws-cpp-sdk-transfer";
        const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, TransferDLLName, TransferLibraryHandle);
        if (!bDependencyLoaded)
        {
            FFormatNamedArguments Arguments;
            Arguments.Add(TEXT("Name"), FText::FromString(TransferDLLName));
            FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
            FreeDependency(TransferLibraryHandle);
        }
    };
#elif PLATFORM_IOS
#endif
#endif
}

void FTransferModule::ShutdownModule()
{
#if WITH_EDITOR
	FreeDependency(TransferLibraryHandle);
#endif
	LOG_TRANSFER_NORMAL("Shutting down Transfer Module...");
}

#if WITH_EDITOR
bool FTransferModule::LoadDependency(const FString& Dir, const FString& Name, void*& Handle)
{
	FString Lib = Name + TEXT(".") + FPlatformProcess::GetModuleExtension();
	FString Path = Dir.IsEmpty() ? *Lib : FPaths::Combine(*Dir, *Lib);

	Handle = FPlatformProcess::GetDllHandle(*Path);

	if (Handle == nullptr)
	{
		LOG_TRANSFER_ERROR(FString::Printf(TEXT("Dependency %s failed to load in directory %s"), *Lib, *Dir));
		return false;
	}

	LOG_TRANSFER_NORMAL(FString::Printf(TEXT("Dependency %s successfully loaded from directory %s"), *Lib, *Dir));
	return true;
}

void FTransferModule::FreeDependency(void*& Handle)
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

IMPLEMENT_MODULE(FTransferModule, Transfer)
