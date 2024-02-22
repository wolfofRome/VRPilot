/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/CompletedMultipartUpload.h"

#endif

#include "Model/CompletedPart.h"

#include "CompletedMultipartUpload.generated.h"

USTRUCT(BlueprintType)
struct FCompletedMultipartUpload {
GENERATED_BODY()

    /**
    *  <p>Array of CompletedPart data types.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FCompletedPart> parts;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::CompletedMultipartUpload toAWS() const {
        Aws::S3::Model::CompletedMultipartUpload awsCompletedMultipartUpload;

        for (const FCompletedPart& elem : this->parts) {
            awsCompletedMultipartUpload.AddParts(elem.toAWS());
        }

        return awsCompletedMultipartUpload;
    }

    bool IsEmpty() const {
        return this->parts.Num() == 0;
    }
#endif
};
