/**
* Copyright (C) 2017-2021 | eelDev
*/

#include "EOSVoiceSubsystem.h"
#include <VoiceChatResult.h>
#include "VoiceChat.h"
#include "EOSVoiceChatTypes.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Misc/Base64.h"
#include "Misc/ConfigCacheIni.h"
#include "EOSVoiceLogging.h"

struct FRequestData : public FJsonSerializable
{
	struct FRequestUser : public FJsonSerializable
	{
		explicit FRequestUser() = default;
		FString ProductUserId;
		FString ClientIp;
		bool bHardMuted;

		BEGIN_JSON_SERIALIZER
			JSON_SERIALIZE("puid", ProductUserId);
		JSON_SERIALIZE("clientIp", ClientIp);
		JSON_SERIALIZE("hardMuted", bHardMuted);
		END_JSON_SERIALIZER
};

	FRequestData()
	{
	}

	FRequestData(TArray<FRequestParticipantData> Users)
	{
		for (auto& Element : Users)
		{
			FRequestUser User;
			User.ProductUserId = Element.ProductUserId;
			User.ClientIp = Element.ClientIp;
			User.bHardMuted = Element.bHardMuted;

			UsersArray.Add(User);
		}
	}

	TArray<FRequestUser> UsersArray;

	BEGIN_JSON_SERIALIZER
	JSON_SERIALIZE_ARRAY_SERIALIZABLE("participants", UsersArray, FRequestUser);
	END_JSON_SERIALIZER
};

void UEOSVoiceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	
	m_EOSVoiceChat = IVoiceChat::Get();

	if (m_EOSVoiceChat)
	{
		m_OnEOSVoiceChatAvailableAudioDevicesChanged = m_EOSVoiceChat->OnVoiceChatAvailableAudioDevicesChanged().AddUObject(this, &UEOSVoiceSubsystem::OnVoiceChatAvailableAudioDevicesChanged);
		m_OnEOSVoiceChatConnected = m_EOSVoiceChat->OnVoiceChatConnected().AddUObject(this, &UEOSVoiceSubsystem::OnVoiceChatConnected);
		m_OnEOSVoiceChatDisconnected = m_EOSVoiceChat->OnVoiceChatDisconnected().AddUObject(this, &UEOSVoiceSubsystem::OnVoiceChatDisconnected);
		m_OnEOSVoiceChatReconnected = m_EOSVoiceChat->OnVoiceChatReconnected().AddUObject(this, &UEOSVoiceSubsystem::OnVoiceChatReconnected);
		m_OnVoiceChatLoggedIn = m_EOSVoiceChat->OnVoiceChatLoggedIn().AddUObject(this, &UEOSVoiceSubsystem::OnVoiceChatLoggedIn);
		m_OnVoiceChatLoggedOut = m_EOSVoiceChat->OnVoiceChatLoggedOut().AddUObject(this, &UEOSVoiceSubsystem::OnVoiceChatLoggedOut);
		m_OnVoiceChatChannelJoined = m_EOSVoiceChat->OnVoiceChatChannelJoined().AddUObject(this, &UEOSVoiceSubsystem::OnVoiceChatChannelJoined);
		m_OnVoiceChatChannelExited = m_EOSVoiceChat->OnVoiceChatChannelExited().AddUObject(this, &UEOSVoiceSubsystem::OnVoiceChatChannelExited);
		m_OnVoiceChatCallStatsUpdated = m_EOSVoiceChat->OnVoiceChatCallStatsUpdated().AddUObject(this, &UEOSVoiceSubsystem::OnVoiceChatCallStatsUpdated);
		m_OnVoiceChatPlayerAdded = m_EOSVoiceChat->OnVoiceChatPlayerAdded().AddUObject(this, &UEOSVoiceSubsystem::OnVoiceChatPlayerAdded);
		m_OnVoiceCHatPlayerRemoved = m_EOSVoiceChat->OnVoiceChatPlayerRemoved().AddUObject(this, &UEOSVoiceSubsystem::OnVoiceChatPlayerRemoved);
		m_OnEOSVoiceChatPlayerTalkingUpdated = m_EOSVoiceChat->OnVoiceChatPlayerTalkingUpdated().AddUObject(this, &UEOSVoiceSubsystem::OnVoiceChatPlayerTalkingUpdated);
		m_OnVoiceChatPlayerMuteUpdated = m_EOSVoiceChat->OnVoiceChatPlayerMuteUpdated().AddUObject(this, &UEOSVoiceSubsystem::OnVoiceChatPlayerMuteUpdated);
		m_OnEOSVoiceChatPlayerVolumeUpdated = m_EOSVoiceChat->OnVoiceChatPlayerVolumeUpdated().AddUObject(this, &UEOSVoiceSubsystem::OnVoiceChatPlayerVolumeUpdated);	
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("EOS Voice Chat NOT Valid"));
	}
}

