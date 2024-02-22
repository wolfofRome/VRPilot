/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/Include.h"

#endif

#include "AWSS3ControlInclude.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlInclude {
GENERATED_BODY()

    /**
    *  <p>A container for the S3 Storage Lens bucket includes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FString> buckets;

    /**
    *  <p>A container for the S3 Storage Lens Region includes.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FString> regions;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::Include toAWS() const {
        Aws::S3Control::Model::Include awsInclude;

        for (const FString& elem : this->buckets) {
            awsInclude.AddBuckets(TCHAR_TO_UTF8(*elem));
        }

        for (const FString& elem : this->regions) {
            awsInclude.AddRegions(TCHAR_TO_UTF8(*elem));
        }

        return awsInclude;
    }

    bool IsEmpty() const {
        return this->buckets.Num() == 0 && this->regions.Num() == 0;
    }

    FAWSS3ControlInclude &fromAWS(const Aws::S3Control::Model::Include &awsInclude) {
        this->buckets.Empty();
        for (const Aws::String& elem : awsInclude.GetBuckets()) {
            this->buckets.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        this->regions.Empty();
        for (const Aws::String& elem : awsInclude.GetRegions()) {
            this->regions.Add(UTF8_TO_TCHAR(elem.c_str()));
        }

        return *this;
    }
#endif
};
