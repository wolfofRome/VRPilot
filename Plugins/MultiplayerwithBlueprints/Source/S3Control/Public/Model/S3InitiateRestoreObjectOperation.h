/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3InitiateRestoreObjectOperation.h"

#endif

#include "Model/S3GlacierJobTier.h"

#include "S3InitiateRestoreObjectOperation.generated.h"

USTRUCT(BlueprintType)
struct FS3InitiateRestoreObjectOperation {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int expirationInDays = 0;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3GlacierJobTier glacierJobTier = EAWSS3GlacierJobTier::NOT_SET;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::S3InitiateRestoreObjectOperation toAWS() const {
        Aws::S3Control::Model::S3InitiateRestoreObjectOperation awsS3InitiateRestoreObjectOperation;

        if (!(this->expirationInDays == 0)) {
            awsS3InitiateRestoreObjectOperation.SetExpirationInDays(this->expirationInDays);
        }

        switch(this->glacierJobTier) {
            case EAWSS3GlacierJobTier::BULK:
                awsS3InitiateRestoreObjectOperation.SetGlacierJobTier(Aws::S3Control::Model::S3GlacierJobTier::BULK);
                break;
            case EAWSS3GlacierJobTier::STANDARD:
                awsS3InitiateRestoreObjectOperation.SetGlacierJobTier(Aws::S3Control::Model::S3GlacierJobTier::STANDARD);
                break;
            default:
                break;
        }

        return awsS3InitiateRestoreObjectOperation;
    }

    bool IsEmpty() const {
        return this->expirationInDays == 0 && glacierJobTier == EAWSS3GlacierJobTier::NOT_SET;
    }

    FS3InitiateRestoreObjectOperation &fromAWS(const Aws::S3Control::Model::S3InitiateRestoreObjectOperation &awsS3InitiateRestoreObjectOperation) {
		this->expirationInDays = awsS3InitiateRestoreObjectOperation.GetExpirationInDays();

        switch(awsS3InitiateRestoreObjectOperation.GetGlacierJobTier()) {
            case Aws::S3Control::Model::S3GlacierJobTier::NOT_SET:
                this->glacierJobTier = EAWSS3GlacierJobTier::NOT_SET;
                break;
            case Aws::S3Control::Model::S3GlacierJobTier::BULK:
                this->glacierJobTier = EAWSS3GlacierJobTier::BULK;
                break;
            case Aws::S3Control::Model::S3GlacierJobTier::STANDARD:
                this->glacierJobTier = EAWSS3GlacierJobTier::STANDARD;
                break;
            default:
                this->glacierJobTier = EAWSS3GlacierJobTier::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
