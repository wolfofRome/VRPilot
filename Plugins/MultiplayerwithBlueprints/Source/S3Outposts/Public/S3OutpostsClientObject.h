/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/LatentActionManager.h"

#include "Auth/AWSCoreCredentials.h"
#include "Client/AWSClientConfiguration.h"

#include "S3OutpostsError.h"

#include "Model/AWSS3OutpostsCreateEndpointRequest.h"
#include "Model/AWSS3OutpostsDeleteEndpointRequest.h"
#include "Model/AWSS3OutpostsListEndpointsRequest.h"
#include "Model/AWSS3OutpostsListSharedEndpointsRequest.h"
#include "Model/AWSS3OutpostsCreateEndpointResult.h"
#include "Model/AWSS3OutpostsListEndpointsResult.h"
#include "Model/AWSS3OutpostsListSharedEndpointsResult.h"
#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE

#include "aws/s3outposts/S3OutpostsClient.h"

#endif

#include "S3OutpostsClientObject.generated.h"

/**
*  <p>Amazon S3 on Outposts provides access to S3 on Outposts operations.</p>
**/
UCLASS(BlueprintType)
class S3OUTPOSTS_API US3OutpostsClientObject : public UObject {
    GENERATED_BODY()

public:
#if WITH_S3OUTPOSTSCLIENTSDK && WITH_CORE
    Aws::S3Outposts::S3OutpostsClient *awsS3OutpostsClient;
#endif

    /**
    * public static US3OutpostsClientObject::CreateS3OutpostsObject
    * Creates a S3OutpostsObject. This function must be called first before accessing any GameLift client functions.
    * @param credentials [FAWSCredentials] .
    * @param clientConfiguration [FClientConfiguration] .
    * @return [US3OutpostsClient*] Returns US3OutpostsClient*.
    **/
    UFUNCTION(BlueprintCallable, Category = "S3Outposts Client")
    static US3OutpostsClientObject *
    CreateS3OutpostsObject(const FAWSCredentials &credentials, const FAWSClientConfiguration &clientConfiguration);

    /**
    * <p>Creates an endpoint and associates it with the specified Outpost.</p> <note> <p>It can take up to 5 minutes for this action to finish.</p> </note> <p/> <p>Related actions include:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_s3outposts_DeleteEndpoint.html">DeleteEndpoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_s3outposts_ListEndpoints.html">ListEndpoints</a> </p> </li> </ul>
    * @param
    * @param createEndpointRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Outposts Client")
    void CreateEndpoint (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3OutpostsCreateEndpointRequest createEndpointRequest,
        FAWSS3OutpostsCreateEndpointResult &createEndpointResult,
        ES3OutpostsError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Deletes an endpoint.</p> <note> <p>It can take up to 5 minutes for this action to finish.</p> </note> <p/> <p>Related actions include:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_s3outposts_CreateEndpoint.html">CreateEndpoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_s3outposts_ListEndpoints.html">ListEndpoints</a> </p> </li> </ul>
    * @param
    * @param deleteEndpointRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Outposts Client")
    void DeleteEndpoint (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3OutpostsDeleteEndpointRequest deleteEndpointRequest,
        ES3OutpostsError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Lists endpoints associated with the specified Outpost. </p> <p>Related actions include:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_s3outposts_CreateEndpoint.html">CreateEndpoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_s3outposts_DeleteEndpoint.html">DeleteEndpoint</a> </p> </li> </ul>
    * @param
    * @param listEndpointsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Outposts Client")
    void ListEndpoints (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3OutpostsListEndpointsRequest listEndpointsRequest,
        FAWSS3OutpostsListEndpointsResult &listEndpointsResult,
        ES3OutpostsError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Lists all endpoints associated with an Outpost that has been shared by Amazon Web Services Resource Access Manager (RAM).</p> <p>Related actions include:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_s3outposts_CreateEndpoint.html">CreateEndpoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_s3outposts_DeleteEndpoint.html">DeleteEndpoint</a> </p> </li> </ul>
    * @param
    * @param listSharedEndpointsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Outposts Client")
    void ListSharedEndpoints (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3OutpostsListSharedEndpointsRequest listSharedEndpointsRequest,
        FAWSS3OutpostsListSharedEndpointsResult &listSharedEndpointsResult,
        ES3OutpostsError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
};
