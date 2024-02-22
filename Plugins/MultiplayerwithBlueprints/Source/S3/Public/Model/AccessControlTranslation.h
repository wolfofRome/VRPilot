/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/AccessControlTranslation.h"

#endif

#include "Model/OwnerOverride.h"

#include "AccessControlTranslation.generated.h"

USTRUCT(BlueprintType)
struct FAccessControlTranslation {
GENERATED_BODY()

    /**
    *  <p>Specifies the replica ownership. For default and valid values, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/API/RESTBucketPUTreplication.html">PUT bucket replication</a> in the <i>Amazon Simple Storage Service API Reference</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSOwnerOverride owner = EAWSOwnerOverride::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::AccessControlTranslation toAWS() const {
        Aws::S3::Model::AccessControlTranslation awsAccessControlTranslation;

        switch(this->owner) {
            case EAWSOwnerOverride::Destination:
                awsAccessControlTranslation.SetOwner(Aws::S3::Model::OwnerOverride::Destination);
                break;
            default:
                break;
        }

        return awsAccessControlTranslation;
    }

    bool IsEmpty() const {
        return owner == EAWSOwnerOverride::NOT_SET;
    }

    FAccessControlTranslation &fromAWS(const Aws::S3::Model::AccessControlTranslation &awsAccessControlTranslation) {
        switch(awsAccessControlTranslation.GetOwner()) {
            case Aws::S3::Model::OwnerOverride::NOT_SET:
                this->owner = EAWSOwnerOverride::NOT_SET;
                break;
            case Aws::S3::Model::OwnerOverride::Destination:
                this->owner = EAWSOwnerOverride::Destination;
                break;
            default:
                this->owner = EAWSOwnerOverride::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
