/**
* Copyright (C) 2017-2021 | eelDev
*/

#pragma once

#include "CoreMinimal.h"
#include "VoiceChat.h"
#include "VoiceChatResult.h"
#include "EOSCoreVoiceTypes.generated.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		ENUMS
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
UENUM(BlueprintType)
enum class EEOSVoiceChatTransmitMode : uint8
{
	/** Transmit to none of the channels you are in */
	None,
	/** Transmit to all of the channels you are in */
	All,
	/** Transmit to a specific channel */
	Channel
};

UENUM(BlueprintType)
enum class EEOSCoreVoiceChatChannelType : uint8
{
	/** Non positional/2d audio channel */
	NonPositional,
	/** Positional/3d audio channel */
	Positional,
	/** Echo channel. Will only ever have one player and will echo anything you say */
	Echo
};

UENUM(BlueprintType)
enum class EEOSCoreVoiceChatResult : uint8
{
	// The operation succeeded
	Success = 0,

	// Common state errors
	InvalidState,
	NotInitialized,
	NotConnected,
	NotLoggedIn,
	NotPermitted,
	Throttled,

	// Common argument errors
	InvalidArgument,
	CredentialsInvalid,
	CredentialsExpired,

	// Common connection errors
	ClientTimeout,
	ServerTimeout,
	DnsFailure,
	ConnectionFailure,

	// Error does not map to any common categories
	ImplementationError
};

UENUM(BlueprintType)
enum class EEOSCoreVoiceChatAttenuationModel : uint8
{
	/** No attenuation is applied. The audio will drop to 0 at MaxDistance */
	None,
	/** The attenuation increases in inverse proportion to the distance. The Rolloff is the inverse of the slope of the attenuation curve. */
	InverseByDistance,
	/** The attenuation increases in linear proportion to the distance. The Rolloff is the negative slope of the attenuation curve. */
	LinearByDistance,
	/** The attenuation increases in inverse proportion to the distance raised to the power of the Rolloff. */
	ExponentialByDistance
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		STRUCTS
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
USTRUCT(BlueprintType)
struct FRequestParticipantData
{
	GENERATED_BODY()
public:
	explicit FRequestParticipantData()
		: ClientIp("10.0.0.1")
		, bHardMuted(false)
	{
	}

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	FString ProductUserId;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	FString ClientIp;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	bool bHardMuted;
};

USTRUCT(BlueprintType)
struct FEOSVoiceChatDeviceInfo
{
	GENERATED_BODY()
public:
	FEOSVoiceChatDeviceInfo() = default;

	FEOSVoiceChatDeviceInfo(const FVoiceChatDeviceInfo& Data)
		: DisplayName(Data.DisplayName)
		, Id(Data.Id)
	{
	}

	FEOSVoiceChatDeviceInfo(FString DisplayName)
		: DisplayName(DisplayName)
	{
	}

public:
	/** The display name for the device */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EOSVoice")
	FString DisplayName;
	/** The unique id for the device */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EOSVoice")
	FString Id;
};

USTRUCT(BlueprintType)
struct FEOSCoreVoiceChatResult
{
	GENERATED_BODY()
public:
	FEOSCoreVoiceChatResult() = default;

