/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/RestoreRequest.h"

#endif

#include "Model/GlacierJobParameters.h"
#include "Model/RestoreRequestType.h"
#include "Model/Tier.h"
#include "Model/SelectParameters.h"
#include "Model/OutputLocation.h"

#include "RestoreRequest.generated.h"

USTRUCT(BlueprintType)
struct FRestoreRequest {
GENERATED_BODY()

    /**
    *  <p>Lifetime of the active copy in days. Do not use with restores that specify <code>OutputLocation</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    int days = 0;

    /**
    *  <p>S3 Glacier related parameters pertaining to this job. Do not use with restores that specify <code>OutputLocation</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FGlacierJobParameters glacierJobParameters;

    /**
    *  <p>Type of restore request.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRestoreRequestType type = EAWSRestoreRequestType::NOT_SET;

    /**
    *  <p>S3 Glacier retrieval tier at which the restore will be processed.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSTier tier = EAWSTier::NOT_SET;

    /**
    *  <p>The optional description for the job.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString description;

    /**
    *  <p>Describes the parameters for Select job types.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FSelectParameters selectParameters;

    /**
    *  <p>Describes the location where the restore job's output is stored.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FOutputLocation outputLocation;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::RestoreRequest toAWS() const {
        Aws::S3::Model::RestoreRequest awsRestoreRequest;

        if (!(this->days == 0)) {
            awsRestoreRequest.SetDays(this->days);
        }

        if (!(this->glacierJobParameters.IsEmpty())) {
            awsRestoreRequest.SetGlacierJobParameters(this->glacierJobParameters.toAWS());
        }

        switch(this->type) {
            case EAWSRestoreRequestType::SELECT:
                awsRestoreRequest.SetType(Aws::S3::Model::RestoreRequestType::SELECT);
                break;
            default:
                break;
        }

        switch(this->tier) {
            case EAWSTier::Standard:
                awsRestoreRequest.SetTier(Aws::S3::Model::Tier::Standard);
                break;
            case EAWSTier::Bulk:
                awsRestoreRequest.SetTier(Aws::S3::Model::Tier::Bulk);
                break;
            case EAWSTier::Expedited:
                awsRestoreRequest.SetTier(Aws::S3::Model::Tier::Expedited);
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
        return this->days == 0 && this->glacierJobParameters.IsEmpty() && type == EAWSRestoreRequestType::NOT_SET && tier == EAWSTier::NOT_SET && this->description.IsEmpty() && this->selectParameters.IsEmpty() && this->outputLocation.IsEmpty();
    }
#endif
};
