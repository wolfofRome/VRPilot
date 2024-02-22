/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/Exclude.h"

#endif

#include "AWSS3ControlExclude.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlExclude {
GENERATED_BODY()

    /**
    *  <p>A container for the S3 Storage Lens bucket excludes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FString> buckets;

    /**
    *  <p>A container for the S3 Storage Lens Region excludes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FString> regions;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::Exclude toAWS() const {
        Aws::S3Control::Model::Exclude awsExclude;

        for (const FString& elem : this->buckets) {
            awsExclude.AddBuckets(TCHAR_TO_UTF8(*elem));
        }

        for (const FString& elem : this->regions) {
            awsExclude.AddRegions(TCHAR_TO_UTF8(*elem));
        }

        return awsExclude;
    }

    bool IsEmpty() const {
        return this->buckets.Num() == 0 && this->regions.Num() == 0;
    }

    FAWSS3ControlExclude &fromAWS(const Aws::S3Control::Model::Exclude &awsExclude) {
        this->buckets.Empty();
        for (const Aws::String& elem : awsExclude.GetBuckets()) {
            this->buckets.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->regions.Empty();
        for (const Aws::String& elem : awsExclude.GetRegions()) {
            this->regions.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        return *this;
    }
#endif
};
