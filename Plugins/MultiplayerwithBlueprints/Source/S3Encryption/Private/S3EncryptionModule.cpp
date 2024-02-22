/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#include "S3EncryptionModule.h"
#include "S3EncryptionGlobals.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#if WITH_EDITOR
#include "Misc/Paths.h"
#include "Misc/MessageDialog.h"
#include "HAL/PlatformProcess.h"
#endif

#define LOCTEXT_NAMESPACE "FS3EncryptionModule"

#if WITH_EDITOR
#ifndef WITH_KMSCLIENTSDK
void* FS3EncryptionModule::KMSLibraryHandle = nullptr;
#endif
void* FS3EncryptionModule::S3EncryptionLibraryHandle = nullptr;
#endif

void FS3EncryptionModule::StartupModule()
{
    LOG_S3ENCRYPTION_NORMAL("Starting S3EncryptionClient Module...");
#if WITH_EDITOR
#ifndef WITH_KMSCLIENTSDK
#if PLATFORM_WINDOWS && PLATFORM_64BITS
    {
        const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
        LOG_S3ENCRYPTION_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

        const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("KMSClientLibrary"), TEXT("Win64"),  TEXT("Editor"));
        LOG_S3ENCRYPTION_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

        static const FString KMSDLLName = "aws-cpp-sdk-kms";
        const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, KMSDLLName, KMSLibraryHandle);
        if (!bDependencyLoaded)
        {
            FFormatNamedArguments Arguments;
            Arguments.Add(TEXT("Name"), FText::FromString(KMSDLLName));
            FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
            FreeDependency(KMSLibraryHandle);
        }
	};
#elif PLATFORM_MAC
    {
        const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
        LOG_S3ENCRYPTION_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));
    
        const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("KMSClientLibrary"), TEXT("Mac"),  TEXT("Editor"));
        LOG_S3ENCRYPTION_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));
    
        static const FString KMSDLLName = "libaws-cpp-sdk-kms";
        const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, KMSDLLName, KMSLibraryHandle);
        if (!bDependencyLoaded)
        {
            FFormatNamedArguments Arguments;
            Arguments.Add(TEXT("Name"), FText::FromString(KMSDLLName));
            FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
            FreeDependency(KMSLibraryHandle);
        }
    };
#elif PLATFORM_IOS
#endif
#endif
#if PLATFORM_WINDOWS && PLATFORM_64BITS

    {
        const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
        LOG_S3ENCRYPTION_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

        const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("S3EncryptionClientLibrary"), TEXT("Win64"),  TEXT("Editor"));
        LOG_S3ENCRYPTION_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

        static const FString S3EncryptionDLLName = "aws-cpp-sdk-s3-encryption";
        const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, S3EncryptionDLLName, S3EncryptionLibraryHandle);
        if (!bDependencyLoaded)
        {
            FFormatNamedArguments Arguments;
            Arguments.Add(TEXT("Name"), FText::FromString(S3EncryptionDLLName));
            FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
            FreeDependency(S3EncryptionLibraryHandle);
        }
    };
#elif PLATFORM_MAC
    {
        const FString BaseDir = IPluginManager::Get().FindPlugin("awsSDK")->GetBaseDir();
        LOG_S3ENCRYPTION_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));
    
        const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("Source"), TEXT("ThirdParty"), TEXT("S3EncryptionClientLibrary"), TEXT("Mac"),  TEXT("Editor"));
        LOG_S3ENCRYPTION_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));
    
        static const FString S3EncryptionDLLName = "libaws-cpp-sdk-s3-encryption";
        const bool bDependencyLoaded = LoadDependency(ThirdPartyDir, S3EncryptionDLLName, S3EncryptionLibraryHandle);
        if (!bDependencyLoaded)
        {
            FFormatNamedArguments Arguments;
            Arguments.Add(TEXT("Name"), FText::FromString(S3EncryptionDLLName));
            FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}."), Arguments));
            FreeDependency(S3EncryptionLibraryHandle);
        }
    };
#elif PLATFORM_IOS
#endif
#endif
}

void FS3EncryptionModule::ShutdownModule()
{
#if WITH_EDITOR
	FreeDependency(S3EncryptionLibraryHandle);
#ifndef WITH_KMSCLIENTSDK
    FreeDependency(KMSLibraryHandle);
#endif
#endif
	LOG_S3ENCRYPTION_NORMAL("Shutting down S3Encryption Module...");
}

#if WITH_EDITOR
bool FS3EncryptionModule::LoadDependency(const FString& Dir, const FString& Name, void*& Handle)
{
	FString Lib = Name + TEXT(".") + FPlatformProcess::GetModuleExtension();
	FString Path = Dir.IsEmpty() ? *Lib : FPaths::Combine(*Dir, *Lib);

	Handle = FPlatformProcess::GetDllHandle(*Path);

	if (Handle == nullptr)
	{
		LOG_S3ENCRYPTION_ERROR(FString::Printf(TEXT("Dependency %s failed to load in directory %s"), *Lib, *Dir));
		return false;
	}

	LOG_S3ENCRYPTION_NORMAL(FString::Printf(TEXT("Dependency %s successfully loaded from directory %s"), *Lib, *Dir));
	return true;
}

void FS3EncryptionModule::FreeDependency(void*& Handle)
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

IMPLEMENT_MODULE(FS3EncryptionModule, S3Encryption)
