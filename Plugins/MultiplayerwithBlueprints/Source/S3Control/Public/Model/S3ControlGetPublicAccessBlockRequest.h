/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/GetPublicAccessBlockRequest.h"

#endif


#include "S3ControlGetPublicAccessBlockRequest.generated.h"

USTRUCT(BlueprintType)
struct FS3ControlGetPublicAccessBlockRequest {
GENERATED_BODY()

    /**
    *  <p>The account ID for the Amazon Web Services account whose <code>PublicAccessBlock</code> configuration you want to retrieve.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::GetPublicAccessBlockRequest toAWS() const {
        Aws::S3Control::Model::GetPublicAccessBlockRequest awsGetPublicAccessBlockRequest;

		if (!(this->accountId.IsEmpty())) {
            awsGetPublicAccessBlockRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        return awsGetPublicAccessBlockRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty();
    }
#endif
};
