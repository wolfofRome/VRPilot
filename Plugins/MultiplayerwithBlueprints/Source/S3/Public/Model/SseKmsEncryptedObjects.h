/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/SseKmsEncryptedObjects.h"

#endif

#include "Model/SseKmsEncryptedObjectsStatus.h"

#include "SseKmsEncryptedObjects.generated.h"

USTRUCT(BlueprintType)
struct FSseKmsEncryptedObjects {
GENERATED_BODY()

    /**
    *  <p>Specifies whether Amazon S3 replicates objects created with server-side encryption using a customer master key (CMK) stored in AWS Key Management Service.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSSseKmsEncryptedObjectsStatus status = EAWSSseKmsEncryptedObjectsStatus::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::SseKmsEncryptedObjects toAWS() const {
        Aws::S3::Model::SseKmsEncryptedObjects awsSseKmsEncryptedObjects;

        switch(this->status) {
            case EAWSSseKmsEncryptedObjectsStatus::Enabled:
                awsSseKmsEncryptedObjects.SetStatus(Aws::S3::Model::SseKmsEncryptedObjectsStatus::Enabled);
                break;
            case EAWSSseKmsEncryptedObjectsStatus::Disabled:
                awsSseKmsEncryptedObjects.SetStatus(Aws::S3::Model::SseKmsEncryptedObjectsStatus::Disabled);
                break;
            default:
                break;
        }

        return awsSseKmsEncryptedObjects;
    }

    bool IsEmpty() const {
        return status == EAWSSseKmsEncryptedObjectsStatus::NOT_SET;
    }

    FSseKmsEncryptedObjects &fromAWS(const Aws::S3::Model::SseKmsEncryptedObjects &awsSseKmsEncryptedObjects) {
        switch(awsSseKmsEncryptedObjects.GetStatus()) {
            case Aws::S3::Model::SseKmsEncryptedObjectsStatus::NOT_SET:
                this->status = EAWSSseKmsEncryptedObjectsStatus::NOT_SET;
                break;
            case Aws::S3::Model::SseKmsEncryptedObjectsStatus::Enabled:
                this->status = EAWSSseKmsEncryptedObjectsStatus::Enabled;
                break;
            case Aws::S3::Model::SseKmsEncryptedObjectsStatus::Disabled:
                this->status = EAWSSseKmsEncryptedObjectsStatus::Disabled;
                break;
            default:
                this->status = EAWSSseKmsEncryptedObjectsStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
