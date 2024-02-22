/**
* Copyright (C) 2017-2021 | eelDev
*/

#pragma once

#include "CoreMinimal.h"

#include "Subsystems/GameInstanceSubsystem.h"
#include "EOSCoreVoiceTypes.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "EOSVoiceSubsystem.generated.h"

class IVoiceChat;

UCLASS()
class UEOSVoiceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Voice", WorldContext = "WorldContextObject"), Category = "EOSCoreVoice")
	static UEOSVoiceSubsystem* Get(UObject* WorldContextObject) 
		{
			if (WorldContextObject && WorldContextObject->GetWorld())
			{
				if (UEOSVoiceSubsystem* m_EOSVoiceSubsystem = UGameInstance::GetSubsystem<UEOSVoiceSubsystem>(WorldContextObject->GetWorld()->GetGameInstance()))
				{
					return m_EOSVoiceSubsystem;
				}
			}

			return nullptr;
		}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
//		DELEGATES
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

	/**
	 * Delegate broadcast whenever the available audio devices change. Any cached values from GetAvailableInputDevices or GetAvailableOutputDevices should be discarded and requeried
	 */
	UPROPERTY(BlueprintAssignable)
		FOnEOSVoiceChatAvailableAudioDevicesChangedDelegate OnEOSVoiceChatAvailableAudioDevicesChanged;

	/**
	 * Delegate triggered when we are connected to voice chat
	 */
	UPROPERTY(BlueprintAssignable)
		FOnEOSVoiceChatConnectedDelegate OnEOSVoiceChatConnected;

	/**
	 * Delegate triggered when we are disconnected from voice chat
	 */
	UPROPERTY(BlueprintAssignable)
		FOnEOSVoiceChatDisconnectedDelegate OnEOSVoiceChatDisconnected;

	/**
	 * Delegate triggered when we are reconnected to voice chat in cases where the underlying implementation disconnected
	 * and then reconnected. This is most commonly seen when an application resumes after being suspended. If the disconnect
	 * is unexpected, OnVoiceChatDisconnected will be called instead.
	 */
	UPROPERTY(BlueprintAssignable)
		FOnEOSVoiceChatReconnectedDelegate OnEOSVoiceChatReconnected;

	/**
	 * Delegate triggered when we are logged in to voice chat
	 */
	UPROPERTY(BlueprintAssignable)
		FOnEOSVoiceChatLoggedInDelegate OnEOSVoiceChatLoggedIn;

	/**
	 * Delegate triggered when we are logged out from voice chat
	 */
	UPROPERTY(BlueprintAssignable)
		FOnEOSVoiceChatLoggedOutDelegate OnEOSVoiceChatLoggedOut;

	/**
	 * Delegate triggered when we join a voice channel
	 */
	UPROPERTY(BlueprintAssignable)
		FOnEOSVoiceChatChannelJoinedDelegate OnEOSVoiceChatChannelJoined;

	/**
	 * Delegate triggered when we leave a voice channel
	 */
	UPROPERTY(BlueprintAssignable)
		FOnEOSVoiceChatChannelExitedDelegate OnEOSVoiceChatChannelExited;

	/**
	 * Delegate triggered when a call is ended, providing the stats for the call.
	 */
	UPROPERTY(BlueprintAssignable)
		FOnEOSVoiceChatCallStatsUpdatedDelegate OnEOSVoiceChatCallStatsUpdated;

	/**
	 * Delegate triggered when a player is added to a channel
	 */
	UPROPERTY(BlueprintAssignable)
		FOnEOSVoiceChatPlayerAddedDelegate OnEOSVoiceChatPlayerAdded;

	/**
	 * Delegate triggered when a player is removed from a channel
	 */
	UPROPERTY(BlueprintAssignable)
		FOnEOSVoiceChatPlayerRemovedDelegate OnEOSVoiceChatPlayerRemoved;

	/**
	 * Delegate triggered when a player's talking state is updated
	 */
	UPROPERTY(BlueprintAssignable)
		FOnEOSVoiceChatPlayerTalkingUpdatedDelegate OnEOSVoiceChatPlayerTalkingUpdated;

	/**
	 * Delegate triggered when a player's muted state is updated, usually as a Result of calling SetPlayerMuted
	 */
	UPROPERTY(BlueprintAssignable)
		FOnEOSVoiceChatPlayerMuteUpdatedDelegate OnEOSVoiceChatPlayerMuteUpdated;

	/**
	 * Delegate triggered when a player's volume is updated, usually as a Result of calling SetPlayerVolume
	 */
	UPROPERTY(BlueprintAssignable)
		FOnEOSVoiceChatPlayerVolumeUpdatedDelegate OnEOSVoiceChatPlayerVolumeUpdated;