void UEOSVoiceSubsystem::Deinitialize()
{
	Super::Deinitialize();

	if (m_EOSVoiceChat)
	{
#if WITH_EDITOR
		TArray<FString> Channels = GetChannels();
		for (auto Element : Channels)
		{
			m_EOSVoiceChat->LeaveChannel(Element, FOnVoiceChatChannelLeaveCompleteDelegate::CreateLambda([this](const FString& ChannelName, const FVoiceChatResult& Result){}));
		}
		
		m_EOSVoiceChat->Disconnect(FOnVoiceChatDisconnectCompleteDelegate::CreateLambda([this](const FVoiceChatResult& Result){}));
		UninitializeEOSCoreVoice();
#endif
		
		m_EOSVoiceChat->OnVoiceChatAvailableAudioDevicesChanged().Remove(m_OnEOSVoiceChatAvailableAudioDevicesChanged);
		m_EOSVoiceChat->OnVoiceChatConnected().Remove(m_OnEOSVoiceChatConnected);
		m_EOSVoiceChat->OnVoiceChatDisconnected().Remove(m_OnEOSVoiceChatDisconnected);
		m_EOSVoiceChat->OnVoiceChatReconnected().Remove(m_OnEOSVoiceChatReconnected);
		m_EOSVoiceChat->OnVoiceChatLoggedIn().Remove(m_OnVoiceChatLoggedIn);
		m_EOSVoiceChat->OnVoiceChatLoggedOut().Remove(m_OnVoiceChatLoggedOut);

		m_EOSVoiceChat->OnVoiceChatChannelJoined().Remove(m_OnVoiceChatChannelJoined);
		m_EOSVoiceChat->OnVoiceChatChannelExited().Remove(m_OnVoiceChatChannelExited);
		m_EOSVoiceChat->OnVoiceChatCallStatsUpdated().Remove(m_OnVoiceChatCallStatsUpdated);

		m_EOSVoiceChat->OnVoiceChatPlayerRemoved().Remove(m_OnVoiceChatPlayerAdded);
		m_EOSVoiceChat->OnVoiceChatPlayerRemoved().Remove(m_OnVoiceCHatPlayerRemoved);

		m_EOSVoiceChat->OnVoiceChatPlayerTalkingUpdated().Remove(m_OnEOSVoiceChatPlayerTalkingUpdated);
		m_EOSVoiceChat->OnVoiceChatPlayerMuteUpdated().Remove(m_OnVoiceChatPlayerMuteUpdated);
		m_EOSVoiceChat->OnVoiceChatPlayerVolumeUpdated().Remove(m_OnEOSVoiceChatPlayerVolumeUpdated);

	}
}

bool UEOSVoiceSubsystem::InitializeEOSCoreVoice()
{
	if (m_EOSVoiceChat)
	{
		if (!m_EOSVoiceChat->IsInitialized())
		{
			return m_EOSVoiceChat->Initialize();
		}
	}

	return false;
}

