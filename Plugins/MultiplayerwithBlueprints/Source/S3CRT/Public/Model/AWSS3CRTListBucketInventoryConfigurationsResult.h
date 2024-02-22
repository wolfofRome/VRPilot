/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ListBucketInventoryConfigurationsResult.h"

#endif

#include "Model/AWSS3CRTInventoryConfiguration.h"

#include "AWSS3CRTListBucketInventoryConfigurationsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTListBucketInventoryConfigurationsResult {
GENERATED_BODY()

    /**
    *  <p>If sent in the request, the marker that is used as a starting point for this inventory configuration list response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString continuationToken;

    /**
    *  <p>The list of inventory configurations for a bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTInventoryConfiguration> inventoryConfigurationList;

    /**
    *  <p>Tells whether the returned list of inventory configurations is complete. A value of true indicates that the list is not complete and the NextContinuationToken is provided for a subsequent request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool isTruncated = false;

    /**
    *  <p>The marker used to continue this inventory configuration listing. Use the <code>NextContinuationToken</code> from this response to continue the listing in a subsequent request. The continuation token is an opaque value that Amazon S3 understands.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString nextContinuationToken;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTListBucketInventoryConfigurationsResult &fromAWS(const Aws::S3Crt::Model::ListBucketInventoryConfigurationsResult &awsListBucketInventoryConfigurationsResult) {
        this->continuationToken = UTF8_TO_TCHAR(awsListBucketInventoryConfigurationsResult.GetContinuationToken().c_str());

        this->inventoryConfigurationList.Empty();
        for (const Aws::S3Crt::Model::InventoryConfiguration& elem : awsListBucketInventoryConfigurationsResult.GetInventoryConfigurationList()) {
            this->inventoryConfigurationList.Add(FAWSS3CRTInventoryConfiguration().fromAWS(elem));
        }

        this->isTruncated = awsListBucketInventoryConfigurationsResult.GetIsTruncated();

        this->nextContinuationToken = UTF8_TO_TCHAR(awsListBucketInventoryConfigurationsResult.GetNextContinuationToken().c_str());

        return *this;
    }
#endif
};
