// Copyright 2023,Obitodaitu. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "../../WindowsVideoRecorder/Public/PlatformGetFeatures.h"
#include "WindowsFeaturesCommon.h"

class FWindowsFeaturesModule : public IPlatformGetFeaturesModule
{
public:

	/** Creates a new instance of the audio device implemented by the module. */
	FWindowsFeaturesModule();

	virtual IRecordingSystem* GetRecordingSystem() override;

private:
	void StartupModule() override;

};


