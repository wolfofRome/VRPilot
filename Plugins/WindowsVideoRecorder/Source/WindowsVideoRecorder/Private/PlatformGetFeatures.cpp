// Copyright 2023,Obitodaitu. All Rights Reserved.

#include "PlatformGetFeatures.h"
//#include "SaveGameSystem.h"
//#include "DVRStreaming.h"
#include "RecordingSystem.h"

#if PLATFORM_ANDROID
extern bool AndroidThunkCpp_IsScreenCaptureDisabled();
extern void AndroidThunkCpp_DisableScreenCapture(bool bDisable);
#endif

//ISaveGameSystem* IPlatformGetFeaturesModule::GetSaveGameSystem()
//{
//	static FGenericSaveGameSystem GenericSaveGame;
//	return &GenericSaveGame;
//}


//IDVRStreamingSystem* IPlatformGetFeaturesModule::GetStreamingSystem()
//{
//	static FGenericDVRStreamingSystem GenericStreamingSystem;
//	return &GenericStreamingSystem;
//}

//FString IPlatformGetFeaturesModule::GetUniqueAppId()
//{
//	return FString();
//}

IRecordingSystem* IPlatformGetFeaturesModule::GetRecordingSystem()
{
	static FGenericRecordingSystem GenericRecordingSystem;
	return &GenericRecordingSystem;
}

//void IPlatformGetFeaturesModule::SetScreenshotEnableState(bool bEnabled)
//{
//#if PLATFORM_ANDROID
//	if (AndroidThunkCpp_IsScreenCaptureDisabled() != !bEnabled)
//	{
//		AndroidThunkCpp_DisableScreenCapture(!bEnabled);
//	}
//#endif
//}