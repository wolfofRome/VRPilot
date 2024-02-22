// Copyright 2023,Obitodaitu. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RecordingSystem.h"
#include "PlatformGetFeatures.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "WindowsVideoRecorderSubsystem.generated.h"

UENUM(BlueprintType)
enum class EWindowsVideoRecorderResolution : uint8
{
	p720 UMETA(DisplayName = "1280x720"),
	p1080 UMETA(DisplayName = "1920x1080"),
	p1440 UMETA(DisplayName = "2560x1440"),
	p2160 UMETA(DisplayName = "3840x2160"),
	v720 UMETA(DisplayName = "720x1280"),
	v1080 UMETA(DisplayName = "1080x1920"),
	v1440 UMETA(DisplayName = "1440x2560"),
	v2160 UMETA(DisplayName = "2160x3840")
};

USTRUCT(BlueprintType)
struct FWindowsVideoRecorderConfig
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WindowsVideoRecorder")
		EWindowsVideoRecorderResolution VideoResolution = EWindowsVideoRecorderResolution::p1080;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WindowsVideoRecorder", meta = (ClampMin = 10, ClampMax = 60))
		int FPS = 60;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WindowsVideoRecorder", meta = (ClampMin = 1000000, ClampMax = 20000000))
		int Bitrate = 20000000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WindowsVideoRecorder")
		bool IsAudio = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WindowsVideoRecorder")
		bool IsShowUI = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WindowsVideoRecorder")
		FString FileName = "Video";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WindowsVideoRecorder")
		FString FilePath = "";
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVideoFinished, bool, bSuccessed, FString, FilePath);

UCLASS(Blueprintable, BlueprintType)
class WINDOWSVIDEORECORDER_API UWindowsVideoRecorderSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:	
	virtual bool ShouldCreateSubsystem(UObject* Outer) const;

	/** Implement this for initialization of instances of the system */
	virtual void Initialize(FSubsystemCollectionBase& Collection);

	/** Implement this for deinitialization of instances of the system */
	virtual void Deinitialize();

public:
	UFUNCTION(BlueprintCallable, Category = "WindowsVideoRecorder")
		void StartRecording(FWindowsVideoRecorderConfig VideoRecorderConfig);

	UFUNCTION(BlueprintCallable, Category = "WindowsVideoRecorder")
		void PauseRecording();

	UFUNCTION(BlueprintCallable, Category = "WindowsVideoRecorder")
		void ResumeRecording();

	UFUNCTION(BlueprintCallable, Category = "WindowsVideoRecorder")
		void FinalizeRecording();

	UFUNCTION(BlueprintPure, Category = "WindowsVideoRecorder")
		FTimespan GetRecordingTime();

	UFUNCTION()
		void VideoFinished(bool bSuccessed, const FString& FilePath);

	
	IRecordingSystem* VideoRecordSystem;

	UPROPERTY(BlueprintAssignable, Category = "WindowsVideoRecorder")
	FOnVideoFinished OnVideoFinished;

	UFUNCTION()
	void PostEngineInit();
};
