/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/OwnershipControlsRule.h"

#endif

#include "Model/AWSS3ObjectOwnership.h"

#include "AWSS3OwnershipControlsRule.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3OwnershipControlsRule {
GENERATED_BODY()

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3ObjectOwnership objectOwnership = EAWSS3ObjectOwnership::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::OwnershipControlsRule toAWS() const {
        Aws::S3::Model::OwnershipControlsRule awsOwnershipControlsRule;

        switch(this->objectOwnership) {
            case EAWSS3ObjectOwnership::BucketOwnerPreferred:
                awsOwnershipControlsRule.SetObjectOwnership(Aws::S3::Model::ObjectOwnership::BucketOwnerPreferred);
                break;
            case EAWSS3ObjectOwnership::ObjectWriter:
                awsOwnershipControlsRule.SetObjectOwnership(Aws::S3::Model::ObjectOwnership::ObjectWriter);
                break;
            case EAWSS3ObjectOwnership::BucketOwnerEnforced:
                awsOwnershipControlsRule.SetObjectOwnership(Aws::S3::Model::ObjectOwnership::BucketOwnerEnforced);
                break;
            default:
                break;
        }

        return awsOwnershipControlsRule;
    }

    bool IsEmpty() const {
        return this->objectOwnership == EAWSS3ObjectOwnership::NOT_SET;
    }

    FAWSS3OwnershipControlsRule &fromAWS(const Aws::S3::Model::OwnershipControlsRule &awsOwnershipControlsRule) {
        switch(awsOwnershipControlsRule.GetObjectOwnership()) {
            case Aws::S3::Model::ObjectOwnership::NOT_SET:
                this->objectOwnership = EAWSS3ObjectOwnership::NOT_SET;
                break;
            case Aws::S3::Model::ObjectOwnership::BucketOwnerPreferred:
                this->objectOwnership = EAWSS3ObjectOwnership::BucketOwnerPreferred;
                break;
            case Aws::S3::Model::ObjectOwnership::ObjectWriter:
                this->objectOwnership = EAWSS3ObjectOwnership::ObjectWriter;
                break;
            case Aws::S3::Model::ObjectOwnership::BucketOwnerEnforced:
                this->objectOwnership = EAWSS3ObjectOwnership::BucketOwnerEnforced;
                break;
            default:
                this->objectOwnership = EAWSS3ObjectOwnership::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