void UEOSVoiceSubsystem::UninitializeEOSCoreVoice()
{
	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->Uninitialize();
	}
}

void UEOSVoiceSubsystem::Connect(const FOnEOSCoreVoiceConnectCallback& Callback)
{
	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->Connect(FOnVoiceChatConnectCompleteDelegate::CreateLambda([this, Callback](const FVoiceChatResult& Result)
			{
				Callback.ExecuteIfBound(Result);
			}));
	}
}

void UEOSVoiceSubsystem::Disconnect(const FOnEOSCoreVoiceDisconnectCallback& Callback)
{
	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->Disconnect(FOnVoiceChatDisconnectCompleteDelegate::CreateLambda([this, Callback](const FVoiceChatResult& Result)
			{
				Callback.ExecuteIfBound(Result);
			}));
	}
}

bool UEOSVoiceSubsystem::IsConnecting() const
{
	if (m_EOSVoiceChat)
	{
		return m_EOSVoiceChat->IsConnecting();
	}

	return false;
}

bool UEOSVoiceSubsystem::IsConnected() const
{
	if (m_EOSVoiceChat)
	{
		return m_EOSVoiceChat->IsConnected();
	}

	return false;
}

void UEOSVoiceSubsystem::Login(int32 PlatformId, const FString& PlayerName, const FString& Credentials, const FOnEOSCoreVoiceLoginCallback& Callback)
{
	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->Login(PlatformId, PlayerName, Credentials, FOnVoiceChatLoginCompleteDelegate::CreateLambda([this, Callback](const FString& PlayerName, const FVoiceChatResult& Result)
			{
				Callback.ExecuteIfBound(Result.ErrorDesc, Result);
			}));
	}
}

void UEOSVoiceSubsystem::Logout(const FOnEOSCoreVoiceLogoutCallback& Callback)
{
	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->Logout(FOnVoiceChatLogoutCompleteDelegate::CreateLambda([this, Callback](const FString& PlayerName, const FVoiceChatResult& Result)
			{
				Callback.ExecuteIfBound(Result.ErrorDesc, Result);
			}));
	}
}

bool UEOSVoiceSubsystem::IsLoggingIn() const
{
	bool bResult = false;

	if (m_EOSVoiceChat)
	{
		bResult = m_EOSVoiceChat->IsLoggingIn();
	}

	return bResult;
}

bool UEOSVoiceSubsystem::IsLoggedIn() const
{
	bool bResult = false;

	if (m_EOSVoiceChat)
	{
		bResult = m_EOSVoiceChat->IsLoggedIn();
	}

	return bResult;
}

FString UEOSVoiceSubsystem::GetLoggedInPlayerName() const
{
	FString Result;

	if (m_EOSVoiceChat)
	{
		Result = m_EOSVoiceChat->GetLoggedInPlayerName();
	}

	return Result;
}

void UEOSVoiceSubsystem::BlockPlayers(const TArray<FString>& PlayerNames)
{
	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->BlockPlayers(PlayerNames);
	}
}

void UEOSVoiceSubsystem::UnblockPlayers(const TArray<FString>& PlayerNames)
{
	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->UnblockPlayers(PlayerNames);
	}
}

void UEOSVoiceSubsystem::JoinChannel(FString ChannelName, FString ChannelCredentials, EEOSCoreVoiceChatChannelType ChannelType, const FOnEOSCoreVoiceJoinChannelCallback& Callback, FEOSCoreVoiceChatChannel3dProperties Channel3dProperties)
{
	if (m_EOSVoiceChat)
	{
		FVoiceChatChannel3dProperties Properties;
		Properties.AttenuationModel = static_cast<EVoiceChatAttenuationModel>(Channel3dProperties.AttenuationModel);
		Properties.MaxDistance = Channel3dProperties.MaxDistance;
		Properties.MinDistance = Channel3dProperties.MinDistance;
		Properties.Rolloff = Channel3dProperties.Rolloff;

		m_EOSVoiceChat->JoinChannel(ChannelName, ChannelCredentials, static_cast<EVoiceChatChannelType>(ChannelType), FOnVoiceChatChannelJoinCompleteDelegate::CreateLambda([this, Callback](const FString& ChannelName, const FVoiceChatResult& Result)
			{
				Callback.ExecuteIfBound(ChannelName, Result);
			}), Properties);
	}
}

