/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3JobManifestGenerator.h"

#endif

#include "Model/AWSS3ControlS3ManifestOutputLocation.h"
#include "Model/AWSS3ControlJobManifestGeneratorFilter.h"

#include "AWSS3ControlS3JobManifestGenerator.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlS3JobManifestGenerator {
GENERATED_BODY()

    /**
    *  <p>The Amazon Web Services account ID that owns the bucket the generated manifest is written to. If provided the generated manifest bucket's owner Amazon Web Services account ID must match this value, else the job fails.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString expectedBucketOwner;

    /**
    *  <p>The source bucket used by the ManifestGenerator.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString sourceBucket;

    /**
    *  <p>Specifies the location the generated manifest will be written to.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlS3ManifestOutputLocation manifestOutputLocation;

    /**
    *  <p>Specifies rules the S3JobManifestGenerator should use to use to decide whether an object in the source bucket should or should not be included in the generated job manifest.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlJobManifestGeneratorFilter filter;

    /**
    *  <p>Determines whether or not to write the job's generated manifest to a bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool enableManifestOutput = false;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::S3JobManifestGenerator toAWS() const {
        Aws::S3Control::Model::S3JobManifestGenerator awsS3JobManifestGenerator;

        if (!(this->expectedBucketOwner.IsEmpty())) {
            awsS3JobManifestGenerator.SetExpectedBucketOwner(TCHAR_TO_UTF8(*this->expectedBucketOwner));
        }

        if (!(this->sourceBucket.IsEmpty())) {
            awsS3JobManifestGenerator.SetSourceBucket(TCHAR_TO_UTF8(*this->sourceBucket));
        }

        if (!(this->manifestOutputLocation.IsEmpty())) {
            awsS3JobManifestGenerator.SetManifestOutputLocation(this->manifestOutputLocation.toAWS());
        }

        if (!(this->filter.IsEmpty())) {
            awsS3JobManifestGenerator.SetFilter(this->filter.toAWS());
        }

        awsS3JobManifestGenerator.SetEnableManifestOutput(this->enableManifestOutput);

        return awsS3JobManifestGenerator;
    }

    bool IsEmpty() const {
        return this->expectedBucketOwner.IsEmpty() && this->sourceBucket.IsEmpty() && this->manifestOutputLocation.IsEmpty() && this->filter.IsEmpty() && false;
    }

    FAWSS3ControlS3JobManifestGenerator &fromAWS(const Aws::S3Control::Model::S3JobManifestGenerator &awsS3JobManifestGenerator) {
        this->expectedBucketOwner = UTF8_TO_TCHAR(awsS3JobManifestGenerator.GetExpectedBucketOwner().c_str());

        this->sourceBucket = UTF8_TO_TCHAR(awsS3JobManifestGenerator.GetSourceBucket().c_str());

        this->manifestOutputLocation.fromAWS(awsS3JobManifestGenerator.GetManifestOutputLocation());

        this->filter.fromAWS(awsS3JobManifestGenerator.GetFilter());

        this->enableManifestOutput = awsS3JobManifestGenerator.GetEnableManifestOutput();

        return *this;
    }
#endif
};
