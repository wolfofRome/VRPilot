/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/JSONInput.h"

#endif

#include "Model/AWSS3CRTJSONType.h"

#include "AWSS3CRTJSONInput.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTJSONInput {
GENERATED_BODY()

    /**
    *  <p>The type of JSON. Valid values: Document, Lines.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTJSONType type = EAWSS3CRTJSONType::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::JSONInput toAWS() const {
        Aws::S3Crt::Model::JSONInput awsJSONInput;

        switch(this->type) {
            case EAWSS3CRTJSONType::DOCUMENT:
                awsJSONInput.SetType(Aws::S3Crt::Model::JSONType::DOCUMENT);
                break;
            case EAWSS3CRTJSONType::LINES:
                awsJSONInput.SetType(Aws::S3Crt::Model::JSONType::LINES);
                break;
            default:
                break;
        }

        return awsJSONInput;
    }

    bool IsEmpty() const {
        return type == EAWSS3CRTJSONType::NOT_SET;
    }
#endif
};
