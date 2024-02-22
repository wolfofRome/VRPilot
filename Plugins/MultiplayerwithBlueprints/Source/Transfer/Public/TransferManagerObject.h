/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/LatentActionManager.h"

#include "S3ClientObject.h"

#if WITH_TRANSFERCLIENTSDK && WITH_CORE

#include "aws/core/utils/memory/stl/AWSAllocator.h"
#include "aws/transfer/TransferManager.h"

#endif

#include "TransferHandle.h"

#include "TransferManagerObject.generated.h"

/**
* Configuration for use with TransferManager. The data here will be copied directly to TransferManager.
*/
UCLASS(Blueprintable)
class TRANSFER_API  UTransferManagerConfiguration : public UObject {
    GENERATED_BODY()

public:
    ~UTransferManagerConfiguration();

    /**
    * S3 Client to use for transfers. You are responsible for setting this.
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer", Meta = (ExposeOnSpawn = true))
    US3ClientObject *s3Client;

    /**
    * When true, TransferManager will calculate the MD5 digest of the content being uploaded.
    * The digest is sent to S3 via an HTTP header enabling the service to perform integrity checks.
    * This option is disabled by default.
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer", Meta = (ExposeOnSpawn = true))
    bool computeContentMD5 = false;

    /**
    * If you have special arguments you want passed to our put object calls, put them here. We will copy the template for each put object call overriding the body stream, bucket, and key. If object metadata is passed through, we will override that as well.
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer", Meta = (ExposeOnSpawn = true))
    FPutObjectRequest putObjectTemplate;

    /**
     * If you have special arguments you want passed to our get object calls, put them here. We will copy the template for each put object call overriding the body stream, bucket, and key. If object metadata is passed through, we will override that as well.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer", Meta = (ExposeOnSpawn = true))
    FGetObjectRequest getObjectTemplate;

    /**
     * If you have special arguments you want passed to our create multipart upload calls, put them here. We will copy the template for each call overriding the body stream, bucket, and key. If object metadata is passed through, we will override that as well.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer", Meta = (ExposeOnSpawn = true))
    FCreateMultipartUploadRequest createMultipartUploadTemplate;

    /**
     * If you have special arguments you want passed to our upload part calls, put them here. We will copy the template for each call overriding the body stream, bucket, and key. If object metadata is passed through, we will override that as well.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer", Meta = (ExposeOnSpawn = true))
    FUploadPartRequest uploadPartTemplate;

    /**
     * Maximum size of the working buffers to use. This is not the same thing as max heap size for your process. This is the maximum amount of memory we will allocate for all transfer buffers. default is 50MB.
     * If you are using Aws::Utils::Threading::PooledThreadExecutor for transferExecutor, this size should be greater than bufferSize * poolSize.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer", Meta = (ExposeOnSpawn = true))
    int64 transferBufferMaxHeapSize = 52428800;

    /**
     * Defaults to 5MB. If you are uploading large files,  (larger than 50GB, this needs to be specified to be something larger than 5MB. Also keep in mind that you may need to increase your max heap size if this is something you plan on increasing.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer", Meta = (ExposeOnSpawn = true))
    int64 bufferSize = 5242880;

    /**
     * Callback to receive progress updates for uploads.
     */
    UFUNCTION(BlueprintNativeEvent, Category = "Transfer")
    void uploadProgressCallback(const FConstTransferHandle transferHandle) const;

    /**
     * Callback to receive progress updates for downloads.
     */
    UFUNCTION(BlueprintNativeEvent, Category = "Transfer")
    void downloadProgressCallback(const FConstTransferHandle transferHandle) const;

    /**
     * Callback to receive updates on the status of the transfer.
     */
    UFUNCTION(BlueprintNativeEvent, Category = "Transfer")
    void transferStatusUpdatedCallback(const FConstTransferHandle transferHandle) const;

    /**
     * Callback to receive initiated transfers for the directory operations.
     */
    UFUNCTION(BlueprintNativeEvent, Category = "Transfer")
    void transferInitiatedCallback(const FConstTransferHandle transferHandle) const;

    /**
     * Callback to receive all errors that are thrown over the course of a transfer.
     */
    UFUNCTION(BlueprintNativeEvent, Category = "Transfer")
    void errorCallback(const FConstTransferHandle transferHandle, const ES3Error error) const;

    /**
     * To support Customer Access Log Information when access S3.
     * https://docs.aws.amazon.com/AmazonS3/latest/dev/LogFormat.html
     * Note: query string key not started with "x-" will be filtered out.
     * key/val of map entries will be key/val of query strings.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer", Meta = (ExposeOnSpawn = true))
    TMap<FString, FString> customizedAccessLogTag;

    /**
    * max number of threads executors in thread pool.
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Transfer", Meta = (ExposeOnSpawn = true))
    int maxThreadExecutor = 4;

#if WITH_S3CLIENTSDK && WITH_TRANSFERCLIENTSDK && WITH_CORE
    std::shared_ptr<Aws::Utils::Threading::Executor> executor;

    Aws::Transfer::TransferManagerConfiguration toAWS();
#endif
};

/**
* This is a utility around Amazon Simple Storage Service. It can Upload large files via parts in parallel, Upload files less than 5MB in single PutObject, and download files via GetObject,
*  If a transfer fails, it can be retried for an upload. For a download, there is nothing to retry in case of failure. Just download it again. You can also abort any in progress transfers.
*  The key interface for controlling and knowing the status of your upload is the TransferHandle. An instance of TransferHandle is returned from each of the public functions in this interface.
*  Keep a reference to the pointer. Each of the callbacks will also pass the handle that has received an update. None of the public methods in this interface block.
*/
UCLASS(BlueprintType)
class TRANSFER_API UTransferManagerObject : public UObject {
    GENERATED_BODY()

public:
	UPROPERTY()
    UTransferManagerConfiguration *config;

#if WITH_TRANSFERCLIENTSDK && WITH_CORE
    std::shared_ptr<Aws::Transfer::TransferManager> awsTransferManager;
#endif
	virtual void BeginDestroy() override;
	virtual bool IsReadyForFinishDestroy() override;

