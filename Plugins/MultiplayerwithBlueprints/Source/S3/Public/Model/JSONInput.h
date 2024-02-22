/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/JSONInput.h"

#endif

#include "Model/JSONType.h"

#include "JSONInput.generated.h"

USTRUCT(BlueprintType)
struct FJSONInput {
GENERATED_BODY()

    /**
    *  <p>The type of JSON. Valid values: Document, Lines.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSJSONType type = EAWSJSONType::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::JSONInput toAWS() const {
        Aws::S3::Model::JSONInput awsJSONInput;

        switch(this->type) {
            case EAWSJSONType::DOCUMENT:
                awsJSONInput.SetType(Aws::S3::Model::JSONType::DOCUMENT);
                break;
            case EAWSJSONType::LINES:
                awsJSONInput.SetType(Aws::S3::Model::JSONType::LINES);
                break;
            default:
                break;
        }

        return awsJSONInput;
    }

    bool IsEmpty() const {
        return type == EAWSJSONType::NOT_SET;
    }
#endif
};
