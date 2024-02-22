// Copyright 2023,Obitodaitu. All Rights Reserved.

#pragma once

#include "../../WindowsVideoRecorder/Public/RecordingSystem.h"

#include "RHI.h"
#include "RHIResources.h"

#include "HAL/ThreadSafeBool.h"
#include "CoreMinimal.h"
#include "AudioMixerDevice.h"
#include "RHI.h"
#include "RHIResources.h"
#include "PipelineStateCache.h"
#include "WindowsFeaturesCommon.h"
#include "WindowsHighlightRecorder.h"

DECLARE_LOG_CATEGORY_EXTERN(WinVideoRecordingSystem, VeryVerbose, VeryVerbose);


//class FWindowsHighlightRecorder;

class FWinVideoRecordingSystem : public IRecordingSystem
{
public:
	FWinVideoRecordingSystem();
	~FWinVideoRecordingSystem() override;

	// IWinVideoRecordingSystem interface
	void EnableRecording(const bool bEnableRecording) override;
	bool IsEnabled() const override;
	bool NewRecording(const TCHAR* DestinationFileName, FRecordingParameters Parameters = FRecordingParameters(), FVideoRecordingConfig Config = FVideoRecordingConfig()) override;
	void StartRecording() override;
	void PauseRecording() override;
	virtual uint64 GetMinimumRecordingSeconds() const override;
	virtual uint64 GetMaximumRecordingSeconds() const override;
	float GetCurrentRecordingSeconds() const override;
	void FinalizeRecording(const bool bSaveRecording, const FText& Title, const FText& Comment, const bool bStopAutoContinue = true) override;
	ERecordingState GetRecordingState() const override;

	void InitializeVideoRecordingConfig(FVideoRecordingConfig InVideoRecordingConfig);

private:
	void NextRecording();
	void FinalizeCallbackOnGameThread(bool bSaved, bool bAutoContinue, FString Path, bool bBroadcast);

	TAtomic<ERecordingState> RecordState{ ERecordingState::None };

	FRecordingParameters Parameters;
	FVideoRecordingConfig VideoRecordingConfigs;

	FString BaseFilename;
	FString CurrentFilename;
	uint64 RecordingIndex = 0;
	uint64 CurrentStartRecordingCycles = 0;
	uint64 CyclesBeforePausing = 0;

	// If this is nullptr, then it means video recording is not enabled
	TUniquePtr<FWindowsHighlightRecorder> Recorder;

	bool bAudioFormatChecked = false;

	class FWindowsScreenRecording;
	TUniquePtr<FWindowsScreenRecording>	ScreenshotAndRecorderHandler;
};