public:
	IVoiceChat* m_EOSVoiceChat;
public:
	/**
	* Initialize VoiceChat
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice")
	bool InitializeEOSCoreVoice();

	/**
	* Uninitialize VoiceChat
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice")
	void UninitializeEOSCoreVoice();

	/**
	* Connect to a voice server
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice", meta = (AutoCreateRefTerm = "Callback"))
	void Connect(const FOnEOSCoreVoiceConnectCallback& Callback);

	/**
	* Disconnect from a voice server
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice", meta = (AutoCreateRefTerm = "Callback"))
	void Disconnect(const FOnEOSCoreVoiceDisconnectCallback& Callback);

	/**
	* Are we connecting to the voice server?
	*
	* @return true if we are connecting to the voice server
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice")
	bool IsConnecting() const;

	/**
	* Are we connected to the voice server?
	*
	* @return true if we are connected to the voice server
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice")
	bool IsConnected() const;

	/**
	* Login to the connected voice server
	*
	* @param PlatformId Platform user Id for the player logging in
	* @param PlayerName Name of the account to login to
	* @param Credentials Token or password
	* @param Callback delegate called once login completes
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User", meta = (AutoCreateRefTerm = "Callback"))
	void Login(int32 PlatformId, const FString& PlayerName, const FString& Credentials, const FOnEOSCoreVoiceLoginCallback& Callback);

	/**
	* Logout from the connected voice server
	*
	* @param Callback delegate called once logout completes
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User", meta = (AutoCreateRefTerm = "Callback"))
	void Logout(const FOnEOSCoreVoiceLogoutCallback& Callback);

	/**
	* Are we logging in?
	*
	* @return true if we are logging in to the voice server
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	bool IsLoggingIn() const;

	/**
	* Are we logged in?
	*
	* @return true if we are logged in to the voice server
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	bool IsLoggedIn() const;

	/**
	* Get the player name used to log in
	*
	* @return player name used to log in
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	FString GetLoggedInPlayerName() const;

	/**
	* Block communication with players
	*
	* Adds the PlayerNames to the block list, muting them in all current and subsequently joined channels.
	* A block for a player persists until either:
	*		- The local user logs out (e.g. by calling Logout/Disconnect/Uninitialize, or receiving equivalent events)
	*		- A subsequent call to UnblockPlayers is made with that PlayerName.
	*
	* @param PlayerNames List of players to block communication with
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	void BlockPlayers(const TArray<FString>& PlayerNames);

	/**
	* Unblock communication with players
	*
	* @param PlayerNames List of players to unblock communication with
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	void UnblockPlayers(const TArray<FString>& PlayerNames);

	/**
	* Join a voice channel
	*
	* @param ChannelName Channel to join
	* @param ChannelCredentials password or token
	* @param ChannelType NonPositional, Positional, or Echo
	* @param Callback delegate called once join completes
	* @param Channel3dProperties Optional parameter to set 3d/Positional channel properties
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User", meta = (AutoCreateRefTerm = "Callback"))
	void JoinChannel(FString ChannelName, FString ChannelCredentials, EEOSCoreVoiceChatChannelType ChannelType, const FOnEOSCoreVoiceJoinChannelCallback& Callback, FEOSCoreVoiceChatChannel3dProperties Channel3dProperties);

	/**
	* Leave a voice channel
	*
	* @param ChannelName Channel to leave
	* @param Callback delegate called once leave completes
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User", meta = (AutoCreateRefTerm = "Callback"))
	void LeaveChannel(FString ChannelName, const FOnEOSCoreVoiceLeaveChannelCallback& Callback);

	/**
	* Set the 3d position of the player
	*
	* @param ChannelName
	* @param SpeakerPosition
	* @param ListenerPosition
	* @param ListenerForwardDirection
	* @param ListenerUpDirection
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	void Set3DPosition(const FString& ChannelName, const FVector& SpeakerPosition, const FVector& ListenerPosition, const FVector& ListenerForwardDirection, const FVector& ListenerUpDirection);

	/**
	* Get an array of channels the user is in
	*
	* @return Array of connected channel names
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	TArray<FString> GetChannels() const;

	/**
	 * Get an array of players in a channel
	 *
	 * @param ChannelName Channel to get the list of players for
	 * @return Array of names of players in Channel
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	TArray<FString> GetPlayersInChannel(FString ChannelName) const;

	/**
	 * Get an array of players in a channel
	 *
	 * @param ChannelName Channel to get the type of
	 * @return Channel type
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	EEOSCoreVoiceChatChannelType GetChannelType(FString ChannelName) const;

	/**
	 * @param PlayerName Player to get the talking state of
	 * @return true if player is talking
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	bool IsPlayerTalking(FString PlayerName);

	/**
	 * Mute or unmute a player
	 *
	 * @param PlayerName Player to mute
	 * @param bMuted true if the player should be muted
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	void SetPlayerMuted(FString PlayerName, bool bMuted);

	/**
	 * @param PlayerName Player to get the mute state of
	 * @return true if player is muted
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	bool IsPlayerMuted(FString PlayerName) const;

	/**
	 * Set player volume
	 *
	 * @param PlayerName Player to adjust the volume for
	 * @param Volume Value between 0.0 and 1.0
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	void SetPlayerVolume(FString PlayerName, float Volume);

	/**
	 * @param PlayerName Player to get the volume of
	 * @return volume for player
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	float GetPlayerVolume(FString PlayerName) const;

	/**
	 * Transmit to all channels that you are currently in
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	void TransmitToAllChannels();

	/**
	 * Stop transmitting to all channels that you are currently in. This does not apply to channels you will join.
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	void TransmitToNoChannels();

	/**
	 * Transmit to a specific channel
	 *
	 * @param ChannelName Channel to transmit to
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	void TransmitToSpecificChannel(FString ChannelName);

	/**
	 * Get the current transmit mode
	 *
	 * @return Transmit mode. If it is EVoiceChatTransmitMode::Channel, the channel can be retrieved using GetTransmitChannel()
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	EEOSVoiceChatTransmitMode GetTransmitMode() const;

	/**
	 * Get the specific channel we are transmitting to
	 *
	 * @return Channel we are transmitting to. Will be empty if GetTransmissionMode() returned a value other than EVoiceChatTransmitMode::Channel
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	FString GetTransmitChannel() const;


	/**
	* Set an implementation specific setting
	*
	* @param Name Name of the config setting to set
	* @param Value Value for the setting
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	void SetSetting(const FString& Name, const FString& Value);

	/**
	* Get an implementation specific setting
	*
	* @param Name Name of the config setting to get
	*
	* @return Current value for the setting
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	FString GetSetting(const FString& Name);

	/**
	 * Set record volume
	 *
	 * @param Volume Value between 0.0 and 1.0
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	void SetAudioInputVolume(float Volume);

	/**
	 * Set playback volume
	 *
	 * @param Volume Value between 0.0 and 1.0
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	void SetAudioOutputVolume(float Volume);

	/**
	 * Get volume of audio input device
	 *
	 * @return Audio input device volume. Will be between 0.0 and 1.0
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	float GetAudioInputVolume() const;

	/**
	 * Get volume of audio output device
	 *
	 * @return Audio output device volume. Will be between 0.0 and 1.0
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	float GetAudioOutputVolume() const;

	/**
	 * Mute or unmute the audio input device
	 *
	 * @param bIsMuted set to true to mute the device or false to unmute
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	void SetAudioInputDeviceMuted(bool bIsMuted);

	/**
	 * Mute or unmute the audio output device
	 *
	 * @param bIsMuted set to true to mute the device or false to unmute
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	void SetAudioOutputDeviceMuted(bool bIsMuted);

	/**
	 * Is the input device muted?
	 *
	 * @return true if the input device is muted
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	bool GetAudioInputDeviceMuted() const;

	/**
	 * Is the output device muted?
	 *
	 * @return true if the input device is muted
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	bool GetAudioOutputDeviceMuted() const;

	/**
	 * Get a list of available audio input devices
	 *
	 * @return Array of audio input devices
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	TArray<FEOSVoiceChatDeviceInfo> GetAvailableInputDeviceInfos() const;


	/**
	 * Get a list of available audio output devices
	 *
	 * @return Array of audio output devices
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	TArray<FEOSVoiceChatDeviceInfo> GetAvailableOutputDeviceInfos() const;

	/**
	 * Set the audio input device to use
	 *
	 * @param InputDeviceId Device Id from GetAvailableInputDeviceInfos. If empty, will use the default input device
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	void SetInputDeviceId(FString InputDeviceId);

	/**
	 * Set the audio output device to use
	 *
	 * @param OutputDeviceId Device Id from GetAvailableOutputDeviceInfos. If empty, will use the default output device
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	void SetOutputDeviceId(FString OutputDeviceId);

	/**
	 * Get the device info of the audio input device that is being used
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	FEOSVoiceChatDeviceInfo GetInputDeviceInfo() const;

	/**
	 * Get the device info of the audio output device that is being used
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	FEOSVoiceChatDeviceInfo GetOutputDeviceInfo() const;

	/**
	 * Get the device info of the default audio input device
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	FEOSVoiceChatDeviceInfo GetDefaultInputDeviceInfo() const;

	/**
	 * Get the device info of the default audio output device
	 */
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	FEOSVoiceChatDeviceInfo GetDefaultOutputDeviceInfo() const;

	/**
	* Generate Join token.
	*/
	UFUNCTION(BlueprintCallable, Category = "EOSCoreVoice|User")
	void GetJoinToken(FString ClientId, FString ClientSecret, FString DeploymentId, FString RoomName, TArray<FRequestParticipantData> Participants, const FOnSomeCallback& Callback);

	/*
	 * Try getting the Client Id from DefaultEngine.ini 
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EOSCoreVoice|User")
	static FString GetClientId();
	/*
	* Try getting the Client Secret from DefaultEngine.ini 
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EOSCoreVoice|User")
	static FString GetClientSecret();
	/*
	* Try getting the Deployment Id from DefaultEngine.ini 
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "EOSCoreVoice|User")
	static FString GetDeploymentId();
	

private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		DELEGATE HANDLES
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	FDelegateHandle m_OnEOSVoiceChatAvailableAudioDevicesChanged;
	FDelegateHandle m_OnEOSVoiceChatConnected;
	FDelegateHandle m_OnEOSVoiceChatDisconnected;
	FDelegateHandle m_OnEOSVoiceChatReconnected;
	FDelegateHandle m_OnVoiceChatLoggedIn;
	FDelegateHandle m_OnVoiceChatLoggedOut;

	FDelegateHandle m_OnVoiceChatChannelJoined;
	FDelegateHandle m_OnVoiceChatChannelExited;
	FDelegateHandle m_OnVoiceChatCallStatsUpdated;

	FDelegateHandle m_OnVoiceChatPlayerAdded;
	FDelegateHandle m_OnVoiceCHatPlayerRemoved;

	FDelegateHandle m_OnEOSVoiceChatPlayerTalkingUpdated;
	FDelegateHandle m_OnVoiceChatPlayerMuteUpdated;
	FDelegateHandle m_OnEOSVoiceChatPlayerVolumeUpdated;

private:
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	//		CALLBACK FUNCTIONS
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //
	void OnVoiceChatAvailableAudioDevicesChanged();
	void OnVoiceChatConnected();
	void OnVoiceChatDisconnected(const FVoiceChatResult& Result);
	void OnVoiceChatReconnected();
	void OnVoiceChatLoggedIn(const FString& PlayerName);
	void OnVoiceChatLoggedOut(const FString& PlayerName);
	void OnVoiceChatChannelJoined(const FString& PlayerName);
	void OnVoiceChatChannelExited(const FString& ChannelName, const FVoiceChatResult& Reason);
	void OnVoiceChatCallStatsUpdated(const FVoiceChatCallStats& CallStats);
	void OnVoiceChatPlayerRemoved(const FString& ChannelName, const FString& PlayerName);
	void OnVoiceChatPlayerAdded(const FString& ChannelName, const FString& PlayerName);
	void OnVoiceChatPlayerTalkingUpdated(const FString& ChannelName, const FString& PlayerName, bool bIsTalking);
	void OnVoiceChatPlayerMuteUpdated(const FString& ChannelName, const FString& PlayerName, bool bIsMuted);
	void OnVoiceChatPlayerVolumeUpdated(const FString& ChannelName, const FString& PlayerName, float Volume);
};
