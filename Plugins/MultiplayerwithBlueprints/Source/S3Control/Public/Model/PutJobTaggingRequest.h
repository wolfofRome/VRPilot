/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/PutJobTaggingRequest.h"

#endif

#include "Model/S3ControlS3Tag.h"

#include "PutJobTaggingRequest.generated.h"

USTRUCT(BlueprintType)
struct FPutJobTaggingRequest {
GENERATED_BODY()

    /**
    *  <p>The AWS account ID associated with the Amazon S3 Batch Operations job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>The ID for the Amazon S3 Batch Operations job whose tags you want to replace.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString jobId;

    /**
    *  <p>The set of tags to associate with the Amazon S3 Batch Operations job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FS3ControlS3Tag> tags;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::PutJobTaggingRequest toAWS() const {
        Aws::S3Control::Model::PutJobTaggingRequest awsPutJobTaggingRequest;

		if (!(this->accountId.IsEmpty())) {
            awsPutJobTaggingRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

		if (!(this->jobId.IsEmpty())) {
            awsPutJobTaggingRequest.SetJobId(TCHAR_TO_UTF8(*this->jobId));
        }

        for (const FS3ControlS3Tag& elem : this->tags) {
            awsPutJobTaggingRequest.AddTags(elem.toAWS());
        }

        return awsPutJobTaggingRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && this->jobId.IsEmpty() && this->tags.Num() == 0;
    }
#endif
};
