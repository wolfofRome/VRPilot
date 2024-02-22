/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/S3Grantee.h"

#endif

#include "Model/S3GranteeTypeIdentifier.h"

#include "S3Grantee.generated.h"

USTRUCT(BlueprintType)
struct FS3Grantee {
GENERATED_BODY()

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3GranteeTypeIdentifier typeIdentifier = EAWSS3GranteeTypeIdentifier::NOT_SET;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString identifier;

    /**
    *  <p/>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString displayName;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::S3Grantee toAWS() const {
        Aws::S3Control::Model::S3Grantee awsS3Grantee;

        switch(this->typeIdentifier) {
            case EAWSS3GranteeTypeIdentifier::id:
                awsS3Grantee.SetTypeIdentifier(Aws::S3Control::Model::S3GranteeTypeIdentifier::id);
                break;
            case EAWSS3GranteeTypeIdentifier::emailAddress:
                awsS3Grantee.SetTypeIdentifier(Aws::S3Control::Model::S3GranteeTypeIdentifier::emailAddress);
                break;
            case EAWSS3GranteeTypeIdentifier::uri:
                awsS3Grantee.SetTypeIdentifier(Aws::S3Control::Model::S3GranteeTypeIdentifier::uri);
                break;
            default:
                break;
        }

		if (!(this->identifier.IsEmpty())) {
            awsS3Grantee.SetIdentifier(TCHAR_TO_UTF8(*this->identifier));
        }

		if (!(this->displayName.IsEmpty())) {
            awsS3Grantee.SetDisplayName(TCHAR_TO_UTF8(*this->displayName));
        }

        return awsS3Grantee;
    }

    bool IsEmpty() const {
        return typeIdentifier == EAWSS3GranteeTypeIdentifier::NOT_SET && this->identifier.IsEmpty() && this->displayName.IsEmpty();
    }

    FS3Grantee &fromAWS(const Aws::S3Control::Model::S3Grantee &awsS3Grantee) {
        switch(awsS3Grantee.GetTypeIdentifier()) {
            case Aws::S3Control::Model::S3GranteeTypeIdentifier::NOT_SET:
                this->typeIdentifier = EAWSS3GranteeTypeIdentifier::NOT_SET;
                break;
            case Aws::S3Control::Model::S3GranteeTypeIdentifier::id:
                this->typeIdentifier = EAWSS3GranteeTypeIdentifier::id;
                break;
            case Aws::S3Control::Model::S3GranteeTypeIdentifier::emailAddress:
                this->typeIdentifier = EAWSS3GranteeTypeIdentifier::emailAddress;
                break;
            case Aws::S3Control::Model::S3GranteeTypeIdentifier::uri:
                this->typeIdentifier = EAWSS3GranteeTypeIdentifier::uri;
                break;
            default:
                this->typeIdentifier = EAWSS3GranteeTypeIdentifier::NOT_SET;
                break;
        }

        this->identifier = UTF8_TO_TCHAR(awsS3Grantee.GetIdentifier().c_str());

        this->displayName = UTF8_TO_TCHAR(awsS3Grantee.GetDisplayName().c_str());

        return *this;
    }
#endif
};
