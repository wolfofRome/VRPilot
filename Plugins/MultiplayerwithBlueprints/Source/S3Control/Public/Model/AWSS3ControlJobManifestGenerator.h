/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/JobManifestGenerator.h"

#endif

#include "Model/AWSS3ControlS3JobManifestGenerator.h"

#include "AWSS3ControlJobManifestGenerator.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlJobManifestGenerator {
GENERATED_BODY()

    /**
    *  <p>The S3 job ManifestGenerator's configuration details.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlS3JobManifestGenerator s3JobManifestGenerator;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::JobManifestGenerator toAWS() const {
        Aws::S3Control::Model::JobManifestGenerator awsJobManifestGenerator;

        if (!(this->s3JobManifestGenerator.IsEmpty())) {
            awsJobManifestGenerator.SetS3JobManifestGenerator(this->s3JobManifestGenerator.toAWS());
        }

        return awsJobManifestGenerator;
    }

    bool IsEmpty() const {
        return this->s3JobManifestGenerator.IsEmpty();
    }

    FAWSS3ControlJobManifestGenerator &fromAWS(const Aws::S3Control::Model::JobManifestGenerator &awsJobManifestGenerator) {
        this->s3JobManifestGenerator.fromAWS(awsJobManifestGenerator.GetS3JobManifestGenerator());

        return *this;
    }
#endif
};
