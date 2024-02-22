// Copyright 2023,Obitodaitu. All Rights Reserved.

#include "WindowsFeatures.h"
#include "WmfPrivate.h"
#include "WinVideoRecordingSystem.h"
#include "Misc/CommandLine.h"

IMPLEMENT_MODULE(FWindowsFeaturesModule, WindowsFeatures);

WINDOWSFEATURES_START

FWindowsFeaturesModule::FWindowsFeaturesModule()
{
}

IRecordingSystem* FWindowsFeaturesModule::GetRecordingSystem()
{
	static FWinVideoRecordingSystem VideoRecordingSystem;
	return &VideoRecordingSystem;
}

void FWindowsFeaturesModule::StartupModule()
{
	FModuleManager::Get().LoadModule(TEXT("MediaEncoder"));
}

WINDOWSFEATURES_END