void UEOSVoiceSubsystem::LeaveChannel(FString ChannelName, const FOnEOSCoreVoiceLeaveChannelCallback& Callback)
{
	m_EOSVoiceChat->LeaveChannel(ChannelName, FOnVoiceChatChannelLeaveCompleteDelegate::CreateLambda([this, Callback](const FString& ChannelName, const FVoiceChatResult& Result)
		{
			Callback.ExecuteIfBound(ChannelName, Result);
		}));
}

void UEOSVoiceSubsystem::Set3DPosition(const FString& ChannelName, const FVector& SpeakerPosition, const FVector& ListenerPosition, const FVector& ListenerForwardDirection, const FVector& ListenerUpDirection)
{
	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->Set3DPosition(ChannelName, SpeakerPosition, ListenerPosition, ListenerForwardDirection, ListenerUpDirection);
	}
}

TArray<FString> UEOSVoiceSubsystem::GetChannels() const
{
	LogVeryVerbose("");

	TArray<FString> Result;

	if (m_EOSVoiceChat)
	{
		Result = m_EOSVoiceChat->GetChannels();
	}

	return Result;
}

TArray<FString> UEOSVoiceSubsystem::GetPlayersInChannel(FString channelName) const
{
	LogVeryVerbose("");

	TArray<FString> Result;

	if (m_EOSVoiceChat)
	{
		Result = m_EOSVoiceChat->GetPlayersInChannel(channelName);
	}


	return Result;
}

EEOSCoreVoiceChatChannelType UEOSVoiceSubsystem::GetChannelType(FString channelName) const
{
	LogVeryVerbose("");

	EEOSCoreVoiceChatChannelType Result = EEOSCoreVoiceChatChannelType::Positional;

	if (m_EOSVoiceChat)
	{
		Result = static_cast<EEOSCoreVoiceChatChannelType>(m_EOSVoiceChat->GetChannelType(channelName));
	}


	return Result;
}

bool UEOSVoiceSubsystem::IsPlayerTalking(FString playerName)
{
	LogVerbose("");

	bool bResult = false;

	if (m_EOSVoiceChat)
	{
		bResult = m_EOSVoiceChat->IsPlayerTalking(playerName);
	}


	return bResult;
}

void UEOSVoiceSubsystem::SetPlayerMuted(FString pPlayerName, bool bMuted)
{
	LogVerbose("");

	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->SetPlayerMuted(pPlayerName, bMuted);
	}

}

bool UEOSVoiceSubsystem::IsPlayerMuted(FString playerName) const
{
	LogVeryVerbose("");

	bool bResult = false;

	if (m_EOSVoiceChat)
	{
		bResult = m_EOSVoiceChat->IsPlayerMuted(playerName);
	}


	return bResult;
}

void UEOSVoiceSubsystem::SetPlayerVolume(FString playerName, float volume)
{
	LogVerbose("");

	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->SetPlayerVolume(playerName, volume);
	}

}

float UEOSVoiceSubsystem::GetPlayerVolume(FString playerName) const
{
	LogVeryVerbose("");

	float Result = 0.0f;

	if (m_EOSVoiceChat)
	{
		Result = m_EOSVoiceChat->GetPlayerVolume(playerName);
	}


	return Result;
}

void UEOSVoiceSubsystem::TransmitToAllChannels()
{
	LogVerbose("");

	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->TransmitToAllChannels();
	}

}

