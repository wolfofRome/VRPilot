// Copyright 2023,Obitodaitu. All Rights Reserved.


#include "WindowsVideoRecorderSubsystem.h"
#include "Misc/CoreDelegates.h"

static IPlatformGetFeaturesModule* StaticModule = NULL;
// Sets default values

bool UWindowsVideoRecorderSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	Super::ShouldCreateSubsystem(Outer);
	
	return true;
}

void UWindowsVideoRecorderSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	
	Super::Initialize(Collection);

	if(!GIsEditor)
	{
		// -1: remain on
		GIsDumpingMovie = -1;
		FCoreDelegates::OnPostEngineInit.AddUObject(this, &UWindowsVideoRecorderSubsystem::PostEngineInit);
	}
	
	bool bModuleExists = FModuleManager::Get().ModuleExists(TEXT("WindowsFeatures"));
	// If running a dedicated server then we use the default PlatformFeatures
	if (bModuleExists && !IsRunningDedicatedServer())
	{
		UE_LOG(LogWindows, Log, TEXT("WindowsFeatures enabled"));


		// first time initialization
		if (!StaticModule)
		{
			const TCHAR* PlatformModuleName = TEXT("WindowsFeatures");
			if (PlatformModuleName)
			{
				StaticModule = &FModuleManager::LoadModuleChecked<IPlatformGetFeaturesModule>(PlatformModuleName);
			}
		}
		if (StaticModule)
		{
			VideoRecordSystem = (*StaticModule).GetRecordingSystem();
		}
	}
	else
	{
		UE_LOG(LogWindows, Log, TEXT("WindowsFeatures disabled or dedicated server build"));

	}

	if (VideoRecordSystem)
	{
		VideoRecordSystem->GetOnVideoRecordingFinalizedDelegate().AddUObject(this, &UWindowsVideoRecorderSubsystem::VideoFinished);
	}
}

void UWindowsVideoRecorderSubsystem::Deinitialize()
{
	Super::Deinitialize();
	
	VideoRecordSystem->EnableRecording(false);
	OnVideoFinished.RemoveAll(this);
	VideoRecordSystem = nullptr;
	FCoreDelegates::OnPostEngineInit.RemoveAll(this);
}

void UWindowsVideoRecorderSubsystem::StartRecording(FWindowsVideoRecorderConfig VideoRecorderConfig)
{
	if (!VideoRecordSystem)
	{
		return;
	}
	//Initial
	VideoRecordSystem->EnableRecording(true);
	FRecordingParameters param;
	param.RecordingLengthSeconds = 90000;

	FVideoRecordingConfig Config;
	switch (VideoRecorderConfig.VideoResolution)
	{
	case EWindowsVideoRecorderResolution::p720:
	{
		Config.Height = 720;
		Config.Width = 1280;
		break;
	}
	case EWindowsVideoRecorderResolution::p1080:
	{
		Config.Height = 1080;
		Config.Width = 1920;
		break;
	}
	case EWindowsVideoRecorderResolution::p1440:
	{
		Config.Height = 1440;
		Config.Width = 2560;
		break;
	}
	case EWindowsVideoRecorderResolution::p2160:
	{
		Config.Height = 2160;
		Config.Width = 3840;
		break;
	}
	case EWindowsVideoRecorderResolution::v720:
	{
		Config.Height = 1280;
		Config.Width = 720;
		break;
	}
	case EWindowsVideoRecorderResolution::v1080:
	{
		Config.Height = 1920;
		Config.Width = 1080;
		break;
	}
	case EWindowsVideoRecorderResolution::v1440:
	{
		Config.Height = 2560;
		Config.Width = 1440;
		break;
	}
	case EWindowsVideoRecorderResolution::v2160:
	{
		Config.Height = 3840;
		Config.Width = 2160;
		break;
	}
	default:
		break;
	}
	
	Config.Framerate = VideoRecorderConfig.FPS;
	Config.Bitrate = VideoRecorderConfig.Bitrate;
	Config.IsAudio = VideoRecorderConfig.IsAudio;
	Config.IsShowUI = VideoRecorderConfig.IsShowUI;
	Config.FilePath = VideoRecorderConfig.FilePath;
	
	//Start recording
	VideoRecordSystem->NewRecording(*(VideoRecorderConfig.FileName), param, Config);
	VideoRecordSystem->StartRecording();

	
}

void UWindowsVideoRecorderSubsystem::PauseRecording()
{
	if (!VideoRecordSystem)
	{
		return;
	}
	VideoRecordSystem->PauseRecording();
}

void UWindowsVideoRecorderSubsystem::ResumeRecording()
{

	if (!VideoRecordSystem)
	{
		return;
	}
	VideoRecordSystem->StartRecording();
}

void UWindowsVideoRecorderSubsystem::FinalizeRecording()
{
	if (!VideoRecordSystem)
	{
		return;
	}
	//Finish Recording
	FText Title;
	FText Comment;
	VideoRecordSystem->FinalizeRecording(true, Title, Comment);
}

FTimespan UWindowsVideoRecorderSubsystem::GetRecordingTime()
{
	if (!VideoRecordSystem)
	{
		return FTimespan();
	}
	float RecordingSeconds = VideoRecordSystem->GetCurrentRecordingSeconds();
	FTimespan Timespan = FTimespan::FromSeconds(RecordingSeconds);
	return Timespan;
}

void UWindowsVideoRecorderSubsystem::VideoFinished(bool bSuccessed, const FString& FilePath)
{
	if (OnVideoFinished.IsBound())
	{
		OnVideoFinished.Broadcast(bSuccessed, FilePath);
	}	
}

void UWindowsVideoRecorderSubsystem::PostEngineInit()
{
	// -1: remain on
	GIsDumpingMovie = 0;
	
}





