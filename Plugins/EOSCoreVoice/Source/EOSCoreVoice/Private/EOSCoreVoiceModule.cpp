/**
* Copyright (C) 2017-2021 | eelDev
*/

#include "EOSCoreVoiceModule.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FEOSCoreVoiceModule"

DEFINE_LOG_CATEGORY(LogEOSCoreVoice);

void FEOSCoreVoiceModule::StartupModule()
{
	const TSharedPtr<IPlugin> PluginPtr = IPluginManager::Get().FindPlugin("EOSCoreVoice");

	if (PluginPtr)
	{
		const FString PluginVersion = PluginPtr->GetDescriptor().VersionName;

		UE_LOG(LogTemp, Log, TEXT("--------------------------------------------------------------------------------"));
		UE_LOG(LogTemp, Log, TEXT("Using EOSCoreVoice Version: %s"), *PluginVersion);
		UE_LOG(LogTemp, Log, TEXT("--------------------------------------------------------------------------------"));
	}
}

void FEOSCoreVoiceModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEOSCoreVoiceModule, EOSCoreVoice)