void UEOSVoiceSubsystem::TransmitToNoChannels()
{
	LogVerbose("");

	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->TransmitToNoChannels();
	}

}

void UEOSVoiceSubsystem::TransmitToSpecificChannel(FString channelName)
{
	LogVerbose("");

	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->TransmitToSpecificChannel(channelName);
	}

}

EEOSVoiceChatTransmitMode UEOSVoiceSubsystem::GetTransmitMode() const
{
	LogVeryVerbose("");

	EEOSVoiceChatTransmitMode Result = EEOSVoiceChatTransmitMode::All;

	if (m_EOSVoiceChat)
	{
		Result = static_cast<EEOSVoiceChatTransmitMode>(m_EOSVoiceChat->GetTransmitMode());
	}


	return Result;
}

FString UEOSVoiceSubsystem::GetTransmitChannel() const
{
	LogVeryVerbose("");

	FString Result;

	if (m_EOSVoiceChat)
	{
		Result = m_EOSVoiceChat->GetTransmitChannel();
	}

	return Result;
}

void UEOSVoiceSubsystem::SetSetting(const FString& Name, const FString& Value)
{
	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->SetSetting(Name, Value);
	}
}

FString UEOSVoiceSubsystem::GetSetting(const FString& Name)
{
	LogVeryVerbose("");

	FString Result;

	if (m_EOSVoiceChat)
	{
		Result = m_EOSVoiceChat->GetSetting(Name);
	}

	return Result;
}

void UEOSVoiceSubsystem::SetAudioInputVolume(float volume)
{
	LogVerbose("");

	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->SetAudioInputVolume(volume);
	}

}

void UEOSVoiceSubsystem::SetAudioOutputVolume(float volume)
{
	LogVerbose("");

	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->SetAudioOutputVolume(volume);
	}
}

float UEOSVoiceSubsystem::GetAudioInputVolume() const
{
	LogVeryVerbose("");

	float Result = 0.0f;

	if (m_EOSVoiceChat)
	{
		Result = m_EOSVoiceChat->GetAudioInputVolume();
	}

	return Result;
}

float UEOSVoiceSubsystem::GetAudioOutputVolume() const
{
	LogVeryVerbose("");

	float Result = 0.0f;

	if (m_EOSVoiceChat)
	{
		Result = m_EOSVoiceChat->GetAudioOutputVolume();
	}

	return Result;
}

void UEOSVoiceSubsystem::SetAudioInputDeviceMuted(bool bIsMuted)
{
	LogVerbose("");

	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->SetAudioInputDeviceMuted(bIsMuted);
	}
}

void UEOSVoiceSubsystem::SetAudioOutputDeviceMuted(bool bIsMuted)
{
	LogVerbose("");

	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->SetAudioOutputDeviceMuted(bIsMuted);
	}
}

bool UEOSVoiceSubsystem::GetAudioInputDeviceMuted() const
{
	LogVeryVerbose("");

	bool bResult = false;

	if (m_EOSVoiceChat)
	{
		bResult = m_EOSVoiceChat->GetAudioInputDeviceMuted();
	}

	return bResult;
}

bool UEOSVoiceSubsystem::GetAudioOutputDeviceMuted() const
{
	LogVeryVerbose("");

	bool bResult = false;

	if (m_EOSVoiceChat)
	{
		bResult = m_EOSVoiceChat->GetAudioOutputDeviceMuted();
	}

	return bResult;
}

TArray<FEOSVoiceChatDeviceInfo> UEOSVoiceSubsystem::GetAvailableInputDeviceInfos() const
{
	LogVeryVerbose("");

	TArray<FEOSVoiceChatDeviceInfo> Result;


	if (m_EOSVoiceChat)
	{
		TArray<FVoiceChatDeviceInfo> Data = m_EOSVoiceChat->GetAvailableInputDeviceInfos();

		for (auto& Element : Data)
		{
			Result.Add(Element);
		}
	}
	return Result;
}