	FEOSCoreVoiceChatResult(const FVoiceChatResult& data)
		: ResultCode(static_cast<EEOSCoreVoiceChatResult>(data.ResultCode))
		, ErrorCode(data.ErrorCode)
		, ErrorNum(data.ErrorNum)
		, ErrorDesc(data.ErrorDesc)
	{
	}

public:
	/** Success, or an error category */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EOSVoice")
	EEOSCoreVoiceChatResult ResultCode;
	/** If we failed, the code for the error */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EOSVoice")
	FString ErrorCode;
	/** If we failed, a numeric error from the implementation */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EOSVoice")
	int ErrorNum;
	/** If we failed, more details about the error condition */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EOSVoice")
	FString ErrorDesc;
};

USTRUCT(BlueprintType)
struct FEOSCoreVoiceChatChannel3dProperties
{
	GENERATED_BODY()
public:
	FEOSCoreVoiceChatChannel3dProperties()
		: AttenuationModel(EEOSCoreVoiceChatAttenuationModel::InverseByDistance)
		, MinDistance(270.f)
		, MaxDistance(8100.f)
		, Rolloff(1.0f)
	{
	}

public:
	/** The model used to determine how loud audio is at different distances */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EOSVoice")
	EEOSCoreVoiceChatAttenuationModel AttenuationModel;
	/** The distance at which the sound will start to attenuate */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EOSVoice")
	float MinDistance;
	/** The distance at which sound will no longer be audible */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EOSVoice")
	float MaxDistance;
	/** How fast the sound attenuates with distance */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EOSVoice")
	float Rolloff;
};

USTRUCT(BlueprintType)
struct FEOSVoiceChatCallStats
{
	GENERATED_BODY()
public:
	FEOSVoiceChatCallStats() = default;
	FEOSVoiceChatCallStats(const FVoiceChatCallStats& data)
		: CallLength(LexToString(data.CallLength))
		, LatencyMinMeasuredSeconds(LexToString(data.LatencyMinMeasuredSeconds))
		, LatencyMaxMeasuredSeconds(LexToString(data.LatencyMaxMeasuredSeconds))
		, LatencyAverageMeasuredSeconds(LexToString(data.LatencyAverageMeasuredSeconds))
		, PacketsNumTotal(data.PacketsNumTotal)
		, PacketsNumLost(data.PacketsNumLost)
	{}
public:
	/** Call length in seconds */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EOSCoreVoice")
	FString CallLength;
	/** Minimum measured network latency in seconds. Zero if no measurements made */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EOSCoreVoice")
	FString LatencyMinMeasuredSeconds;
	/** Maximum measured network latency in seconds. Zero if no measurements made */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EOSCoreVoice")
	FString LatencyMaxMeasuredSeconds;
	/** Average measured network latency in seconds. Zero if no measurements made */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EOSCoreVoice")
	FString LatencyAverageMeasuredSeconds;
	/** Total number of packets, both received and lost */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EOSCoreVoice")
	int PacketsNumTotal;
	/** Total number of lost packets */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EOSCoreVoice")
	int PacketsNumLost;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		CALLBACKS
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnEOSCoreVoiceConnectCallback, const FEOSCoreVoiceChatResult&, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnEOSCoreVoiceDisconnectCallback, const FEOSCoreVoiceChatResult&, Result);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnEOSCoreVoiceLoginCallback, const FString&, PlayerName, const FEOSCoreVoiceChatResult&, Result);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnEOSCoreVoiceLogoutCallback, const FString&, PlayerName, const FEOSCoreVoiceChatResult&, Result);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnEOSCoreVoiceJoinChannelCallback, const FString&, ChannelName, const FEOSCoreVoiceChatResult&, Result);
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnEOSCoreVoiceLeaveChannelCallback, const FString&, ChannelName, const FEOSCoreVoiceChatResult&, Result);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnSomeCallback, const FString&, Data);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEOSVoiceChatAvailableAudioDevicesChangedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEOSVoiceChatReconnectedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEOSVoiceChatConnectedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEOSVoiceChatDisconnectedDelegate, const FEOSCoreVoiceChatResult&, Result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEOSVoiceChatLoggedInDelegate, const FString&, PlayerName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEOSVoiceChatLoggedOutDelegate, const FString&, PlayerName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEOSVoiceChatChannelJoinedDelegate, const FString&, ChannelName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEOSVoiceChatChannelExitedDelegate, const FString&, ChannelName, const FEOSCoreVoiceChatResult&, Result);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEOSVoiceChatCallStatsUpdatedDelegate, const FEOSVoiceChatCallStats&, callStats);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEOSVoiceChatPlayerAddedDelegate, const FString&, ChannelName, const FString&, PlayerName);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEOSVoiceChatPlayerRemovedDelegate, const FString&, ChannelName, const FString&, PlayerName);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnEOSVoiceChatPlayerTalkingUpdatedDelegate, const FString&, ChannelName, const FString&, PlayerName, bool, bIsTalking);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnEOSVoiceChatPlayerMuteUpdatedDelegate, const FString&, ChannelName, const FString&, PlayerName, bool, bIsMuted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnEOSVoiceChatPlayerVolumeUpdatedDelegate, const FString&, ChannelName, const FString&, PlayerName, float, Volume);