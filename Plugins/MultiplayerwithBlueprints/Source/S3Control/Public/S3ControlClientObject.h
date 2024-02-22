/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/LatentActionManager.h"

#include "Auth/AWSCoreCredentials.h"
#include "Client/AWSClientConfiguration.h"

#include "S3ControlError.h"

#include "Model/CreateAccessPointRequest.h"
#include "Model/AWSS3ControlCreateAccessPointForObjectLambdaRequest.h"
#include "Model/AWSS3ControlCreateBucketRequest.h"
#include "Model/CreateJobRequest.h"
#include "Model/AWSS3ControlCreateMultiRegionAccessPointRequest.h"
#include "Model/DeleteAccessPointRequest.h"
#include "Model/AWSS3ControlDeleteAccessPointForObjectLambdaRequest.h"
#include "Model/DeleteAccessPointPolicyRequest.h"
#include "Model/AWSS3ControlDeleteAccessPointPolicyForObjectLambdaRequest.h"
#include "Model/AWSS3ControlDeleteBucketRequest.h"
#include "Model/AWSS3ControlDeleteBucketLifecycleConfigurationRequest.h"
#include "Model/AWSS3ControlDeleteBucketPolicyRequest.h"
#include "Model/AWSS3ControlDeleteBucketTaggingRequest.h"
#include "Model/DeleteJobTaggingRequest.h"
#include "Model/AWSS3ControlDeleteMultiRegionAccessPointRequest.h"
#include "Model/S3ControlDeletePublicAccessBlockRequest.h"
#include "Model/AWSS3ControlDeleteStorageLensConfigurationRequest.h"
#include "Model/AWSS3ControlDeleteStorageLensConfigurationTaggingRequest.h"
#include "Model/DescribeJobRequest.h"
#include "Model/AWSS3ControlDescribeMultiRegionAccessPointOperationRequest.h"
#include "Model/GetAccessPointRequest.h"
#include "Model/AWSS3ControlGetAccessPointConfigurationForObjectLambdaRequest.h"
#include "Model/AWSS3ControlGetAccessPointForObjectLambdaRequest.h"
#include "Model/GetAccessPointPolicyRequest.h"
#include "Model/AWSS3ControlGetAccessPointPolicyForObjectLambdaRequest.h"
#include "Model/GetAccessPointPolicyStatusRequest.h"
#include "Model/AWSS3ControlGetAccessPointPolicyStatusForObjectLambdaRequest.h"
#include "Model/AWSS3ControlGetBucketRequest.h"
#include "Model/AWSS3ControlGetBucketLifecycleConfigurationRequest.h"
#include "Model/AWSS3ControlGetBucketPolicyRequest.h"
#include "Model/AWSS3ControlGetBucketTaggingRequest.h"
#include "Model/AWSS3ControlGetBucketVersioningRequest.h"
#include "Model/GetJobTaggingRequest.h"
#include "Model/AWSS3ControlGetMultiRegionAccessPointRequest.h"
#include "Model/AWSS3ControlGetMultiRegionAccessPointPolicyRequest.h"
#include "Model/AWSS3ControlGetMultiRegionAccessPointPolicyStatusRequest.h"
#include "Model/AWSS3ControlGetMultiRegionAccessPointRoutesRequest.h"
#include "Model/S3ControlGetPublicAccessBlockRequest.h"
#include "Model/AWSS3ControlGetStorageLensConfigurationRequest.h"
#include "Model/AWSS3ControlGetStorageLensConfigurationTaggingRequest.h"
#include "Model/ListAccessPointsRequest.h"
#include "Model/AWSS3ControlListAccessPointsForObjectLambdaRequest.h"
#include "Model/ListJobsRequest.h"
#include "Model/AWSS3ControlListMultiRegionAccessPointsRequest.h"
#include "Model/AWSS3ControlListRegionalBucketsRequest.h"
#include "Model/AWSS3ControlListStorageLensConfigurationsRequest.h"
#include "Model/AWSS3ControlPutAccessPointConfigurationForObjectLambdaRequest.h"
#include "Model/PutAccessPointPolicyRequest.h"
#include "Model/AWSS3ControlPutAccessPointPolicyForObjectLambdaRequest.h"
#include "Model/AWSS3ControlPutBucketLifecycleConfigurationRequest.h"
#include "Model/AWSS3ControlPutBucketPolicyRequest.h"
#include "Model/AWSS3ControlPutBucketTaggingRequest.h"
#include "Model/AWSS3ControlPutBucketVersioningRequest.h"
#include "Model/PutJobTaggingRequest.h"
#include "Model/AWSS3ControlPutMultiRegionAccessPointPolicyRequest.h"
#include "Model/S3ControlPutPublicAccessBlockRequest.h"
#include "Model/AWSS3ControlPutStorageLensConfigurationRequest.h"
#include "Model/AWSS3ControlPutStorageLensConfigurationTaggingRequest.h"
#include "Model/AWSS3ControlSubmitMultiRegionAccessPointRoutesRequest.h"
#include "Model/UpdateJobPriorityRequest.h"
#include "Model/UpdateJobStatusRequest.h"

#include "Model/AWSS3ControlCreateAccessPointResult.h"
#include "Model/AWSS3ControlCreateAccessPointForObjectLambdaResult.h"
#include "Model/AWSS3ControlCreateBucketResult.h"
#include "Model/CreateJobResult.h"
#include "Model/AWSS3ControlCreateMultiRegionAccessPointResult.h"
#include "Model/DeleteJobTaggingResult.h"
#include "Model/AWSS3ControlDeleteMultiRegionAccessPointResult.h"
#include "Model/AWSS3ControlDeleteStorageLensConfigurationTaggingResult.h"
#include "Model/DescribeJobResult.h"
#include "Model/AWSS3ControlDescribeMultiRegionAccessPointOperationResult.h"
#include "Model/GetAccessPointResult.h"
#include "Model/AWSS3ControlGetAccessPointConfigurationForObjectLambdaResult.h"
#include "Model/AWSS3ControlGetAccessPointForObjectLambdaResult.h"
#include "Model/GetAccessPointPolicyResult.h"
#include "Model/AWSS3ControlGetAccessPointPolicyForObjectLambdaResult.h"
#include "Model/GetAccessPointPolicyStatusResult.h"
#include "Model/AWSS3ControlGetAccessPointPolicyStatusForObjectLambdaResult.h"
#include "Model/AWSS3ControlGetBucketResult.h"
#include "Model/AWSS3ControlGetBucketLifecycleConfigurationResult.h"
#include "Model/AWSS3ControlGetBucketPolicyResult.h"
#include "Model/AWSS3ControlGetBucketTaggingResult.h"
#include "Model/AWSS3ControlGetBucketVersioningResult.h"
#include "Model/GetJobTaggingResult.h"
#include "Model/AWSS3ControlGetMultiRegionAccessPointResult.h"
#include "Model/AWSS3ControlGetMultiRegionAccessPointPolicyResult.h"
#include "Model/AWSS3ControlGetMultiRegionAccessPointPolicyStatusResult.h"
#include "Model/AWSS3ControlGetMultiRegionAccessPointRoutesResult.h"
#include "Model/S3ControlGetPublicAccessBlockResult.h"
#include "Model/AWSS3ControlGetStorageLensConfigurationResult.h"
#include "Model/AWSS3ControlGetStorageLensConfigurationTaggingResult.h"
#include "Model/ListAccessPointsResult.h"
#include "Model/AWSS3ControlListAccessPointsForObjectLambdaResult.h"
#include "Model/ListJobsResult.h"
#include "Model/AWSS3ControlListMultiRegionAccessPointsResult.h"
#include "Model/AWSS3ControlListRegionalBucketsResult.h"
#include "Model/AWSS3ControlListStorageLensConfigurationsResult.h"
#include "Model/PutJobTaggingResult.h"
#include "Model/AWSS3ControlPutMultiRegionAccessPointPolicyResult.h"
#include "Model/AWSS3ControlPutStorageLensConfigurationTaggingResult.h"
#include "Model/AWSS3ControlSubmitMultiRegionAccessPointRoutesResult.h"
#include "Model/UpdateJobPriorityResult.h"
#include "Model/UpdateJobStatusResult.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/S3ControlClient.h"

#endif

#include "S3ControlClientObject.generated.h"

/**
*  <p> AWS S3 Control provides access to Amazon S3 control plane operations. </p>
**/
UCLASS(BlueprintType)
class S3CONTROL_API US3ControlClientObject : public UObject {
    GENERATED_BODY()

public:
#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
    Aws::S3Control::S3ControlClient *awsS3ControlClient;
#endif

    /**
    * public static US3ControlClientObject::CreateS3ControlObject
    * Creates a S3ControlObject. This function must be called first before accessing any S3Control client functions.
    * @param credentials [FAWSCredentials] .
    * @param clientConfiguration [FClientConfiguration] .
    * @return [US3ControlClient*] Returns US3ControlClient*.
    **/
    UFUNCTION(BlueprintCallable, Category = "S3Control Client")
    static US3ControlClientObject *
    CreateS3ControlObject(const FAWSCredentials &credentials, const FAWSClientConfiguration &clientConfiguration);

