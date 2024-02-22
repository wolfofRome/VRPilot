// Copyright 2023,Obitodaitu. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

class IRecordingSystem;

/**
 * Interface for platform feature modules
 */

/** Defines the interface of a module implementing platform feature collector class. */
class WINDOWSVIDEORECORDER_API IPlatformGetFeaturesModule : public IModuleInterface
{
public:

	static IPlatformGetFeaturesModule& Get()
	{
		static IPlatformGetFeaturesModule* StaticModule = NULL;
		// first time initialization
		if (!StaticModule)
		{

			bool bModuleExists = FModuleManager::Get().ModuleExists(TEXT("WindowsFeatures"));
			// If running a dedicated server then we use the default PlatformFeatures
			if (bModuleExists && !IsRunningDedicatedServer())
			{
				UE_LOG(LogWindows, Log, TEXT("WindowsFeatures enabled"));
				
				StaticModule = &FModuleManager::LoadModuleChecked<IPlatformGetFeaturesModule>(TEXT("WindowsFeatures"));
			}
			else
			{
				UE_LOG(LogWindows, Log, TEXT("WindowsPlatformFeatures disabled or dedicated server build"));
				// if the platform doesn't care about a platform features module, then use this generic almost empty implementation
				StaticModule = new IPlatformGetFeaturesModule;
			}

		}

		return *StaticModule;
	}

	//virtual class ISaveGameSystem* GetSaveGameSystem();

	//virtual class IDVRStreamingSystem* GetStreamingSystem();

	//virtual FString GetUniqueAppId();

	virtual IRecordingSystem* GetRecordingSystem();

	//virtual void SetScreenshotEnableState(bool bEnabled);
};
