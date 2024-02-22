/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/SseKmsEncryptedObjects.h"

#endif

#include "Model/AWSS3CRTSseKmsEncryptedObjectsStatus.h"

#include "AWSS3CRTSseKmsEncryptedObjects.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTSseKmsEncryptedObjects {
GENERATED_BODY()

    /**
    *  <p>Specifies whether Amazon S3 replicates objects created with server-side encryption using a customer master key (CMK) stored in AWS Key Management Service.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTSseKmsEncryptedObjectsStatus status = EAWSS3CRTSseKmsEncryptedObjectsStatus::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::SseKmsEncryptedObjects toAWS() const {
        Aws::S3Crt::Model::SseKmsEncryptedObjects awsSseKmsEncryptedObjects;

        switch(this->status) {
            case EAWSS3CRTSseKmsEncryptedObjectsStatus::Enabled:
                awsSseKmsEncryptedObjects.SetStatus(Aws::S3Crt::Model::SseKmsEncryptedObjectsStatus::Enabled);
                break;
            case EAWSS3CRTSseKmsEncryptedObjectsStatus::Disabled:
                awsSseKmsEncryptedObjects.SetStatus(Aws::S3Crt::Model::SseKmsEncryptedObjectsStatus::Disabled);
                break;
            default:
                break;
        }

        return awsSseKmsEncryptedObjects;
    }

    bool IsEmpty() const {
        return this->status == EAWSS3CRTSseKmsEncryptedObjectsStatus::NOT_SET;
    }

    FAWSS3CRTSseKmsEncryptedObjects &fromAWS(const Aws::S3Crt::Model::SseKmsEncryptedObjects &awsSseKmsEncryptedObjects) {
        switch(awsSseKmsEncryptedObjects.GetStatus()) {
            case Aws::S3Crt::Model::SseKmsEncryptedObjectsStatus::NOT_SET:
                this->status = EAWSS3CRTSseKmsEncryptedObjectsStatus::NOT_SET;
                break;
            case Aws::S3Crt::Model::SseKmsEncryptedObjectsStatus::Enabled:
                this->status = EAWSS3CRTSseKmsEncryptedObjectsStatus::Enabled;
                break;
            case Aws::S3Crt::Model::SseKmsEncryptedObjectsStatus::Disabled:
                this->status = EAWSS3CRTSseKmsEncryptedObjectsStatus::Disabled;
                break;
            default:
                this->status = EAWSS3CRTSseKmsEncryptedObjectsStatus::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
