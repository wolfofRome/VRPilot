/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/JobManifest.h"

#endif

#include "Model/JobManifestSpec.h"
#include "Model/JobManifestLocation.h"

#include "JobManifest.generated.h"

USTRUCT(BlueprintType)
struct FJobManifest {
GENERATED_BODY()

    /**
    *  <p>Describes the format of the specified job's manifest. If the manifest is in CSV format, also describes the columns contained within the manifest.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FJobManifestSpec spec;

    /**
    *  <p>Contains the information required to locate the specified job's manifest.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FJobManifestLocation location;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::JobManifest toAWS() const {
        Aws::S3Control::Model::JobManifest awsJobManifest;

        if (!(this->spec.IsEmpty())) {
            awsJobManifest.SetSpec(this->spec.toAWS());
        }

        if (!(this->location.IsEmpty())) {
            awsJobManifest.SetLocation(this->location.toAWS());
        }

        return awsJobManifest;
    }

    bool IsEmpty() const {
        return this->spec.IsEmpty() && this->location.IsEmpty();
    }

    FJobManifest &fromAWS(const Aws::S3Control::Model::JobManifest &awsJobManifest) {
        this->spec.fromAWS(awsJobManifest.GetSpec());

        this->location.fromAWS(awsJobManifest.GetLocation());

        return *this;
    }
#endif
};