TArray<FEOSVoiceChatDeviceInfo> UEOSVoiceSubsystem::GetAvailableOutputDeviceInfos() const
{
	LogVeryVerbose("");

	TArray<FEOSVoiceChatDeviceInfo> Result;

	if (m_EOSVoiceChat)
	{
		TArray<FVoiceChatDeviceInfo> Data;
		Data = m_EOSVoiceChat->GetAvailableOutputDeviceInfos();

		for (auto& Element : Data)
		{
			Result.Add(Element);
		}
	}

	return Result;
}

void UEOSVoiceSubsystem::SetInputDeviceId(FString inputDeviceId)
{
	LogVerbose("");

	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->SetInputDeviceId(inputDeviceId);
	}

}

void UEOSVoiceSubsystem::SetOutputDeviceId(FString outputDeviceId)
{
	LogVerbose("");

	if (m_EOSVoiceChat)
	{
		m_EOSVoiceChat->SetOutputDeviceId(outputDeviceId);
	}

}

FEOSVoiceChatDeviceInfo UEOSVoiceSubsystem::GetInputDeviceInfo() const
{
	LogVeryVerbose("");

	FEOSVoiceChatDeviceInfo Result;

	if (m_EOSVoiceChat)
	{
		Result = m_EOSVoiceChat->GetInputDeviceInfo();
	}

	return Result;
}

FEOSVoiceChatDeviceInfo UEOSVoiceSubsystem::GetOutputDeviceInfo() const
{
	LogVeryVerbose("");

	FEOSVoiceChatDeviceInfo Result;

	if (m_EOSVoiceChat)
	{
		Result = m_EOSVoiceChat->GetOutputDeviceInfo();
	}

	return Result;
}

FEOSVoiceChatDeviceInfo UEOSVoiceSubsystem::GetDefaultInputDeviceInfo() const
{
	LogVeryVerbose("");

	FEOSVoiceChatDeviceInfo Result;

	if (m_EOSVoiceChat)
	{
		Result = m_EOSVoiceChat->GetDefaultInputDeviceInfo();
	}

	return Result;
}

FEOSVoiceChatDeviceInfo UEOSVoiceSubsystem::GetDefaultOutputDeviceInfo() const
{
	LogVeryVerbose("");

	FEOSVoiceChatDeviceInfo Result;

	if (m_EOSVoiceChat)
	{
		Result = m_EOSVoiceChat->GetDefaultOutputDeviceInfo();
	}

	return Result;
}

