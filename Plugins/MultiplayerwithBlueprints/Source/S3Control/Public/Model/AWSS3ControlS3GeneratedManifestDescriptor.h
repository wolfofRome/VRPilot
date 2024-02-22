/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3GeneratedManifestDescriptor.h"

#endif

#include "Model/AWSS3ControlGeneratedManifestFormat.h"
#include "Model/JobManifestLocation.h"

#include "AWSS3ControlS3GeneratedManifestDescriptor.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlS3GeneratedManifestDescriptor {
GENERATED_BODY()

    /**
    *  <p>The format of the generated manifest.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ControlGeneratedManifestFormat format = EAWSS3ControlGeneratedManifestFormat::NOT_SET;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FJobManifestLocation location;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlS3GeneratedManifestDescriptor &fromAWS(const Aws::S3Control::Model::S3GeneratedManifestDescriptor &awsS3GeneratedManifestDescriptor) {
        switch(awsS3GeneratedManifestDescriptor.GetFormat()) {
            case Aws::S3Control::Model::GeneratedManifestFormat::NOT_SET:
                this->format = EAWSS3ControlGeneratedManifestFormat::NOT_SET;
                break;
            case Aws::S3Control::Model::GeneratedManifestFormat::S3InventoryReport_CSV_20211130:
                this->format = EAWSS3ControlGeneratedManifestFormat::S3InventoryReport_CSV_20211130;
                break;
            default:
                this->format = EAWSS3ControlGeneratedManifestFormat::NOT_SET;
                break;
        }

        this->location.fromAWS(awsS3GeneratedManifestDescriptor.GetLocation());

        return *this;
    }
#endif
};
