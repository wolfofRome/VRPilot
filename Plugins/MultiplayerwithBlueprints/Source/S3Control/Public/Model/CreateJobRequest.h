/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/CreateJobRequest.h"

#endif

#include "Model/JobOperation.h"
#include "Model/JobReport.h"
#include "Model/JobManifest.h"
#include "Model/S3ControlS3Tag.h"
#include "Model/AWSS3ControlJobManifestGenerator.h"

#include "CreateJobRequest.generated.h"

USTRUCT(BlueprintType)
struct FCreateJobRequest {
GENERATED_BODY()

    /**
    *  <p>The Amazon Web Services account ID that creates the job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString accountId;

    /**
    *  <p>Indicates whether confirmation is required before Amazon S3 runs the job. Confirmation is only required for jobs created through the Amazon S3 console.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool confirmationRequired = false;

    /**
    *  <p>The operation that you want this job to perform on each object listed in the manifest. For more information about the available operations, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/batch-ops-operations.html">Available Operations</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FJobOperation operation;

    /**
    *  <p>Configuration parameters for the optional job-completion report.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FJobReport report;

    /**
    *  <p>An idempotency token to ensure that you don't accidentally submit the same request twice. You can use any string up to the maximum length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString clientRequestToken;

    /**
    *  <p>Configuration parameters for the manifest.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FJobManifest manifest;

    /**
    *  <p>A description for this job. You can use any string within the permitted length. Descriptions don't need to be unique and can be used for multiple jobs.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString description;

    /**
    *  <p>The numerical priority for this job. Higher numbers indicate higher priority.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int priority = 0;

    /**
    *  <p>The Amazon Resource Name (ARN) for the Identity and Access Management (IAM) role that Batch Operations will use to run this job's action on every object in the manifest.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString roleArn;

    /**
    *  <p>A set of tags to associate with the S3 Batch Operations job. This is an optional parameter. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FS3ControlS3Tag> tags;

    /**
    *  <p>The attribute container for the ManifestGenerator details. Jobs must be created with either a manifest file or a ManifestGenerator, but not both.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlJobManifestGenerator manifestGenerator;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::CreateJobRequest toAWS() const {
        Aws::S3Control::Model::CreateJobRequest awsCreateJobRequest;

		if (!(this->accountId.IsEmpty())) {
            awsCreateJobRequest.SetAccountId(TCHAR_TO_UTF8(*this->accountId));
        }

        if (!(false)) {
            awsCreateJobRequest.SetConfirmationRequired(this->confirmationRequired);
        }

        if (!(this->operation.IsEmpty())) {
            awsCreateJobRequest.SetOperation(this->operation.toAWS());
        }

        if (!(this->report.IsEmpty())) {
            awsCreateJobRequest.SetReport(this->report.toAWS());
        }

		if (!(this->clientRequestToken.IsEmpty())) {
            awsCreateJobRequest.SetClientRequestToken(TCHAR_TO_UTF8(*this->clientRequestToken));
        }

        if (!(this->manifest.IsEmpty())) {
            awsCreateJobRequest.SetManifest(this->manifest.toAWS());
        }

		if (!(this->description.IsEmpty())) {
            awsCreateJobRequest.SetDescription(TCHAR_TO_UTF8(*this->description));
        }

        if (!(this->priority == 0)) {
            awsCreateJobRequest.SetPriority(this->priority);
        }

		if (!(this->roleArn.IsEmpty())) {
            awsCreateJobRequest.SetRoleArn(TCHAR_TO_UTF8(*this->roleArn));
        }

        for (const FS3ControlS3Tag& elem : this->tags) {
            awsCreateJobRequest.AddTags(elem.toAWS());
        }

        if (!(this->manifestGenerator.IsEmpty())) {
            awsCreateJobRequest.SetManifestGenerator(this->manifestGenerator.toAWS());
        }

        return awsCreateJobRequest;
    }

    bool IsEmpty() const {
        return this->accountId.IsEmpty() && false && this->operation.IsEmpty() && this->report.IsEmpty() && this->clientRequestToken.IsEmpty() && this->manifest.IsEmpty() && this->description.IsEmpty() && this->priority == 0 && this->roleArn.IsEmpty() && this->tags.Num() == 0 && this->manifestGenerator.IsEmpty();
    }
#endif
};