void UEOSVoiceSubsystem::GetJoinToken(FString ClientId, FString ClientSecret, FString DeploymentId, FString RoomName, TArray<FRequestParticipantData> Participants, const FOnSomeCallback& Callback)
{
	if (ClientId.IsEmpty())
	{
		LogError("ClientId cannot be empty");
		return;
	}

	if (ClientSecret.IsEmpty())
	{
		LogError("ClientSecret cannot be empty");
		return;
	}

	if (DeploymentId.IsEmpty())
	{
		LogError("DeploymentId cannot be empty");
		return;
	}

	if (RoomName.IsEmpty())
	{
		LogError("RoomName cannot be empty");
		return;
	}
	
	if (Participants.Num() == 0)
	{
		LogError("Participants cannot be empty");
		return;
	}
	
	FString Result;
	auto HttpRequest = FHttpModule::Get().CreateRequest();
	const FString Base64Credentials = FBase64::Encode(FString::Printf(TEXT("%s:%s"), *ClientId, *ClientSecret));
	const FString ContentString = FString::Printf(TEXT("grant_type=client_credentials&deployment_id=%s"), *DeploymentId);
	
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/x-www-form-urlencoded"));
	HttpRequest->AppendToHeader(TEXT("Accept"), TEXT("application/json"));
	HttpRequest->AppendToHeader(TEXT("Authorization"), *FString::Printf(TEXT("Basic %s"), *Base64Credentials));
	HttpRequest->SetContentAsString(ContentString);
	HttpRequest->SetURL("https://api.epicgames.dev/auth/v1/oauth/token");
	HttpRequest->SetVerb("POST");

	HttpRequest->OnProcessRequestComplete().BindLambda([=](FHttpRequestPtr HttpRequestPtr, FHttpResponsePtr HttpResponsePtr, bool bConnectedSuccessfully)
	{
		FString AccessTokenString;

		if (bConnectedSuccessfully)
		{
			TSharedPtr<FJsonObject> JsonObject;
			TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(HttpResponsePtr->GetContentAsString());

			if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
			{
				TSharedPtr<FJsonValue> AccessTokenObject = JsonObject->TryGetField(TEXT("access_token"));

				if (AccessTokenObject)
				{
					AccessTokenString = AccessTokenObject->AsString();
				}
			}
		}
		else
		{
			Callback.ExecuteIfBound("Connection failed!" + HttpResponsePtr->GetContentAsString());
		}

		if (bConnectedSuccessfully && !AccessTokenString.IsEmpty())
		{
			// create room token

			auto RoomTokenRequest = FHttpModule::Get().CreateRequest();

			RoomTokenRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
			RoomTokenRequest->AppendToHeader(TEXT("Accept"), TEXT("application/json"));
			RoomTokenRequest->AppendToHeader(TEXT("Authorization"), *FString::Printf(TEXT("Bearer %s"), *AccessTokenString));

			FRequestData RequestData(Participants);
			const FString ContentString = *RequestData.ToJson(false);

			RoomTokenRequest->SetContentAsString(ContentString);
			RoomTokenRequest->SetURL(FString::Printf(TEXT("https://api.epicgames.dev/rtc/v1/%s/room/%s"), *DeploymentId, *RoomName));
			RoomTokenRequest->SetVerb("POST");
			RoomTokenRequest->OnProcessRequestComplete().BindLambda([=](FHttpRequestPtr HttpRequestPtr, FHttpResponsePtr HttpResponsePtr, bool bConnectedSuccessfully)
			{
				FString ClientBaseUrlString;
				FString TokenString;

				if (bConnectedSuccessfully)
				{
					if (HttpResponsePtr->GetResponseCode() == 200)
					{
						TSharedPtr<FJsonObject> JsonObject;
						const TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(HttpResponsePtr->GetContentAsString());

						if (FJsonSerializer::Deserialize(JsonReader, JsonObject) && JsonObject.IsValid())
						{
							const TSharedPtr<FJsonValue> ClientBaseUrlObject = JsonObject->TryGetField(TEXT("clientBaseUrl"));
							const TSharedPtr<FJsonValue> ParticipantsObject = JsonObject->TryGetField(TEXT("participants"));

							if (!ClientBaseUrlObject)
							{
								LogError("No ClientBaseUrl was found");
							}

							if (!ParticipantsObject)
							{
								LogError("No Participants was found");
							}

							if (ClientBaseUrlObject && ParticipantsObject)
							{
								ClientBaseUrlString = ClientBaseUrlObject->AsString();

								if (ParticipantsObject && ParticipantsObject->Type == EJson::Array)
								{
									TArray<TSharedPtr<FJsonValue>> ParticipantsArray = ParticipantsObject->AsArray();

									for (const auto& Element : ParticipantsArray)
									{
										if (Element->Type != EJson::Object)
											continue;

										auto& Object = Element->AsObject();

										TokenString = Object->TryGetField("token")->AsString();
									}
								}
							}
						}
					}
					else
					{
						LogError("Error Code: %d", HttpResponsePtr->GetResponseCode());
					}
				}
				else
				{
					LogError("Connection failed");
				}

				FEOSVoiceChatChannelCredentials Credentials;
				Credentials.ParticipantToken = TokenString;
				Credentials.ClientBaseUrl = ClientBaseUrlString;
				Credentials.OverrideUserId = Participants[0].ProductUserId;

				Callback.ExecuteIfBound(Credentials.ToJson(false));
			});

			RoomTokenRequest->ProcessRequest();
		}
		else
		{
			
		}
	});

	HttpRequest->ProcessRequest();
}

