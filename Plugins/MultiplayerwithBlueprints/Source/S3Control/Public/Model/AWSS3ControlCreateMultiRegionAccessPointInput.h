/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/CreateMultiRegionAccessPointInput.h"

#endif

#include "Model/S3ControlPublicAccessBlockConfiguration.h"
#include "Model/AWSS3ControlRegion.h"

#include "AWSS3ControlCreateMultiRegionAccessPointInput.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlCreateMultiRegionAccessPointInput {
GENERATED_BODY()

    /**
    *  <p>The name of the Multi-Region Access Point associated with this request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3ControlPublicAccessBlockConfiguration publicAccessBlock;

    /**
    *  <p>The buckets in different Regions that are associated with the Multi-Region Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FAWSS3ControlRegion> regions;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::CreateMultiRegionAccessPointInput toAWS() const {
        Aws::S3Control::Model::CreateMultiRegionAccessPointInput awsCreateMultiRegionAccessPointInput;

        if (!(this->name.IsEmpty())) {
            awsCreateMultiRegionAccessPointInput.SetName(TCHAR_TO_UTF8(*this->name));
        }

        if (!(this->publicAccessBlock.IsEmpty())) {
            awsCreateMultiRegionAccessPointInput.SetPublicAccessBlock(this->publicAccessBlock.toAWS());
        }

        for (const FAWSS3ControlRegion& elem : this->regions) {
            awsCreateMultiRegionAccessPointInput.AddRegions(elem.toAWS());
        }

        return awsCreateMultiRegionAccessPointInput;
    }

    bool IsEmpty() const {
        return this->name.IsEmpty() && this->publicAccessBlock.IsEmpty() && this->regions.Num() == 0;
    }

    FAWSS3ControlCreateMultiRegionAccessPointInput &fromAWS(const Aws::S3Control::Model::CreateMultiRegionAccessPointInput &awsCreateMultiRegionAccessPointInput) {
        this->name = UTF8_TO_TCHAR(awsCreateMultiRegionAccessPointInput.GetName().c_str());

        this->publicAccessBlock.fromAWS(awsCreateMultiRegionAccessPointInput.GetPublicAccessBlock());

        this->regions.Empty();
        for (const Aws::S3Control::Model::Region& elem : awsCreateMultiRegionAccessPointInput.GetRegions()) {
            this->regions.Add(FAWSS3ControlRegion().fromAWS(elem));
        }

        return *this;
    }
#endif
};
