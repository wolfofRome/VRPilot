/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/PutPublicAccessBlockRequest.h"

#endif

#include "Model/S3ControlPublicAccessBlockConfiguration.h"

#include "S3ControlPutPublicAccessBlockRequest.generated.h"

USTRUCT(BlueprintType)
struct FS3ControlPutPublicAccessBlockRequest {
GENERATED_BODY()

    /**
    *  <p>The <code>PublicAccessBlock</code> configuration that you want to apply to the specified Amazon Web Services account.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3ControlPublicAccessBlockConfiguration publicAccessBlockConfiguration;

    /**
    *  <p>The account ID for the Amazon Web Services account whose <code>PublicAccessBlock</code> configuration you want to set.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::PutPublicAccessBlockRequest toAWS() const {
        Aws::S3Control::Model::PutPublicAccessBlockRequest awsPutPublicAccessBlockRequest;

        if (!(this->publicAccessBlockConfiguration.IsEmpty())) {
            awsPutPublicAccessBlockRequest.SetPublicAccessBlockConfiguration(this->publicAccessBlockConfiguration.toAWS());
        }

		if (!(this->accountId.IsEmpty())) {
            awsPutPublicAccessBlockRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        return awsPutPublicAccessBlockRequest;
    }

    bool IsEmpty() const {
        return this->publicAccessBlockConfiguration.IsEmpty() && this->accountId.IsEmpty();
    }
#endif
};