FString UEOSVoiceSubsystem::GetClientId()
{
	FString Result;
	GConfig->GetString(TEXT("EOSVoiceChat"), TEXT("ClientId"), Result, GEngineIni);
	return Result;
}

FString UEOSVoiceSubsystem::GetClientSecret()
{
	FString Result;
	GConfig->GetString(TEXT("EOSVoiceChat"), TEXT("ClientSecret"), Result, GEngineIni);
	return Result;
}

FString UEOSVoiceSubsystem::GetDeploymentId()
{
	FString Result;
	GConfig->GetString(TEXT("EOSVoiceChat"), TEXT("DeploymentId"), Result, GEngineIni);
	return Result;
}

void UEOSVoiceSubsystem::OnVoiceChatAvailableAudioDevicesChanged()
{
	OnEOSVoiceChatAvailableAudioDevicesChanged.Broadcast();
}

void UEOSVoiceSubsystem::OnVoiceChatConnected()
{
	OnEOSVoiceChatConnected.Broadcast();
}

void UEOSVoiceSubsystem::OnVoiceChatDisconnected(const FVoiceChatResult& result)
{
	OnEOSVoiceChatDisconnected.Broadcast(result);
}

void UEOSVoiceSubsystem::OnVoiceChatReconnected()
{
	OnEOSVoiceChatReconnected.Broadcast();
}

void UEOSVoiceSubsystem::OnVoiceChatLoggedIn(const FString& playerName)
{
	OnEOSVoiceChatLoggedIn.Broadcast(playerName);
}

void UEOSVoiceSubsystem::OnVoiceChatLoggedOut(const FString& playerName)
{
	OnEOSVoiceChatLoggedOut.Broadcast(playerName);
}

void UEOSVoiceSubsystem::OnVoiceChatChannelJoined(const FString& playerName)
{
	OnEOSVoiceChatChannelJoined.Broadcast(playerName);
}

void UEOSVoiceSubsystem::OnVoiceChatChannelExited(const FString& channelName, const FVoiceChatResult& reason)
{
	OnEOSVoiceChatChannelExited.Broadcast(channelName, reason);
}

void UEOSVoiceSubsystem::OnVoiceChatCallStatsUpdated(const FVoiceChatCallStats& callstats)
{
	OnEOSVoiceChatCallStatsUpdated.Broadcast(callstats);
}

void UEOSVoiceSubsystem::OnVoiceChatPlayerRemoved(const FString& channelName, const FString& playerName)
{
	OnEOSVoiceChatPlayerRemoved.Broadcast(channelName, playerName);
}

void UEOSVoiceSubsystem::OnVoiceChatPlayerAdded(const FString& channelName, const FString& playerName)
{
	OnEOSVoiceChatPlayerAdded.Broadcast(channelName, playerName);
}

void UEOSVoiceSubsystem::OnVoiceChatPlayerTalkingUpdated(const FString& channelName, const FString& playerName, bool bIsTalking)
{
	OnEOSVoiceChatPlayerTalkingUpdated.Broadcast(channelName, playerName, bIsTalking);
}

void UEOSVoiceSubsystem::OnVoiceChatPlayerMuteUpdated(const FString& channelName, const FString& playerName, bool bIsMuted)
{
	OnEOSVoiceChatPlayerMuteUpdated.Broadcast(channelName, playerName, bIsMuted);
}

void UEOSVoiceSubsystem::OnVoiceChatPlayerVolumeUpdated(const FString& channelName, const FString& playerName, float volume)
{
	OnEOSVoiceChatPlayerVolumeUpdated.Broadcast(channelName, playerName, volume);
}