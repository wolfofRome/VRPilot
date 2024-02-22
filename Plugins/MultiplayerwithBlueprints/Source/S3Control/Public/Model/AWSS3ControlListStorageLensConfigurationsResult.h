/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/ListStorageLensConfigurationsResult.h"

#endif

#include "Model/AWSS3ControlListStorageLensConfigurationEntry.h"

#include "AWSS3ControlListStorageLensConfigurationsResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlListStorageLensConfigurationsResult {
GENERATED_BODY()

    /**
    *  <p>If the request produced more than the maximum number of S3 Storage Lens configuration results, you can pass this value into a subsequent request to retrieve the next page of results.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString nextToken;

    /**
    *  <p>A list of S3 Storage Lens configurations.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FAWSS3ControlListStorageLensConfigurationEntry> storageLensConfigurationList;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlListStorageLensConfigurationsResult &fromAWS(const Aws::S3Control::Model::ListStorageLensConfigurationsResult &awsListStorageLensConfigurationsResult) {
        this->nextToken = UTF8_TO_TCHAR(awsListStorageLensConfigurationsResult.GetNextToken().c_str());

        this->storageLensConfigurationList.Empty();
        for (const Aws::S3Control::Model::ListStorageLensConfigurationEntry& elem : awsListStorageLensConfigurationsResult.GetStorageLensConfigurationList()) {
            this->storageLensConfigurationList.Add(FAWSS3ControlListStorageLensConfigurationEntry().fromAWS(elem));
        }

        return *this;
    }
#endif
};
