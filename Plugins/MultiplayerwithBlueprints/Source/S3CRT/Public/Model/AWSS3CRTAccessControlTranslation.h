/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/AccessControlTranslation.h"

#endif

#include "Model/AWSS3CRTOwnerOverride.h"

#include "AWSS3CRTAccessControlTranslation.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTAccessControlTranslation {
GENERATED_BODY()

    /**
    *  <p>Specifies the replica ownership. For default and valid values, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/RESTBucketPUTreplication.html">PUT bucket replication</a> in the <i>Amazon Simple Storage Service API Reference</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTOwnerOverride owner = EAWSS3CRTOwnerOverride::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::AccessControlTranslation toAWS() const {
        Aws::S3Crt::Model::AccessControlTranslation awsAccessControlTranslation;

        switch(this->owner) {
            case EAWSS3CRTOwnerOverride::Destination:
                awsAccessControlTranslation.SetOwner(Aws::S3Crt::Model::OwnerOverride::Destination);
                break;
            default:
                break;
        }

        return awsAccessControlTranslation;
    }

    bool IsEmpty() const {
        return this->owner == EAWSS3CRTOwnerOverride::NOT_SET;
    }

    FAWSS3CRTAccessControlTranslation &fromAWS(const Aws::S3Crt::Model::AccessControlTranslation &awsAccessControlTranslation) {
        switch(awsAccessControlTranslation.GetOwner()) {
            case Aws::S3Crt::Model::OwnerOverride::NOT_SET:
                this->owner = EAWSS3CRTOwnerOverride::NOT_SET;
                break;
            case Aws::S3Crt::Model::OwnerOverride::Destination:
                this->owner = EAWSS3CRTOwnerOverride::Destination;
                break;
            default:
                this->owner = EAWSS3CRTOwnerOverride::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
