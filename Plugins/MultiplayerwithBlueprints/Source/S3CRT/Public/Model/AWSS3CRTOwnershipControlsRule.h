/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/OwnershipControlsRule.h"

#endif

#include "Model/AWSS3CRTObjectOwnership.h"

#include "AWSS3CRTOwnershipControlsRule.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTOwnershipControlsRule {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTObjectOwnership objectOwnership = EAWSS3CRTObjectOwnership::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::OwnershipControlsRule toAWS() const {
        Aws::S3Crt::Model::OwnershipControlsRule awsOwnershipControlsRule;

        switch(this->objectOwnership) {
            case EAWSS3CRTObjectOwnership::BucketOwnerPreferred:
                awsOwnershipControlsRule.SetObjectOwnership(Aws::S3Crt::Model::ObjectOwnership::BucketOwnerPreferred);
                break;
            case EAWSS3CRTObjectOwnership::ObjectWriter:
                awsOwnershipControlsRule.SetObjectOwnership(Aws::S3Crt::Model::ObjectOwnership::ObjectWriter);
                break;
            default:
                break;
        }

        return awsOwnershipControlsRule;
    }

    bool IsEmpty() const {
        return this->objectOwnership == EAWSS3CRTObjectOwnership::NOT_SET;
    }

    FAWSS3CRTOwnershipControlsRule &fromAWS(const Aws::S3Crt::Model::OwnershipControlsRule &awsOwnershipControlsRule) {
        switch(awsOwnershipControlsRule.GetObjectOwnership()) {
            case Aws::S3Crt::Model::ObjectOwnership::NOT_SET:
                this->objectOwnership = EAWSS3CRTObjectOwnership::NOT_SET;
                break;
            case Aws::S3Crt::Model::ObjectOwnership::BucketOwnerPreferred:
                this->objectOwnership = EAWSS3CRTObjectOwnership::BucketOwnerPreferred;
                break;
            case Aws::S3Crt::Model::ObjectOwnership::ObjectWriter:
                this->objectOwnership = EAWSS3CRTObjectOwnership::ObjectWriter;
                break;
            default:
                this->objectOwnership = EAWSS3CRTObjectOwnership::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
