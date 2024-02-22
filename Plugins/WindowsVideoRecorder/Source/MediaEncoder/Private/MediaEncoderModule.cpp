// Copyright 2023,Obitodaitu. All Rights Reserved.

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "MediaEncoderCommon.h"
#include "../Public/MediaEncoder.h"

class FMediaEncoderModule : public IModuleInterface
{
public:
	FMediaEncoderModule()
	{
	}

	~FMediaEncoderModule()
	{
	}

	void StartupModule() override
	{
		FModuleManager::Get().LoadModule(TEXT("AVEncoder"));
	}

	void ShutdownModule() override
	{
		// If the FGameplayMediaEncoder instance was created, then explicitly destroy it here
		// instead of waiting for the automatic cleanup, since at that point some objects
		// it depends to for a clean shutdown are not available any longer.
		if (FMediaEncoder::Singleton)
		{
			delete FMediaEncoder::Singleton;
			FMediaEncoder::Singleton = nullptr;
		}
	}
private:
};

IMPLEMENT_MODULE(FMediaEncoderModule, MediaEncoder);