    ~UTransferManagerObject();

    /**
    * public static UTransferManagerObject::CreateTransferManagerObject
    * Create a new TransferManager instance intialized with config.
    * @param config [FTransferManagerConfiguration] .
    * @return [UTransferManagerObject*] Returns UTransferManagerObject*.
    **/
    UFUNCTION(BlueprintCallable, Category = "S3 Encryption Client")
    static UTransferManagerObject *
    CreateTransferManagerObject(UTransferManagerConfiguration *transferManagerConfiguration);

    /**
     * Uploads a file via filename, to bucketName/keyName in S3. contentType and metadata will be added to the object. If the object is larger than the configured bufferSize, then a multi-part upload will be performed.
     */
    UFUNCTION(BlueprintCallable,
              meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
              Category = "Transfer")
    UTransferHandle* UploadFile (
            UObject *WorldContextObject,
            const FString& fileName,
            const FString& bucketName,
            const FString& keyName,
            const FString& contentType,
            const TMap<FString, FString>& metadata,
            struct FLatentActionInfo LatentInfo
    );

    /**
     * Uploads a file via filename, to bucketName/keyName in S3. contentType and metadata will be added to the object. If the object is larger than the configured bufferSize, then a multi-part upload will be performed.
     */
    UFUNCTION(BlueprintCallable,
              meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
              Category = "Transfer")
    UTransferHandle* DownloadFile (
            UObject *WorldContextObject,
            const FString& bucketName,
            const FString& keyName,
            const FString& writeToFile,
            const FDownloadConfiguration& downloadConfig,
            struct FLatentActionInfo LatentInfo
    );

    /**
     * Retry an download that failed from a previous DownloadFile operation. If a multi-part download was used, only the failed parts will be re-fetched.
     */
    UFUNCTION(BlueprintCallable,
              meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
              Category = "Transfer")
    UTransferHandle* RetryDownload (
            UObject *WorldContextObject,
            UTransferHandle* retryHandle,
            struct FLatentActionInfo LatentInfo
    );

    /**
     * Retry an upload that failed from a previous UploadFile operation. If a multi-part upload was used, only the failed parts will be re-sent.
     */
    UFUNCTION(BlueprintCallable,
              meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
              Category = "Transfer")
    UTransferHandle* RetryUpload (
            UObject *WorldContextObject,
            const FString& fileName,
            UTransferHandle* retryHandle,
            struct FLatentActionInfo LatentInfo
    );

    /**
     * By default, multi-part uploads will remain in a FAILED state if they fail, or a CANCELED state if they were canceled. Leaving failed uploads around still costs the owner of the bucket money. If you know you will not be retrying the request, abort the request after canceling it or if it fails and you don't intend to retry it.
     */
    UFUNCTION(BlueprintCallable, Category = "Transfer")
    void AbortMultipartUpload (
            UTransferHandle* inProgressHandle
    );

    /**
     * Uploads entire contents of directory to Amazon S3 bucket and stores them in a directory starting at prefix. This is an asynchronous method. You will receive notifications that an upload has started via the transferInitiatedCallback callback function in your configuration. If you do not set this callback, then you will not be able to handle the file transfers.
     *
     * directory: the absolute directory on disk to upload
     * bucketName: the name of the S3 bucket to upload to
     * prefix: the prefix to put on all objects uploaded (e.g. put them in x directory in the bucket).
     */
    UFUNCTION(BlueprintCallable, Category = "Transfer")
    void UploadDirectory (
            const FString& directory,
            const FString& bucketName,
            const FString& prefix,
            const TMap<FString, FString>& metadata
    );

    /**
    * Downloads entire contents of an Amazon S3 bucket starting at prefix stores them in a directory (not including the prefix). This is an asynchronous method. You will receive notifications that a download has started via the transferInitiatedCallback callback function in your configuration. If you do not set this callback, then you will not be able to handle the file transfers. If an error occurs prior to the transfer being initiated (e.g. list objects fails, then an error will be passed through the errorCallback).
    *
    * directory: the absolute directory on disk to download to
    * bucketName: the name of the S3 bucket to upload to
    * prefix: the prefix in the bucket to use as the root directory (e.g. download all objects at x prefix in S3 and then store them starting in directory with the prefix stripped out).
    */
    UFUNCTION(BlueprintCallable, Category = "Transfer")
    void DownloadToDirectory (
            const FString& directory,
            const FString& bucketName,
            const FString& prefix
    );
};
