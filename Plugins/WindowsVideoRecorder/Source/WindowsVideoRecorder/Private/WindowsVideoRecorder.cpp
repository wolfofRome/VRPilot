// Copyright 2023,Obitodaitu. All Rights Reserved.

#include "WindowsVideoRecorder.h"

#define LOCTEXT_NAMESPACE "FWindowsVideoRecorderModule"

void FWindowsVideoRecorderModule::StartupModule()
{
	FModuleManager::Get().LoadModule(TEXT("WindowsFeatures"));
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FWindowsVideoRecorderModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FWindowsVideoRecorderModule, WindowsVideoRecorder)