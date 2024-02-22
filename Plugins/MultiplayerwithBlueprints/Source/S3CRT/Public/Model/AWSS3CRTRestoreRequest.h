/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/RestoreRequest.h"

#endif

#include "Model/AWSS3CRTGlacierJobParameters.h"
#include "Model/AWSS3CRTRestoreRequestType.h"
#include "Model/AWSS3CRTTier.h"
#include "Model/AWSS3CRTSelectParameters.h"
#include "Model/AWSS3CRTOutputLocation.h"

#include "AWSS3CRTRestoreRequest.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTRestoreRequest {
GENERATED_BODY()

    /**
    *  <p>Lifetime of the active copy in days. Do not use with restores that specify <code>OutputLocation</code>.</p> <p>The Days element is required for regular restores, and must not be provided for select requests.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int days = 0;

    /**
    *  <p>S3 Glacier related parameters pertaining to this job. Do not use with restores that specify <code>OutputLocation</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTGlacierJobParameters glacierJobParameters;

    /**
    *  <p>Type of restore request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRestoreRequestType type = EAWSS3CRTRestoreRequestType::NOT_SET;

    /**
    *  <p>Retrieval tier at which the restore will be processed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTTier tier = EAWSS3CRTTier::NOT_SET;

    /**
    *  <p>The optional description for the job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString description;

    /**
    *  <p>Describes the parameters for Select job types.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTSelectParameters selectParameters;

    /**
    *  <p>Describes the location where the restore job's output is stored.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTOutputLocation outputLocation;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::RestoreRequest toAWS() const {
        Aws::S3Crt::Model::RestoreRequest awsRestoreRequest;

        if (!(this->days == 0)) {
            awsRestoreRequest.SetDays(this->days);
        }

        if (!(this->glacierJobParameters.IsEmpty())) {
            awsRestoreRequest.SetGlacierJobParameters(this->glacierJobParameters.toAWS());
        }

        switch(this->type) {
            case EAWSS3CRTRestoreRequestType::SELECT:
                awsRestoreRequest.SetType(Aws::S3Crt::Model::RestoreRequestType::SELECT);
                break;
            default:
                break;
        }

        switch(this->tier) {
            case EAWSS3CRTTier::Standard:
                awsRestoreRequest.SetTier(Aws::S3Crt::Model::Tier::Standard);
                break;
            case EAWSS3CRTTier::Bulk:
                awsRestoreRequest.SetTier(Aws::S3Crt::Model::Tier::Bulk);
                break;
            case EAWSS3CRTTier::Expedited:
                awsRestoreRequest.SetTier(Aws::S3Crt::Model::Tier::Expedited);
                break;
            default:
                break;
        }

        if (!(this->description.IsEmpty())) {
            awsRestoreRequest.SetDescription(TCHAR_TO_UTF8(*this->description));
        }

        if (!(this->selectParameters.IsEmpty())) {
            awsRestoreRequest.SetSelectParameters(this->selectParameters.toAWS());
        }

        if (!(this->outputLocation.IsEmpty())) {
            awsRestoreRequest.SetOutputLocation(this->outputLocation.toAWS());
        }

        return awsRestoreRequest;
    }

    bool IsEmpty() const {
        return this->days == 0 && this->glacierJobParameters.IsEmpty() && this->type == EAWSS3CRTRestoreRequestType::NOT_SET && this->tier == EAWSS3CRTTier::NOT_SET && this->description.IsEmpty() && this->selectParameters.IsEmpty() && this->outputLocation.IsEmpty();
    }
#endif
};