    /**
    * <p>Creates an access point and associates it with the specified bucket. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/access-points.html">Managing Data Access with Amazon S3 Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p/> <note> <p>S3 on Outposts only supports VPC-style access points. </p> <p>For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html"> Accessing Amazon S3 on Outposts using virtual private cloud (VPC) only access points</a> in the <i>Amazon S3 User Guide</i>.</p> </note> <p>All Amazon S3 on Outposts REST API requests for this action require an additional parameter of <code>x-amz-outpost-id</code> to be passed with the request. In addition, you must use an S3 on Outposts endpoint hostname prefix instead of <code>s3-control</code>. For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and the <code>x-amz-outpost-id</code> derived by using the access point ARN, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateAccessPoint.html#API_control_CreateAccessPoint_Examples">Examples</a> section.</p> <p/> <p>The following actions are related to <code>CreateAccessPoint</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetAccessPoint.html">GetAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteAccessPoint.html">DeleteAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_ListAccessPoints.html">ListAccessPoints</a> </p> </li> </ul>
    * @param
    * @param createAccessPointRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void CreateAccessPoint (
        UObject *WorldContextObject,
        bool &success,
        FCreateAccessPointRequest createAccessPointRequest,
        FAWSS3ControlCreateAccessPointResult &createAccessPointResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Creates an Object Lambda Access Point. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/transforming-objects.html">Transforming objects with Object Lambda Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>The following actions are related to <code>CreateAccessPointForObjectLambda</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteAccessPointForObjectLambda.html">DeleteAccessPointForObjectLambda</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetAccessPointForObjectLambda.html">GetAccessPointForObjectLambda</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_ListAccessPointsForObjectLambda.html">ListAccessPointsForObjectLambda</a> </p> </li> </ul>
    * @param
    * @param createAccessPointForObjectLambdaRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void CreateAccessPointForObjectLambda (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlCreateAccessPointForObjectLambdaRequest createAccessPointForObjectLambdaRequest,
        FAWSS3ControlCreateAccessPointForObjectLambdaResult &createAccessPointForObjectLambdaResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <note> <p>This action creates an Amazon S3 on Outposts bucket. To create an S3 bucket, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_CreateBucket.html">Create Bucket</a> in the <i>Amazon S3 API Reference</i>. </p> </note> <p>Creates a new Outposts bucket. By creating the bucket, you become the bucket owner. To create an Outposts bucket, you must have S3 on Outposts. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using Amazon S3 on Outposts</a> in <i>Amazon S3 User Guide</i>.</p> <p>Not every string is an acceptable bucket name. For information on bucket naming restrictions, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/BucketRestrictions.html#bucketnamingrules">Working with Amazon S3 Buckets</a>.</p> <p>S3 on Outposts buckets support:</p> <ul> <li> <p>Tags</p> </li> <li> <p>LifecycleConfigurations for deleting expired objects</p> </li> </ul> <p>For a complete list of restrictions and Amazon S3 feature limitations on S3 on Outposts, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3OnOutpostsRestrictionsLimitations.html"> Amazon S3 on Outposts Restrictions and Limitations</a>.</p> <p>For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and <code>x-amz-outpost-id</code> in your API request, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateBucket.html#API_control_CreateBucket_Examples">Examples</a> section.</p> <p>The following actions are related to <code>CreateBucket</code> for Amazon S3 on Outposts:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_PutObject.html">PutObject</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetBucket.html">GetBucket</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteBucket.html">DeleteBucket</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateAccessPoint.html">CreateAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutAccessPointPolicy.html">PutAccessPointPolicy</a> </p> </li> </ul>
    * @param
    * @param createBucketRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void CreateBucket (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlCreateBucketRequest createBucketRequest,
        FAWSS3ControlCreateBucketResult &createBucketResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>You can use S3 Batch Operations to perform large-scale batch actions on Amazon S3 objects. Batch Operations can run a single action on lists of Amazon S3 objects that you specify. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/batch-ops.html">S3 Batch Operations</a> in the <i>Amazon S3 User Guide</i>.</p> <p>This action creates a S3 Batch Operations job.</p> <p/> <p>Related actions include:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DescribeJob.html">DescribeJob</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_ListJobs.html">ListJobs</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_UpdateJobPriority.html">UpdateJobPriority</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_UpdateJobStatus.html">UpdateJobStatus</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_JobOperation.html">JobOperation</a> </p> </li> </ul>
    * @param
    * @param createJobRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void CreateJob (
        UObject *WorldContextObject,
        bool &success,
        FCreateJobRequest createJobRequest,
        FCreateJobResult &createJobResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Creates a Multi-Region Access Point and associates it with the specified buckets. For more information about creating Multi-Region Access Points, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/CreatingMultiRegionAccessPoints.html">Creating Multi-Region Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>This action will always be routed to the US West (Oregon) Region. For more information about the restrictions around managing Multi-Region Access Points, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/ManagingMultiRegionAccessPoints.html">Managing Multi-Region Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>This request is asynchronous, meaning that you might receive a response before the command has completed. When this request provides a response, it provides a token that you can use to monitor the status of the request with <code>DescribeMultiRegionAccessPointOperation</code>.</p> <p>The following actions are related to <code>CreateMultiRegionAccessPoint</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteMultiRegionAccessPoint.html">DeleteMultiRegionAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DescribeMultiRegionAccessPointOperation.html">DescribeMultiRegionAccessPointOperation</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetMultiRegionAccessPoint.html">GetMultiRegionAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_ListMultiRegionAccessPoints.html">ListMultiRegionAccessPoints</a> </p> </li> </ul>
    * @param
    * @param createMultiRegionAccessPointRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void CreateMultiRegionAccessPoint (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlCreateMultiRegionAccessPointRequest createMultiRegionAccessPointRequest,
        FAWSS3ControlCreateMultiRegionAccessPointResult &createMultiRegionAccessPointResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Deletes the specified access point.</p> <p>All Amazon S3 on Outposts REST API requests for this action require an additional parameter of <code>x-amz-outpost-id</code> to be passed with the request. In addition, you must use an S3 on Outposts endpoint hostname prefix instead of <code>s3-control</code>. For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and the <code>x-amz-outpost-id</code> derived by using the access point ARN, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteAccessPoint.html#API_control_DeleteAccessPoint_Examples">Examples</a> section.</p> <p>The following actions are related to <code>DeleteAccessPoint</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateAccessPoint.html">CreateAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetAccessPoint.html">GetAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_ListAccessPoints.html">ListAccessPoints</a> </p> </li> </ul>
    * @param
    * @param deleteAccessPointRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void DeleteAccessPoint (
        UObject *WorldContextObject,
        bool &success,
        FDeleteAccessPointRequest deleteAccessPointRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Deletes the specified Object Lambda Access Point.</p> <p>The following actions are related to <code>DeleteAccessPointForObjectLambda</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateAccessPointForObjectLambda.html">CreateAccessPointForObjectLambda</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetAccessPointForObjectLambda.html">GetAccessPointForObjectLambda</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_ListAccessPointsForObjectLambda.html">ListAccessPointsForObjectLambda</a> </p> </li> </ul>
    * @param
    * @param deleteAccessPointForObjectLambdaRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void DeleteAccessPointForObjectLambda (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlDeleteAccessPointForObjectLambdaRequest deleteAccessPointForObjectLambdaRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Deletes the access point policy for the specified access point.</p> <p/> <p>All Amazon S3 on Outposts REST API requests for this action require an additional parameter of <code>x-amz-outpost-id</code> to be passed with the request. In addition, you must use an S3 on Outposts endpoint hostname prefix instead of <code>s3-control</code>. For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and the <code>x-amz-outpost-id</code> derived by using the access point ARN, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteAccessPointPolicy.html#API_control_DeleteAccessPointPolicy_Examples">Examples</a> section.</p> <p>The following actions are related to <code>DeleteAccessPointPolicy</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutAccessPointPolicy.html">PutAccessPointPolicy</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetAccessPointPolicy.html">GetAccessPointPolicy</a> </p> </li> </ul>
    * @param
    * @param deleteAccessPointPolicyRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void DeleteAccessPointPolicy (
        UObject *WorldContextObject,
        bool &success,
        FDeleteAccessPointPolicyRequest deleteAccessPointPolicyRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Removes the resource policy for an Object Lambda Access Point.</p> <p>The following actions are related to <code>DeleteAccessPointPolicyForObjectLambda</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetAccessPointPolicyForObjectLambda.html">GetAccessPointPolicyForObjectLambda</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutAccessPointPolicyForObjectLambda.html">PutAccessPointPolicyForObjectLambda</a> </p> </li> </ul>
    * @param
    * @param deleteAccessPointPolicyForObjectLambdaRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void DeleteAccessPointPolicyForObjectLambda (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlDeleteAccessPointPolicyForObjectLambdaRequest deleteAccessPointPolicyForObjectLambdaRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <note> <p>This action deletes an Amazon S3 on Outposts bucket. To delete an S3 bucket, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_DeleteBucket.html">DeleteBucket</a> in the <i>Amazon S3 API Reference</i>. </p> </note> <p>Deletes the Amazon S3 on Outposts bucket. All objects (including all object versions and delete markers) in the bucket must be deleted before the bucket itself can be deleted. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using Amazon S3 on Outposts</a> in <i>Amazon S3 User Guide</i>.</p> <p>All Amazon S3 on Outposts REST API requests for this action require an additional parameter of <code>x-amz-outpost-id</code> to be passed with the request. In addition, you must use an S3 on Outposts endpoint hostname prefix instead of <code>s3-control</code>. For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and the <code>x-amz-outpost-id</code> derived by using the access point ARN, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteBucket.html#API_control_DeleteBucket_Examples">Examples</a> section.</p> <p class="title"> <b>Related Resources</b> </p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateBucket.html">CreateBucket</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetBucket.html">GetBucket</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_DeleteObject.html">DeleteObject</a> </p> </li> </ul>
    * @param
    * @param deleteBucketRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void DeleteBucket (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlDeleteBucketRequest deleteBucketRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <note> <p>This action deletes an Amazon S3 on Outposts bucket's lifecycle configuration. To delete an S3 bucket's lifecycle configuration, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_DeleteBucketLifecycle.html">DeleteBucketLifecycle</a> in the <i>Amazon S3 API Reference</i>. </p> </note> <p>Deletes the lifecycle configuration from the specified Outposts bucket. Amazon S3 on Outposts removes all the lifecycle configuration rules in the lifecycle subresource associated with the bucket. Your objects never expire, and Amazon S3 on Outposts no longer automatically deletes any objects on the basis of rules contained in the deleted lifecycle configuration. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using Amazon S3 on Outposts</a> in <i>Amazon S3 User Guide</i>.</p> <p>To use this action, you must have permission to perform the <code>s3-outposts:DeleteLifecycleConfiguration</code> action. By default, the bucket owner has this permission and the Outposts bucket owner can grant this permission to others.</p> <p>All Amazon S3 on Outposts REST API requests for this action require an additional parameter of <code>x-amz-outpost-id</code> to be passed with the request. In addition, you must use an S3 on Outposts endpoint hostname prefix instead of <code>s3-control</code>. For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and the <code>x-amz-outpost-id</code> derived by using the access point ARN, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteBucketLifecycleConfiguration.html#API_control_DeleteBucketLifecycleConfiguration_Examples">Examples</a> section.</p> <p>For more information about object expiration, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/intro-lifecycle-rules.html#intro-lifecycle-rules-actions">Elements to Describe Lifecycle Actions</a>.</p> <p>Related actions include:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutBucketLifecycleConfiguration.html">PutBucketLifecycleConfiguration</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetBucketLifecycleConfiguration.html">GetBucketLifecycleConfiguration</a> </p> </li> </ul>
    * @param
    * @param deleteBucketLifecycleConfigurationRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void DeleteBucketLifecycleConfiguration (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlDeleteBucketLifecycleConfigurationRequest deleteBucketLifecycleConfigurationRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <note> <p>This action deletes an Amazon S3 on Outposts bucket policy. To delete an S3 bucket policy, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_DeleteBucketPolicy.html">DeleteBucketPolicy</a> in the <i>Amazon S3 API Reference</i>. </p> </note> <p>This implementation of the DELETE action uses the policy subresource to delete the policy of a specified Amazon S3 on Outposts bucket. If you are using an identity other than the root user of the Amazon Web Services account that owns the bucket, the calling identity must have the <code>s3-outposts:DeleteBucketPolicy</code> permissions on the specified Outposts bucket and belong to the bucket owner's account to use this action. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using Amazon S3 on Outposts</a> in <i>Amazon S3 User Guide</i>.</p> <p>If you don't have <code>DeleteBucketPolicy</code> permissions, Amazon S3 returns a <code>403 Access Denied</code> error. If you have the correct permissions, but you're not using an identity that belongs to the bucket owner's account, Amazon S3 returns a <code>405 Method Not Allowed</code> error. </p> <important> <p>As a security precaution, the root user of the Amazon Web Services account that owns a bucket can always use this action, even if the policy explicitly denies the root user the ability to perform this action.</p> </important> <p>For more information about bucket policies, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/using-iam-policies.html">Using Bucket Policies and User Policies</a>. </p> <p>All Amazon S3 on Outposts REST API requests for this action require an additional parameter of <code>x-amz-outpost-id</code> to be passed with the request. In addition, you must use an S3 on Outposts endpoint hostname prefix instead of <code>s3-control</code>. For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and the <code>x-amz-outpost-id</code> derived by using the access point ARN, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteBucketPolicy.html#API_control_DeleteBucketPolicy_Examples">Examples</a> section.</p> <p>The following actions are related to <code>DeleteBucketPolicy</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetBucketPolicy.html">GetBucketPolicy</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutBucketPolicy.html">PutBucketPolicy</a> </p> </li> </ul>
    * @param
    * @param deleteBucketPolicyRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void DeleteBucketPolicy (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlDeleteBucketPolicyRequest deleteBucketPolicyRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <note> <p>This action deletes an Amazon S3 on Outposts bucket's tags. To delete an S3 bucket tags, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_DeleteBucketTagging.html">DeleteBucketTagging</a> in the <i>Amazon S3 API Reference</i>. </p> </note> <p>Deletes the tags from the Outposts bucket. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using Amazon S3 on Outposts</a> in <i>Amazon S3 User Guide</i>.</p> <p>To use this action, you must have permission to perform the <code>PutBucketTagging</code> action. By default, the bucket owner has this permission and can grant this permission to others. </p> <p>All Amazon S3 on Outposts REST API requests for this action require an additional parameter of <code>x-amz-outpost-id</code> to be passed with the request. In addition, you must use an S3 on Outposts endpoint hostname prefix instead of <code>s3-control</code>. For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and the <code>x-amz-outpost-id</code> derived by using the access point ARN, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteBucketTagging.html#API_control_DeleteBucketTagging_Examples">Examples</a> section.</p> <p>The following actions are related to <code>DeleteBucketTagging</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetBucketTagging.html">GetBucketTagging</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutBucketTagging.html">PutBucketTagging</a> </p> </li> </ul>
    * @param
    * @param deleteBucketTaggingRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void DeleteBucketTagging (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlDeleteBucketTaggingRequest deleteBucketTaggingRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Removes the entire tag set from the specified S3 Batch Operations job. To use the <code>DeleteJobTagging</code> operation, you must have permission to perform the <code>s3:DeleteJobTagging</code> action. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/batch-ops-managing-jobs.html#batch-ops-job-tags">Controlling access and labeling jobs using tags</a> in the <i>Amazon S3 User Guide</i>.</p> <p/> <p>Related actions include:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateJob.html">CreateJob</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetJobTagging.html">GetJobTagging</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutJobTagging.html">PutJobTagging</a> </p> </li> </ul>
    * @param
    * @param deleteJobTaggingRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void DeleteJobTagging (
        UObject *WorldContextObject,
        bool &success,
        FDeleteJobTaggingRequest deleteJobTaggingRequest,
        FDeleteJobTaggingResult &deleteJobTaggingResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Deletes a Multi-Region Access Point. This action does not delete the buckets associated with the Multi-Region Access Point, only the Multi-Region Access Point itself.</p> <p>This action will always be routed to the US West (Oregon) Region. For more information about the restrictions around managing Multi-Region Access Points, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/ManagingMultiRegionAccessPoints.html">Managing Multi-Region Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>This request is asynchronous, meaning that you might receive a response before the command has completed. When this request provides a response, it provides a token that you can use to monitor the status of the request with <code>DescribeMultiRegionAccessPointOperation</code>.</p> <p>The following actions are related to <code>DeleteMultiRegionAccessPoint</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateMultiRegionAccessPoint.html">CreateMultiRegionAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DescribeMultiRegionAccessPointOperation.html">DescribeMultiRegionAccessPointOperation</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetMultiRegionAccessPoint.html">GetMultiRegionAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_ListMultiRegionAccessPoints.html">ListMultiRegionAccessPoints</a> </p> </li> </ul>
    * @param
    * @param deleteMultiRegionAccessPointRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void DeleteMultiRegionAccessPoint (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlDeleteMultiRegionAccessPointRequest deleteMultiRegionAccessPointRequest,
        FAWSS3ControlDeleteMultiRegionAccessPointResult &deleteMultiRegionAccessPointResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Removes the <code>PublicAccessBlock</code> configuration for an Amazon Web Services account. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/access-control-block-public-access.html"> Using Amazon S3 block public access</a>.</p> <p>Related actions include:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetPublicAccessBlock.html">GetPublicAccessBlock</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutPublicAccessBlock.html">PutPublicAccessBlock</a> </p> </li> </ul>
    * @param
    * @param deletePublicAccessBlockRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void DeletePublicAccessBlock (
        UObject *WorldContextObject,
        bool &success,
        FS3ControlDeletePublicAccessBlockRequest deletePublicAccessBlockRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Deletes the Amazon S3 Storage Lens configuration. For more information about S3 Storage Lens, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage_lens.html">Assessing your storage activity and usage with Amazon S3 Storage Lens </a> in the <i>Amazon S3 User Guide</i>.</p> <note> <p>To use this action, you must have permission to perform the <code>s3:DeleteStorageLensConfiguration</code> action. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage_lens_iam_permissions.html">Setting permissions to use Amazon S3 Storage Lens</a> in the <i>Amazon S3 User Guide</i>.</p> </note>
    * @param
    * @param deleteStorageLensConfigurationRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void DeleteStorageLensConfiguration (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlDeleteStorageLensConfigurationRequest deleteStorageLensConfigurationRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Deletes the Amazon S3 Storage Lens configuration tags. For more information about S3 Storage Lens, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage_lens.html">Assessing your storage activity and usage with Amazon S3 Storage Lens </a> in the <i>Amazon S3 User Guide</i>.</p> <note> <p>To use this action, you must have permission to perform the <code>s3:DeleteStorageLensConfigurationTagging</code> action. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage_lens_iam_permissions.html">Setting permissions to use Amazon S3 Storage Lens</a> in the <i>Amazon S3 User Guide</i>.</p> </note>
    * @param
    * @param deleteStorageLensConfigurationTaggingRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void DeleteStorageLensConfigurationTagging (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlDeleteStorageLensConfigurationTaggingRequest deleteStorageLensConfigurationTaggingRequest,
        FAWSS3ControlDeleteStorageLensConfigurationTaggingResult &deleteStorageLensConfigurationTaggingResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Retrieves the configuration parameters and status for a Batch Operations job. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/batch-ops.html">S3 Batch Operations</a> in the <i>Amazon S3 User Guide</i>.</p> <p/> <p>Related actions include:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateJob.html">CreateJob</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_ListJobs.html">ListJobs</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_UpdateJobPriority.html">UpdateJobPriority</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_UpdateJobStatus.html">UpdateJobStatus</a> </p> </li> </ul>
    * @param
    * @param describeJobRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void DescribeJob (
        UObject *WorldContextObject,
        bool &success,
        FDescribeJobRequest describeJobRequest,
        FDescribeJobResult &describeJobResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Retrieves the status of an asynchronous request to manage a Multi-Region Access Point. For more information about managing Multi-Region Access Points and how asynchronous requests work, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/ManagingMultiRegionAccessPoints.html">Managing Multi-Region Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>The following actions are related to <code>GetMultiRegionAccessPoint</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateMultiRegionAccessPoint.html">CreateMultiRegionAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteMultiRegionAccessPoint.html">DeleteMultiRegionAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetMultiRegionAccessPoint.html">GetMultiRegionAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_ListMultiRegionAccessPoints.html">ListMultiRegionAccessPoints</a> </p> </li> </ul>
    * @param
    * @param describeMultiRegionAccessPointOperationRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void DescribeMultiRegionAccessPointOperation (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlDescribeMultiRegionAccessPointOperationRequest describeMultiRegionAccessPointOperationRequest,
        FAWSS3ControlDescribeMultiRegionAccessPointOperationResult &describeMultiRegionAccessPointOperationResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns configuration information about the specified access point.</p> <p/> <p>All Amazon S3 on Outposts REST API requests for this action require an additional parameter of <code>x-amz-outpost-id</code> to be passed with the request. In addition, you must use an S3 on Outposts endpoint hostname prefix instead of <code>s3-control</code>. For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and the <code>x-amz-outpost-id</code> derived by using the access point ARN, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetAccessPoint.html#API_control_GetAccessPoint_Examples">Examples</a> section.</p> <p>The following actions are related to <code>GetAccessPoint</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateAccessPoint.html">CreateAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteAccessPoint.html">DeleteAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_ListAccessPoints.html">ListAccessPoints</a> </p> </li> </ul>
    * @param
    * @param getAccessPointRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetAccessPoint (
        UObject *WorldContextObject,
        bool &success,
        FGetAccessPointRequest getAccessPointRequest,
        FGetAccessPointResult &getAccessPointResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns configuration for an Object Lambda Access Point.</p> <p>The following actions are related to <code>GetAccessPointConfigurationForObjectLambda</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutAccessPointConfigurationForObjectLambda.html">PutAccessPointConfigurationForObjectLambda</a> </p> </li> </ul>
    * @param
    * @param getAccessPointConfigurationForObjectLambdaRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetAccessPointConfigurationForObjectLambda (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlGetAccessPointConfigurationForObjectLambdaRequest getAccessPointConfigurationForObjectLambdaRequest,
        FAWSS3ControlGetAccessPointConfigurationForObjectLambdaResult &getAccessPointConfigurationForObjectLambdaResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns configuration information about the specified Object Lambda Access Point</p> <p>The following actions are related to <code>GetAccessPointForObjectLambda</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateAccessPointForObjectLambda.html">CreateAccessPointForObjectLambda</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteAccessPointForObjectLambda.html">DeleteAccessPointForObjectLambda</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_ListAccessPointsForObjectLambda.html">ListAccessPointsForObjectLambda</a> </p> </li> </ul>
    * @param
    * @param getAccessPointForObjectLambdaRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetAccessPointForObjectLambda (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlGetAccessPointForObjectLambdaRequest getAccessPointForObjectLambdaRequest,
        FAWSS3ControlGetAccessPointForObjectLambdaResult &getAccessPointForObjectLambdaResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns the access point policy associated with the specified access point.</p> <p>The following actions are related to <code>GetAccessPointPolicy</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutAccessPointPolicy.html">PutAccessPointPolicy</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteAccessPointPolicy.html">DeleteAccessPointPolicy</a> </p> </li> </ul>
    * @param
    * @param getAccessPointPolicyRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetAccessPointPolicy (
        UObject *WorldContextObject,
        bool &success,
        FGetAccessPointPolicyRequest getAccessPointPolicyRequest,
        FGetAccessPointPolicyResult &getAccessPointPolicyResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns the resource policy for an Object Lambda Access Point.</p> <p>The following actions are related to <code>GetAccessPointPolicyForObjectLambda</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteAccessPointPolicyForObjectLambda.html">DeleteAccessPointPolicyForObjectLambda</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutAccessPointPolicyForObjectLambda.html">PutAccessPointPolicyForObjectLambda</a> </p> </li> </ul>
    * @param
    * @param getAccessPointPolicyForObjectLambdaRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetAccessPointPolicyForObjectLambda (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlGetAccessPointPolicyForObjectLambdaRequest getAccessPointPolicyForObjectLambdaRequest,
        FAWSS3ControlGetAccessPointPolicyForObjectLambdaResult &getAccessPointPolicyForObjectLambdaResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Indicates whether the specified access point currently has a policy that allows public access. For more information about public access through access points, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/access-points.html">Managing Data Access with Amazon S3 access points</a> in the <i>Amazon S3 User Guide</i>.</p>
    * @param
    * @param getAccessPointPolicyStatusRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetAccessPointPolicyStatus (
        UObject *WorldContextObject,
        bool &success,
        FGetAccessPointPolicyStatusRequest getAccessPointPolicyStatusRequest,
        FGetAccessPointPolicyStatusResult &getAccessPointPolicyStatusResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns the status of the resource policy associated with an Object Lambda Access Point.</p>
    * @param
    * @param getAccessPointPolicyStatusForObjectLambdaRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetAccessPointPolicyStatusForObjectLambda (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlGetAccessPointPolicyStatusForObjectLambdaRequest getAccessPointPolicyStatusForObjectLambdaRequest,
        FAWSS3ControlGetAccessPointPolicyStatusForObjectLambdaResult &getAccessPointPolicyStatusForObjectLambdaResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Gets an Amazon S3 on Outposts bucket. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html"> Using Amazon S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p> <p>If you are using an identity other than the root user of the Amazon Web Services account that owns the Outposts bucket, the calling identity must have the <code>s3-outposts:GetBucket</code> permissions on the specified Outposts bucket and belong to the Outposts bucket owner's account in order to use this action. Only users from Outposts bucket owner account with the right permissions can perform actions on an Outposts bucket. </p> <p> If you don't have <code>s3-outposts:GetBucket</code> permissions or you're not using an identity that belongs to the bucket owner's account, Amazon S3 returns a <code>403 Access Denied</code> error.</p> <p>The following actions are related to <code>GetBucket</code> for Amazon S3 on Outposts:</p> <p>All Amazon S3 on Outposts REST API requests for this action require an additional parameter of <code>x-amz-outpost-id</code> to be passed with the request. In addition, you must use an S3 on Outposts endpoint hostname prefix instead of <code>s3-control</code>. For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and the <code>x-amz-outpost-id</code> derived by using the access point ARN, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetBucket.html#API_control_GetBucket_Examples">Examples</a> section.</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_PutObject.html">PutObject</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateBucket.html">CreateBucket</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteBucket.html">DeleteBucket</a> </p> </li> </ul>
    * @param
    * @param getBucketRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetBucket (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlGetBucketRequest getBucketRequest,
        FAWSS3ControlGetBucketResult &getBucketResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <note> <p>This action gets an Amazon S3 on Outposts bucket's lifecycle configuration. To get an S3 bucket's lifecycle configuration, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_GetBucketLifecycleConfiguration.html">GetBucketLifecycleConfiguration</a> in the <i>Amazon S3 API Reference</i>. </p> </note> <p>Returns the lifecycle configuration information set on the Outposts bucket. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using Amazon S3 on Outposts</a> and for information about lifecycle configuration, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/object-lifecycle-mgmt.html"> Object Lifecycle Management</a> in <i>Amazon S3 User Guide</i>.</p> <p>To use this action, you must have permission to perform the <code>s3-outposts:GetLifecycleConfiguration</code> action. The Outposts bucket owner has this permission, by default. The bucket owner can grant this permission to others. For more information about permissions, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-with-s3-actions.html#using-with-s3-actions-related-to-bucket-subresources">Permissions Related to Bucket Subresource Operations</a> and <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/s3-access-control.html">Managing Access Permissions to Your Amazon S3 Resources</a>.</p> <p>All Amazon S3 on Outposts REST API requests for this action require an additional parameter of <code>x-amz-outpost-id</code> to be passed with the request. In addition, you must use an S3 on Outposts endpoint hostname prefix instead of <code>s3-control</code>. For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and the <code>x-amz-outpost-id</code> derived by using the access point ARN, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetBucketLifecycleConfiguration.html#API_control_GetBucketLifecycleConfiguration_Examples">Examples</a> section.</p> <p> <code>GetBucketLifecycleConfiguration</code> has the following special error:</p> <ul> <li> <p>Error code: <code>NoSuchLifecycleConfiguration</code> </p> <ul> <li> <p>Description: The lifecycle configuration does not exist.</p> </li> <li> <p>HTTP Status Code: 404 Not Found</p> </li> <li> <p>SOAP Fault Code Prefix: Client</p> </li> </ul> </li> </ul> <p>The following actions are related to <code>GetBucketLifecycleConfiguration</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutBucketLifecycleConfiguration.html">PutBucketLifecycleConfiguration</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteBucketLifecycleConfiguration.html">DeleteBucketLifecycleConfiguration</a> </p> </li> </ul>
    * @param
    * @param getBucketLifecycleConfigurationRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetBucketLifecycleConfiguration (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlGetBucketLifecycleConfigurationRequest getBucketLifecycleConfigurationRequest,
        FAWSS3ControlGetBucketLifecycleConfigurationResult &getBucketLifecycleConfigurationResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <note> <p>This action gets a bucket policy for an Amazon S3 on Outposts bucket. To get a policy for an S3 bucket, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_GetBucketPolicy.html">GetBucketPolicy</a> in the <i>Amazon S3 API Reference</i>. </p> </note> <p>Returns the policy of a specified Outposts bucket. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using Amazon S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p> <p>If you are using an identity other than the root user of the Amazon Web Services account that owns the bucket, the calling identity must have the <code>GetBucketPolicy</code> permissions on the specified bucket and belong to the bucket owner's account in order to use this action.</p> <p>Only users from Outposts bucket owner account with the right permissions can perform actions on an Outposts bucket. If you don't have <code>s3-outposts:GetBucketPolicy</code> permissions or you're not using an identity that belongs to the bucket owner's account, Amazon S3 returns a <code>403 Access Denied</code> error.</p> <important> <p>As a security precaution, the root user of the Amazon Web Services account that owns a bucket can always use this action, even if the policy explicitly denies the root user the ability to perform this action.</p> </important> <p>For more information about bucket policies, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/using-iam-policies.html">Using Bucket Policies and User Policies</a>.</p> <p>All Amazon S3 on Outposts REST API requests for this action require an additional parameter of <code>x-amz-outpost-id</code> to be passed with the request. In addition, you must use an S3 on Outposts endpoint hostname prefix instead of <code>s3-control</code>. For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and the <code>x-amz-outpost-id</code> derived by using the access point ARN, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetBucketPolicy.html#API_control_GetBucketPolicy_Examples">Examples</a> section.</p> <p>The following actions are related to <code>GetBucketPolicy</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_GetObject.html">GetObject</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutBucketPolicy.html">PutBucketPolicy</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteBucketPolicy.html">DeleteBucketPolicy</a> </p> </li> </ul>
    * @param
    * @param getBucketPolicyRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetBucketPolicy (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlGetBucketPolicyRequest getBucketPolicyRequest,
        FAWSS3ControlGetBucketPolicyResult &getBucketPolicyResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <note> <p>This action gets an Amazon S3 on Outposts bucket's tags. To get an S3 bucket tags, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_GetBucketTagging.html">GetBucketTagging</a> in the <i>Amazon S3 API Reference</i>. </p> </note> <p>Returns the tag set associated with the Outposts bucket. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using Amazon S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p> <p>To use this action, you must have permission to perform the <code>GetBucketTagging</code> action. By default, the bucket owner has this permission and can grant this permission to others.</p> <p> <code>GetBucketTagging</code> has the following special error:</p> <ul> <li> <p>Error code: <code>NoSuchTagSetError</code> </p> <ul> <li> <p>Description: There is no tag set associated with the bucket.</p> </li> </ul> </li> </ul> <p>All Amazon S3 on Outposts REST API requests for this action require an additional parameter of <code>x-amz-outpost-id</code> to be passed with the request. In addition, you must use an S3 on Outposts endpoint hostname prefix instead of <code>s3-control</code>. For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and the <code>x-amz-outpost-id</code> derived by using the access point ARN, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetBucketTagging.html#API_control_GetBucketTagging_Examples">Examples</a> section.</p> <p>The following actions are related to <code>GetBucketTagging</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutBucketTagging.html">PutBucketTagging</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteBucketTagging.html">DeleteBucketTagging</a> </p> </li> </ul>
    * @param
    * @param getBucketTaggingRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetBucketTagging (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlGetBucketTaggingRequest getBucketTaggingRequest,
        FAWSS3ControlGetBucketTaggingResult &getBucketTaggingResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <note> <p>This operation returns the versioning state for S3 on Outposts buckets only. To return the versioning state for an S3 bucket, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_GetBucketVersioning.html">GetBucketVersioning</a> in the <i>Amazon S3 API Reference</i>. </p> </note> <p>Returns the versioning state for an S3 on Outposts bucket. With S3 Versioning, you can save multiple distinct copies of your objects and recover from unintended user actions and application failures.</p> <p>If you've never set versioning on your bucket, it has no versioning state. In that case, the <code>GetBucketVersioning</code> request does not return a versioning state value.</p> <p>For more information about versioning, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/Versioning.html">Versioning</a> in the <i>Amazon S3 User Guide</i>.</p> <p>All Amazon S3 on Outposts REST API requests for this action require an additional parameter of <code>x-amz-outpost-id</code> to be passed with the request. In addition, you must use an S3 on Outposts endpoint hostname prefix instead of <code>s3-control</code>. For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and the <code>x-amz-outpost-id</code> derived by using the access point ARN, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetBucketVersioning.html#API_control_GetBucketVersioning_Examples">Examples</a> section.</p> <p>The following operations are related to <code>GetBucketVersioning</code> for S3 on Outposts.</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutBucketVersioning.html">PutBucketVersioning</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutBucketLifecycleConfiguration.html">PutBucketLifecycleConfiguration</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetBucketLifecycleConfiguration.html">GetBucketLifecycleConfiguration</a> </p> </li> </ul>
    * @param
    * @param getBucketVersioningRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetBucketVersioning (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlGetBucketVersioningRequest getBucketVersioningRequest,
        FAWSS3ControlGetBucketVersioningResult &getBucketVersioningResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns the tags on an S3 Batch Operations job. To use the <code>GetJobTagging</code> operation, you must have permission to perform the <code>s3:GetJobTagging</code> action. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/batch-ops-managing-jobs.html#batch-ops-job-tags">Controlling access and labeling jobs using tags</a> in the <i>Amazon S3 User Guide</i>.</p> <p/> <p>Related actions include:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateJob.html">CreateJob</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutJobTagging.html">PutJobTagging</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteJobTagging.html">DeleteJobTagging</a> </p> </li> </ul>
    * @param
    * @param getJobTaggingRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetJobTagging (
        UObject *WorldContextObject,
        bool &success,
        FGetJobTaggingRequest getJobTaggingRequest,
        FGetJobTaggingResult &getJobTaggingResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns configuration information about the specified Multi-Region Access Point.</p> <p>This action will always be routed to the US West (Oregon) Region. For more information about the restrictions around managing Multi-Region Access Points, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/ManagingMultiRegionAccessPoints.html">Managing Multi-Region Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>The following actions are related to <code>GetMultiRegionAccessPoint</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateMultiRegionAccessPoint.html">CreateMultiRegionAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteMultiRegionAccessPoint.html">DeleteMultiRegionAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DescribeMultiRegionAccessPointOperation.html">DescribeMultiRegionAccessPointOperation</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_ListMultiRegionAccessPoints.html">ListMultiRegionAccessPoints</a> </p> </li> </ul>
    * @param
    * @param getMultiRegionAccessPointRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetMultiRegionAccessPoint (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlGetMultiRegionAccessPointRequest getMultiRegionAccessPointRequest,
        FAWSS3ControlGetMultiRegionAccessPointResult &getMultiRegionAccessPointResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns the access control policy of the specified Multi-Region Access Point.</p> <p>This action will always be routed to the US West (Oregon) Region. For more information about the restrictions around managing Multi-Region Access Points, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/ManagingMultiRegionAccessPoints.html">Managing Multi-Region Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>The following actions are related to <code>GetMultiRegionAccessPointPolicy</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetMultiRegionAccessPointPolicyStatus.html">GetMultiRegionAccessPointPolicyStatus</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutMultiRegionAccessPointPolicy.html">PutMultiRegionAccessPointPolicy</a> </p> </li> </ul>
    * @param
    * @param getMultiRegionAccessPointPolicyRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetMultiRegionAccessPointPolicy (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlGetMultiRegionAccessPointPolicyRequest getMultiRegionAccessPointPolicyRequest,
        FAWSS3ControlGetMultiRegionAccessPointPolicyResult &getMultiRegionAccessPointPolicyResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Indicates whether the specified Multi-Region Access Point has an access control policy that allows public access.</p> <p>This action will always be routed to the US West (Oregon) Region. For more information about the restrictions around managing Multi-Region Access Points, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/ManagingMultiRegionAccessPoints.html">Managing Multi-Region Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>The following actions are related to <code>GetMultiRegionAccessPointPolicyStatus</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetMultiRegionAccessPointPolicy.html">GetMultiRegionAccessPointPolicy</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutMultiRegionAccessPointPolicy.html">PutMultiRegionAccessPointPolicy</a> </p> </li> </ul>
    * @param
    * @param getMultiRegionAccessPointPolicyStatusRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetMultiRegionAccessPointPolicyStatus (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlGetMultiRegionAccessPointPolicyStatusRequest getMultiRegionAccessPointPolicyStatusRequest,
        FAWSS3ControlGetMultiRegionAccessPointPolicyStatusResult &getMultiRegionAccessPointPolicyStatusResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns the routing configuration for a Multi-Region Access Point, indicating which Regions are active or passive.</p> <p>To obtain routing control changes and failover requests, use the Amazon S3 failover control infrastructure endpoints in these five Amazon Web Services Regions:</p> <ul> <li> <p> <code>us-east-1</code> </p> </li> <li> <p> <code>us-west-2</code> </p> </li> <li> <p> <code>ap-southeast-2</code> </p> </li> <li> <p> <code>ap-northeast-1</code> </p> </li> <li> <p> <code>eu-west-1</code> </p> </li> </ul> <note> <p>Your Amazon S3 bucket does not need to be in these five Regions.</p> </note>
    * @param
    * @param getMultiRegionAccessPointRoutesRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetMultiRegionAccessPointRoutes (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlGetMultiRegionAccessPointRoutesRequest getMultiRegionAccessPointRoutesRequest,
        FAWSS3ControlGetMultiRegionAccessPointRoutesResult &getMultiRegionAccessPointRoutesResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Retrieves the <code>PublicAccessBlock</code> configuration for an Amazon Web Services account. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/access-control-block-public-access.html"> Using Amazon S3 block public access</a>.</p> <p>Related actions include:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeletePublicAccessBlock.html">DeletePublicAccessBlock</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutPublicAccessBlock.html">PutPublicAccessBlock</a> </p> </li> </ul>
    * @param
    * @param getPublicAccessBlockRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetPublicAccessBlock (
        UObject *WorldContextObject,
        bool &success,
        FS3ControlGetPublicAccessBlockRequest getPublicAccessBlockRequest,
        FS3ControlGetPublicAccessBlockResult &getPublicAccessBlockResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Gets the Amazon S3 Storage Lens configuration. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage_lens.html">Assessing your storage activity and usage with Amazon S3 Storage Lens </a> in the <i>Amazon S3 User Guide</i>. For a complete list of S3 Storage Lens metrics, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/storage_lens_metrics_glossary.html">S3 Storage Lens metrics glossary</a> in the <i>Amazon S3 User Guide</i>.</p> <note> <p>To use this action, you must have permission to perform the <code>s3:GetStorageLensConfiguration</code> action. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage_lens_iam_permissions.html">Setting permissions to use Amazon S3 Storage Lens</a> in the <i>Amazon S3 User Guide</i>.</p> </note>
    * @param
    * @param getStorageLensConfigurationRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetStorageLensConfiguration (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlGetStorageLensConfigurationRequest getStorageLensConfigurationRequest,
        FAWSS3ControlGetStorageLensConfigurationResult &getStorageLensConfigurationResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Gets the tags of Amazon S3 Storage Lens configuration. For more information about S3 Storage Lens, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage_lens.html">Assessing your storage activity and usage with Amazon S3 Storage Lens </a> in the <i>Amazon S3 User Guide</i>.</p> <note> <p>To use this action, you must have permission to perform the <code>s3:GetStorageLensConfigurationTagging</code> action. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage_lens_iam_permissions.html">Setting permissions to use Amazon S3 Storage Lens</a> in the <i>Amazon S3 User Guide</i>.</p> </note>
    * @param
    * @param getStorageLensConfigurationTaggingRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void GetStorageLensConfigurationTagging (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlGetStorageLensConfigurationTaggingRequest getStorageLensConfigurationTaggingRequest,
        FAWSS3ControlGetStorageLensConfigurationTaggingResult &getStorageLensConfigurationTaggingResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns a list of the access points that are owned by the current account that's associated with the specified bucket. You can retrieve up to 1000 access points per call. If the specified bucket has more than 1,000 access points (or the number specified in <code>maxResults</code>, whichever is less), the response will include a continuation token that you can use to list the additional access points.</p> <p/> <p>All Amazon S3 on Outposts REST API requests for this action require an additional parameter of <code>x-amz-outpost-id</code> to be passed with the request. In addition, you must use an S3 on Outposts endpoint hostname prefix instead of <code>s3-control</code>. For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and the <code>x-amz-outpost-id</code> derived by using the access point ARN, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetAccessPoint.html#API_control_GetAccessPoint_Examples">Examples</a> section.</p> <p>The following actions are related to <code>ListAccessPoints</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateAccessPoint.html">CreateAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteAccessPoint.html">DeleteAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetAccessPoint.html">GetAccessPoint</a> </p> </li> </ul>
    * @param
    * @param listAccessPointsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void ListAccessPoints (
        UObject *WorldContextObject,
        bool &success,
        FListAccessPointsRequest listAccessPointsRequest,
        FListAccessPointsResult &listAccessPointsResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns some or all (up to 1,000) access points associated with the Object Lambda Access Point per call. If there are more access points than what can be returned in one call, the response will include a continuation token that you can use to list the additional access points.</p> <p>The following actions are related to <code>ListAccessPointsForObjectLambda</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateAccessPointForObjectLambda.html">CreateAccessPointForObjectLambda</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteAccessPointForObjectLambda.html">DeleteAccessPointForObjectLambda</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetAccessPointForObjectLambda.html">GetAccessPointForObjectLambda</a> </p> </li> </ul>
    * @param
    * @param listAccessPointsForObjectLambdaRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void ListAccessPointsForObjectLambda (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlListAccessPointsForObjectLambdaRequest listAccessPointsForObjectLambdaRequest,
        FAWSS3ControlListAccessPointsForObjectLambdaResult &listAccessPointsForObjectLambdaResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Lists current S3 Batch Operations jobs and jobs that have ended within the last 30 days for the Amazon Web Services account making the request. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/batch-ops.html">S3 Batch Operations</a> in the <i>Amazon S3 User Guide</i>.</p> <p>Related actions include:</p> <p/> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateJob.html">CreateJob</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DescribeJob.html">DescribeJob</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_UpdateJobPriority.html">UpdateJobPriority</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_UpdateJobStatus.html">UpdateJobStatus</a> </p> </li> </ul>
    * @param
    * @param listJobsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void ListJobs (
        UObject *WorldContextObject,
        bool &success,
        FListJobsRequest listJobsRequest,
        FListJobsResult &listJobsResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns a list of the Multi-Region Access Points currently associated with the specified Amazon Web Services account. Each call can return up to 100 Multi-Region Access Points, the maximum number of Multi-Region Access Points that can be associated with a single account.</p> <p>This action will always be routed to the US West (Oregon) Region. For more information about the restrictions around managing Multi-Region Access Points, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/ManagingMultiRegionAccessPoints.html">Managing Multi-Region Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>The following actions are related to <code>ListMultiRegionAccessPoint</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateMultiRegionAccessPoint.html">CreateMultiRegionAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteMultiRegionAccessPoint.html">DeleteMultiRegionAccessPoint</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DescribeMultiRegionAccessPointOperation.html">DescribeMultiRegionAccessPointOperation</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetMultiRegionAccessPoint.html">GetMultiRegionAccessPoint</a> </p> </li> </ul>
    * @param
    * @param listMultiRegionAccessPointsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void ListMultiRegionAccessPoints (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlListMultiRegionAccessPointsRequest listMultiRegionAccessPointsRequest,
        FAWSS3ControlListMultiRegionAccessPointsResult &listMultiRegionAccessPointsResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Returns a list of all Outposts buckets in an Outpost that are owned by the authenticated sender of the request. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using Amazon S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p> <p>For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and <code>x-amz-outpost-id</code> in your request, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_ListRegionalBuckets.html#API_control_ListRegionalBuckets_Examples">Examples</a> section.</p>
    * @param
    * @param listRegionalBucketsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void ListRegionalBuckets (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlListRegionalBucketsRequest listRegionalBucketsRequest,
        FAWSS3ControlListRegionalBucketsResult &listRegionalBucketsResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Gets a list of Amazon S3 Storage Lens configurations. For more information about S3 Storage Lens, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage_lens.html">Assessing your storage activity and usage with Amazon S3 Storage Lens </a> in the <i>Amazon S3 User Guide</i>.</p> <note> <p>To use this action, you must have permission to perform the <code>s3:ListStorageLensConfigurations</code> action. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage_lens_iam_permissions.html">Setting permissions to use Amazon S3 Storage Lens</a> in the <i>Amazon S3 User Guide</i>.</p> </note>
    * @param
    * @param listStorageLensConfigurationsRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void ListStorageLensConfigurations (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlListStorageLensConfigurationsRequest listStorageLensConfigurationsRequest,
        FAWSS3ControlListStorageLensConfigurationsResult &listStorageLensConfigurationsResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Replaces configuration for an Object Lambda Access Point.</p> <p>The following actions are related to <code>PutAccessPointConfigurationForObjectLambda</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetAccessPointConfigurationForObjectLambda.html">GetAccessPointConfigurationForObjectLambda</a> </p> </li> </ul>
    * @param
    * @param putAccessPointConfigurationForObjectLambdaRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void PutAccessPointConfigurationForObjectLambda (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlPutAccessPointConfigurationForObjectLambdaRequest putAccessPointConfigurationForObjectLambdaRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Associates an access policy with the specified access point. Each access point can have only one policy, so a request made to this API replaces any existing policy associated with the specified access point.</p> <p/> <p>All Amazon S3 on Outposts REST API requests for this action require an additional parameter of <code>x-amz-outpost-id</code> to be passed with the request. In addition, you must use an S3 on Outposts endpoint hostname prefix instead of <code>s3-control</code>. For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and the <code>x-amz-outpost-id</code> derived by using the access point ARN, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutAccessPointPolicy.html#API_control_PutAccessPointPolicy_Examples">Examples</a> section.</p> <p>The following actions are related to <code>PutAccessPointPolicy</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetAccessPointPolicy.html">GetAccessPointPolicy</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteAccessPointPolicy.html">DeleteAccessPointPolicy</a> </p> </li> </ul>
    * @param
    * @param putAccessPointPolicyRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void PutAccessPointPolicy (
        UObject *WorldContextObject,
        bool &success,
        FPutAccessPointPolicyRequest putAccessPointPolicyRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Creates or replaces resource policy for an Object Lambda Access Point. For an example policy, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/olap-create.html#olap-create-cli">Creating Object Lambda Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>The following actions are related to <code>PutAccessPointPolicyForObjectLambda</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteAccessPointPolicyForObjectLambda.html">DeleteAccessPointPolicyForObjectLambda</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetAccessPointPolicyForObjectLambda.html">GetAccessPointPolicyForObjectLambda</a> </p> </li> </ul>
    * @param
    * @param putAccessPointPolicyForObjectLambdaRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void PutAccessPointPolicyForObjectLambda (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlPutAccessPointPolicyForObjectLambdaRequest putAccessPointPolicyForObjectLambdaRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <note> <p>This action puts a lifecycle configuration to an Amazon S3 on Outposts bucket. To put a lifecycle configuration to an S3 bucket, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_PutBucketLifecycleConfiguration.html">PutBucketLifecycleConfiguration</a> in the <i>Amazon S3 API Reference</i>. </p> </note> <p>Creates a new lifecycle configuration for the S3 on Outposts bucket or replaces an existing lifecycle configuration. Outposts buckets only support lifecycle configurations that delete/expire objects after a certain period of time and abort incomplete multipart uploads.</p> <p/> <p>All Amazon S3 on Outposts REST API requests for this action require an additional parameter of <code>x-amz-outpost-id</code> to be passed with the request. In addition, you must use an S3 on Outposts endpoint hostname prefix instead of <code>s3-control</code>. For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and the <code>x-amz-outpost-id</code> derived by using the access point ARN, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutBucketLifecycleConfiguration.html#API_control_PutBucketLifecycleConfiguration_Examples">Examples</a> section.</p> <p>The following actions are related to <code>PutBucketLifecycleConfiguration</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetBucketLifecycleConfiguration.html">GetBucketLifecycleConfiguration</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteBucketLifecycleConfiguration.html">DeleteBucketLifecycleConfiguration</a> </p> </li> </ul>
    * @param
    * @param putBucketLifecycleConfigurationRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void PutBucketLifecycleConfiguration (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlPutBucketLifecycleConfigurationRequest putBucketLifecycleConfigurationRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <note> <p>This action puts a bucket policy to an Amazon S3 on Outposts bucket. To put a policy on an S3 bucket, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_PutBucketPolicy.html">PutBucketPolicy</a> in the <i>Amazon S3 API Reference</i>. </p> </note> <p>Applies an Amazon S3 bucket policy to an Outposts bucket. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using Amazon S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p> <p>If you are using an identity other than the root user of the Amazon Web Services account that owns the Outposts bucket, the calling identity must have the <code>PutBucketPolicy</code> permissions on the specified Outposts bucket and belong to the bucket owner's account in order to use this action.</p> <p>If you don't have <code>PutBucketPolicy</code> permissions, Amazon S3 returns a <code>403 Access Denied</code> error. If you have the correct permissions, but you're not using an identity that belongs to the bucket owner's account, Amazon S3 returns a <code>405 Method Not Allowed</code> error.</p> <important> <p> As a security precaution, the root user of the Amazon Web Services account that owns a bucket can always use this action, even if the policy explicitly denies the root user the ability to perform this action. </p> </important> <p>For more information about bucket policies, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/using-iam-policies.html">Using Bucket Policies and User Policies</a>.</p> <p>All Amazon S3 on Outposts REST API requests for this action require an additional parameter of <code>x-amz-outpost-id</code> to be passed with the request. In addition, you must use an S3 on Outposts endpoint hostname prefix instead of <code>s3-control</code>. For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and the <code>x-amz-outpost-id</code> derived by using the access point ARN, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutBucketPolicy.html#API_control_PutBucketPolicy_Examples">Examples</a> section.</p> <p>The following actions are related to <code>PutBucketPolicy</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetBucketPolicy.html">GetBucketPolicy</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteBucketPolicy.html">DeleteBucketPolicy</a> </p> </li> </ul>
    * @param
    * @param putBucketPolicyRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void PutBucketPolicy (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlPutBucketPolicyRequest putBucketPolicyRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <note> <p>This action puts tags on an Amazon S3 on Outposts bucket. To put tags on an S3 bucket, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_PutBucketTagging.html">PutBucketTagging</a> in the <i>Amazon S3 API Reference</i>. </p> </note> <p>Sets the tags for an S3 on Outposts bucket. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3onOutposts.html">Using Amazon S3 on Outposts</a> in the <i>Amazon S3 User Guide</i>.</p> <p>Use tags to organize your Amazon Web Services bill to reflect your own cost structure. To do this, sign up to get your Amazon Web Services account bill with tag key values included. Then, to see the cost of combined resources, organize your billing information according to resources with the same tag key values. For example, you can tag several resources with a specific application name, and then organize your billing information to see the total cost of that application across several services. For more information, see <a href="https://docs.aws.amazon.com/awsaccountbilling/latest/aboutv2/cost-alloc-tags.html">Cost allocation and tagging</a>.</p> <note> <p>Within a bucket, if you add a tag that has the same key as an existing tag, the new value overwrites the old value. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/CostAllocTagging.html"> Using cost allocation in Amazon S3 bucket tags</a>.</p> </note> <p>To use this action, you must have permissions to perform the <code>s3-outposts:PutBucketTagging</code> action. The Outposts bucket owner has this permission by default and can grant this permission to others. For more information about permissions, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/using-with-s3-actions.html#using-with-s3-actions-related-to-bucket-subresources"> Permissions Related to Bucket Subresource Operations</a> and <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/s3-access-control.html">Managing access permissions to your Amazon S3 resources</a>.</p> <p> <code>PutBucketTagging</code> has the following special errors:</p> <ul> <li> <p>Error code: <code>InvalidTagError</code> </p> <ul> <li> <p>Description: The tag provided was not a valid tag. This error can occur if the tag did not pass input validation. For information about tag restrictions, see <a href="https://docs.aws.amazon.com/awsaccountbilling/latest/aboutv2/allocation-tag-restrictions.html"> User-Defined Tag Restrictions</a> and <a href="https://docs.aws.amazon.com/awsaccountbilling/latest/aboutv2/aws-tag-restrictions.html"> Amazon Web Services-Generated Cost Allocation Tag Restrictions</a>.</p> </li> </ul> </li> <li> <p>Error code: <code>MalformedXMLError</code> </p> <ul> <li> <p>Description: The XML provided does not match the schema.</p> </li> </ul> </li> <li> <p>Error code: <code>OperationAbortedError </code> </p> <ul> <li> <p>Description: A conflicting conditional action is currently in progress against this resource. Try again.</p> </li> </ul> </li> <li> <p>Error code: <code>InternalError</code> </p> <ul> <li> <p>Description: The service was unable to apply the provided tag to the bucket.</p> </li> </ul> </li> </ul> <p>All Amazon S3 on Outposts REST API requests for this action require an additional parameter of <code>x-amz-outpost-id</code> to be passed with the request. In addition, you must use an S3 on Outposts endpoint hostname prefix instead of <code>s3-control</code>. For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and the <code>x-amz-outpost-id</code> derived by using the access point ARN, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutBucketTagging.html#API_control_PutBucketTagging_Examples">Examples</a> section.</p> <p>The following actions are related to <code>PutBucketTagging</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetBucketTagging.html">GetBucketTagging</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteBucketTagging.html">DeleteBucketTagging</a> </p> </li> </ul>
    * @param
    * @param putBucketTaggingRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void PutBucketTagging (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlPutBucketTaggingRequest putBucketTaggingRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <note> <p>This operation sets the versioning state for S3 on Outposts buckets only. To set the versioning state for an S3 bucket, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_PutBucketVersioning.html">PutBucketVersioning</a> in the <i>Amazon S3 API Reference</i>. </p> </note> <p>Sets the versioning state for an S3 on Outposts bucket. With S3 Versioning, you can save multiple distinct copies of your objects and recover from unintended user actions and application failures.</p> <p>You can set the versioning state to one of the following:</p> <ul> <li> <p> <b>Enabled</b> - Enables versioning for the objects in the bucket. All objects added to the bucket receive a unique version ID.</p> </li> <li> <p> <b>Suspended</b> - Suspends versioning for the objects in the bucket. All objects added to the bucket receive the version ID <code>null</code>.</p> </li> </ul> <p>If you've never set versioning on your bucket, it has no versioning state. In that case, a <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetBucketVersioning.html"> GetBucketVersioning</a> request does not return a versioning state value.</p> <p>When you enable S3 Versioning, for each object in your bucket, you have a current version and zero or more noncurrent versions. You can configure your bucket S3 Lifecycle rules to expire noncurrent versions after a specified time period. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/S3OutpostsLifecycleManaging.html"> Creating and managing a lifecycle configuration for your S3 on Outposts bucket</a> in the <i>Amazon S3 User Guide</i>.</p> <p>If you have an object expiration lifecycle configuration in your non-versioned bucket and you want to maintain the same permanent delete behavior when you enable versioning, you must add a noncurrent expiration policy. The noncurrent expiration lifecycle configuration will manage the deletes of the noncurrent object versions in the version-enabled bucket. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/Versioning.html">Versioning</a> in the <i>Amazon S3 User Guide</i>.</p> <p>All Amazon S3 on Outposts REST API requests for this action require an additional parameter of <code>x-amz-outpost-id</code> to be passed with the request. In addition, you must use an S3 on Outposts endpoint hostname prefix instead of <code>s3-control</code>. For an example of the request syntax for Amazon S3 on Outposts that uses the S3 on Outposts endpoint hostname prefix and the <code>x-amz-outpost-id</code> derived by using the access point ARN, see the <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutBucketVersioning.html#API_control_PutBucketVersioning_Examples">Examples</a> section.</p> <p>The following operations are related to <code>PutBucketVersioning</code> for S3 on Outposts.</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetBucketVersioning.html">GetBucketVersioning</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_PutBucketLifecycleConfiguration.html">PutBucketLifecycleConfiguration</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetBucketLifecycleConfiguration.html">GetBucketLifecycleConfiguration</a> </p> </li> </ul>
    * @param
    * @param putBucketVersioningRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void PutBucketVersioning (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlPutBucketVersioningRequest putBucketVersioningRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Sets the supplied tag-set on an S3 Batch Operations job.</p> <p>A tag is a key-value pair. You can associate S3 Batch Operations tags with any job by sending a PUT request against the tagging subresource that is associated with the job. To modify the existing tag set, you can either replace the existing tag set entirely, or make changes within the existing tag set by retrieving the existing tag set using <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetJobTagging.html">GetJobTagging</a>, modify that tag set, and use this action to replace the tag set with the one you modified. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/batch-ops-managing-jobs.html#batch-ops-job-tags">Controlling access and labeling jobs using tags</a> in the <i>Amazon S3 User Guide</i>. </p> <p/> <note> <ul> <li> <p>If you send this request with an empty tag set, Amazon S3 deletes the existing tag set on the Batch Operations job. If you use this method, you are charged for a Tier 1 Request (PUT). For more information, see <a href="http://aws.amazon.com/s3/pricing/">Amazon S3 pricing</a>.</p> </li> <li> <p>For deleting existing tags for your Batch Operations job, a <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteJobTagging.html">DeleteJobTagging</a> request is preferred because it achieves the same result without incurring charges.</p> </li> <li> <p>A few things to consider about using tags:</p> <ul> <li> <p>Amazon S3 limits the maximum number of tags to 50 tags per job.</p> </li> <li> <p>You can associate up to 50 tags with a job as long as they have unique tag keys.</p> </li> <li> <p>A tag key can be up to 128 Unicode characters in length, and tag values can be up to 256 Unicode characters in length.</p> </li> <li> <p>The key and values are case sensitive.</p> </li> <li> <p>For tagging-related restrictions related to characters and encodings, see <a href="https://docs.aws.amazon.com/awsaccountbilling/latest/aboutv2/allocation-tag-restrictions.html">User-Defined Tag Restrictions</a> in the <i>Billing and Cost Management User Guide</i>.</p> </li> </ul> </li> </ul> </note> <p/> <p>To use the <code>PutJobTagging</code> operation, you must have permission to perform the <code>s3:PutJobTagging</code> action.</p> <p>Related actions include:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateJob.html">CreateJob</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetJobTagging.html">GetJobTagging</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeleteJobTagging.html">DeleteJobTagging</a> </p> </li> </ul>
    * @param
    * @param putJobTaggingRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void PutJobTagging (
        UObject *WorldContextObject,
        bool &success,
        FPutJobTaggingRequest putJobTaggingRequest,
        FPutJobTaggingResult &putJobTaggingResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Associates an access control policy with the specified Multi-Region Access Point. Each Multi-Region Access Point can have only one policy, so a request made to this action replaces any existing policy that is associated with the specified Multi-Region Access Point.</p> <p>This action will always be routed to the US West (Oregon) Region. For more information about the restrictions around managing Multi-Region Access Points, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/ManagingMultiRegionAccessPoints.html">Managing Multi-Region Access Points</a> in the <i>Amazon S3 User Guide</i>.</p> <p>The following actions are related to <code>PutMultiRegionAccessPointPolicy</code>:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetMultiRegionAccessPointPolicy.html">GetMultiRegionAccessPointPolicy</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetMultiRegionAccessPointPolicyStatus.html">GetMultiRegionAccessPointPolicyStatus</a> </p> </li> </ul>
    * @param
    * @param putMultiRegionAccessPointPolicyRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void PutMultiRegionAccessPointPolicy (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlPutMultiRegionAccessPointPolicyRequest putMultiRegionAccessPointPolicyRequest,
        FAWSS3ControlPutMultiRegionAccessPointPolicyResult &putMultiRegionAccessPointPolicyResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Creates or modifies the <code>PublicAccessBlock</code> configuration for an Amazon Web Services account. For this operation, users must have the <code>s3:PutAccountPublicAccessBlock</code> permission. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/access-control-block-public-access.html"> Using Amazon S3 block public access</a>.</p> <p>Related actions include:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_GetPublicAccessBlock.html">GetPublicAccessBlock</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DeletePublicAccessBlock.html">DeletePublicAccessBlock</a> </p> </li> </ul>
    * @param
    * @param putPublicAccessBlockRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void PutPublicAccessBlock (
        UObject *WorldContextObject,
        bool &success,
        FS3ControlPutPublicAccessBlockRequest putPublicAccessBlockRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Puts an Amazon S3 Storage Lens configuration. For more information about S3 Storage Lens, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage_lens.html">Working with Amazon S3 Storage Lens</a> in the <i>Amazon S3 User Guide</i>. For a complete list of S3 Storage Lens metrics, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/storage_lens_metrics_glossary.html">S3 Storage Lens metrics glossary</a> in the <i>Amazon S3 User Guide</i>.</p> <note> <p>To use this action, you must have permission to perform the <code>s3:PutStorageLensConfiguration</code> action. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage_lens_iam_permissions.html">Setting permissions to use Amazon S3 Storage Lens</a> in the <i>Amazon S3 User Guide</i>.</p> </note>
    * @param
    * @param putStorageLensConfigurationRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void PutStorageLensConfiguration (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlPutStorageLensConfigurationRequest putStorageLensConfigurationRequest,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Put or replace tags on an existing Amazon S3 Storage Lens configuration. For more information about S3 Storage Lens, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage_lens.html">Assessing your storage activity and usage with Amazon S3 Storage Lens </a> in the <i>Amazon S3 User Guide</i>.</p> <note> <p>To use this action, you must have permission to perform the <code>s3:PutStorageLensConfigurationTagging</code> action. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage_lens_iam_permissions.html">Setting permissions to use Amazon S3 Storage Lens</a> in the <i>Amazon S3 User Guide</i>.</p> </note>
    * @param
    * @param putStorageLensConfigurationTaggingRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void PutStorageLensConfigurationTagging (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlPutStorageLensConfigurationTaggingRequest putStorageLensConfigurationTaggingRequest,
        FAWSS3ControlPutStorageLensConfigurationTaggingResult &putStorageLensConfigurationTaggingResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Submits an updated route configuration for a Multi-Region Access Point. This API operation updates the routing status for the specified Regions from active to passive, or from passive to active. A value of <code>0</code> indicates a passive status, which means that traffic won't be routed to the specified Region. A value of <code>100</code> indicates an active status, which means that traffic will be routed to the specified Region. At least one Region must be active at all times.</p> <p>When the routing configuration is changed, any in-progress operations (uploads, copies, deletes, and so on) to formerly active Regions will continue to run to their final completion state (success or failure). The routing configurations of any Regions that aren’t specified remain unchanged.</p> <note> <p>Updated routing configurations might not be immediately applied. It can take up to 2 minutes for your changes to take effect.</p> </note> <p>To submit routing control changes and failover requests, use the Amazon S3 failover control infrastructure endpoints in these five Amazon Web Services Regions:</p> <ul> <li> <p> <code>us-east-1</code> </p> </li> <li> <p> <code>us-west-2</code> </p> </li> <li> <p> <code>ap-southeast-2</code> </p> </li> <li> <p> <code>ap-northeast-1</code> </p> </li> <li> <p> <code>eu-west-1</code> </p> </li> </ul> <note> <p>Your Amazon S3 bucket does not need to be in these five Regions.</p> </note>
    * @param
    * @param submitMultiRegionAccessPointRoutesRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void SubmitMultiRegionAccessPointRoutes (
        UObject *WorldContextObject,
        bool &success,
        FAWSS3ControlSubmitMultiRegionAccessPointRoutesRequest submitMultiRegionAccessPointRoutesRequest,
        FAWSS3ControlSubmitMultiRegionAccessPointRoutesResult &submitMultiRegionAccessPointRoutesResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Updates an existing S3 Batch Operations job's priority. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/batch-ops.html">S3 Batch Operations</a> in the <i>Amazon S3 User Guide</i>.</p> <p/> <p>Related actions include:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateJob.html">CreateJob</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_ListJobs.html">ListJobs</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DescribeJob.html">DescribeJob</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_UpdateJobStatus.html">UpdateJobStatus</a> </p> </li> </ul>
    * @param
    * @param updateJobPriorityRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void UpdateJobPriority (
        UObject *WorldContextObject,
        bool &success,
        FUpdateJobPriorityRequest updateJobPriorityRequest,
        FUpdateJobPriorityResult &updateJobPriorityResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
    /**
    * <p>Updates the status for the specified job. Use this action to confirm that you want to run a job or to cancel an existing job. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/batch-ops.html">S3 Batch Operations</a> in the <i>Amazon S3 User Guide</i>.</p> <p/> <p>Related actions include:</p> <ul> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_CreateJob.html">CreateJob</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_ListJobs.html">ListJobs</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_DescribeJob.html">DescribeJob</a> </p> </li> <li> <p> <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/API_control_UpdateJobStatus.html">UpdateJobStatus</a> </p> </li> </ul>
    * @param
    * @param updateJobStatusRequest
    * @param LatentInfo         The latent action
    **/
    UFUNCTION(BlueprintCallable,
    meta = (Latent, LatentInfo = "LatentInfo", HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"),
    Category = "S3Control Client")
    void UpdateJobStatus (
        UObject *WorldContextObject,
        bool &success,
        FUpdateJobStatusRequest updateJobStatusRequest,
        FUpdateJobStatusResult &updateJobStatusResult,
        ES3ControlError &errorType,
        FString &errorMessage,
        struct FLatentActionInfo LatentInfo
    );
};
