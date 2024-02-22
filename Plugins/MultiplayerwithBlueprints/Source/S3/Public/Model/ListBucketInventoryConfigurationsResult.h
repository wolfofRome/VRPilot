/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ListBucketInventoryConfigurationsResult.h"

#endif

#include "Model/InventoryConfiguration.h"

#include "ListBucketInventoryConfigurationsResult.generated.h"

USTRUCT(BlueprintType)
struct FListBucketInventoryConfigurationsResult {
GENERATED_BODY()

    /**
    *  <p>If sent in the request, the marker that is used as a starting point for this inventory configuration list response.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString continuationToken;

    /**
    *  <p>The list of inventory configurations for a bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FInventoryConfiguration> inventoryConfigurationList;

    /**
    *  <p>Tells whether the returned list of inventory configurations is complete. A value of true indicates that the list is not complete and the NextContinuationToken is provided for a subsequent request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool isTruncated = false;

    /**
    *  <p>The marker used to continue this inventory configuration listing. Use the <code>NextContinuationToken</code> from this response to continue the listing in a subsequent request. The continuation token is an opaque value that Amazon S3 understands.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString nextContinuationToken;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FListBucketInventoryConfigurationsResult &fromAWS(const Aws::S3::Model::ListBucketInventoryConfigurationsResult &awsListBucketInventoryConfigurationsResult) {
        this->continuationToken = UTF8_TO_TCHAR(awsListBucketInventoryConfigurationsResult.GetContinuationToken().c_str());

        this->inventoryConfigurationList.Empty();
        for (const Aws::S3::Model::InventoryConfiguration& elem : awsListBucketInventoryConfigurationsResult.GetInventoryConfigurationList()) {
            this->inventoryConfigurationList.Add(FInventoryConfiguration().fromAWS(elem));
        }

        this->isTruncated = awsListBucketInventoryConfigurationsResult.GetIsTruncated();

        this->nextContinuationToken = UTF8_TO_TCHAR(awsListBucketInventoryConfigurationsResult.GetNextContinuationToken().c_str());

        return *this;
    }
#endif
};
