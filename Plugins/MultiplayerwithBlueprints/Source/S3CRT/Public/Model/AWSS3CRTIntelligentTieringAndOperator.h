/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/IntelligentTieringAndOperator.h"

#endif

#include "Model/AWSS3CRTTag.h"

#include "AWSS3CRTIntelligentTieringAndOperator.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTIntelligentTieringAndOperator {
GENERATED_BODY()

    /**
    *  <p>An object key name prefix that identifies the subset of objects to which the configuration applies.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString prefix;

    /**
    *  <p>All of these tags must exist in the object's tag set in order for the configuration to apply.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTTag> tags;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::IntelligentTieringAndOperator toAWS() const {
        Aws::S3Crt::Model::IntelligentTieringAndOperator awsIntelligentTieringAndOperator;

        if (!(this->prefix.IsEmpty())) {
            awsIntelligentTieringAndOperator.SetPrefix(TCHAR_TO_UTF8(*this->prefix));
        }

        for (const FAWSS3CRTTag& elem : this->tags) {
            awsIntelligentTieringAndOperator.AddTags(elem.toAWS());
        }

        return awsIntelligentTieringAndOperator;
    }

    bool IsEmpty() const {
        return this->prefix.IsEmpty() && this->tags.Num() == 0;
    }

    FAWSS3CRTIntelligentTieringAndOperator &fromAWS(const Aws::S3Crt::Model::IntelligentTieringAndOperator &awsIntelligentTieringAndOperator) {
        this->prefix = UTF8_TO_TCHAR(awsIntelligentTieringAndOperator.GetPrefix().c_str());

        this->tags.Empty();
        for (const Aws::S3Crt::Model::Tag& elem : awsIntelligentTieringAndOperator.GetTags()) {
            this->tags.Add(FAWSS3CRTTag().fromAWS(elem));
        }

        return *this;
    }
#endif
};
