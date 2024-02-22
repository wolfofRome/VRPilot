/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Grantee.h"

#endif

#include "Model/AWSS3CRTType.h"

#include "AWSS3CRTGrantee.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGrantee {
GENERATED_BODY()

    /**
    *  <p>Screen name of the grantee.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString displayName;

    /**
    *  <p>Email address of the grantee.</p>  <p>Using email addresses to specify a grantee is only supported in the following AWS Regions: </p> <ul> <li> <p>US East (N. Virginia)</p> </li> <li> <p>US West (N. California)</p> </li> <li> <p> US West (Oregon)</p> </li> <li> <p> Asia Pacific (Singapore)</p> </li> <li> <p>Asia Pacific (Sydney)</p> </li> <li> <p>Asia Pacific (Tokyo)</p> </li> <li> <p>Europe (Ireland)</p> </li> <li> <p>South America (São Paulo)</p> </li> </ul> <p>For a list of all the Amazon S3 supported Regions and endpoints, see <a href="https://docs.aws.amazon.com/general/latest/gr/rande.html#s3_region">Regions and Endpoints</a> in the AWS General Reference.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString emailAddress;

    /**
    *  <p>The canonical user ID of the grantee.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString iD;

    /**
    *  <p>Type of grantee</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTType type = EAWSS3CRTType::NOT_SET;

    /**
    *  <p>URI of the grantee group.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString uRI;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::Grantee toAWS() const {
        Aws::S3Crt::Model::Grantee awsGrantee;

        if (!(this->displayName.IsEmpty())) {
            awsGrantee.SetDisplayName(TCHAR_TO_UTF8(*this->displayName));
        }

        if (!(this->emailAddress.IsEmpty())) {
            awsGrantee.SetEmailAddress(TCHAR_TO_UTF8(*this->emailAddress));
        }

        if (!(this->iD.IsEmpty())) {
            awsGrantee.SetID(TCHAR_TO_UTF8(*this->iD));
        }

        switch(this->type) {
            case EAWSS3CRTType::CanonicalUser:
                awsGrantee.SetType(Aws::S3Crt::Model::Type::CanonicalUser);
                break;
            case EAWSS3CRTType::AmazonCustomerByEmail:
                awsGrantee.SetType(Aws::S3Crt::Model::Type::AmazonCustomerByEmail);
                break;
            case EAWSS3CRTType::Group:
                awsGrantee.SetType(Aws::S3Crt::Model::Type::Group);
                break;
            default:
                break;
        }

        if (!(this->uRI.IsEmpty())) {
            awsGrantee.SetURI(TCHAR_TO_UTF8(*this->uRI));
        }

        return awsGrantee;
    }

    bool IsEmpty() const {
        return this->displayName.IsEmpty() && this->emailAddress.IsEmpty() && this->iD.IsEmpty() && this->type == EAWSS3CRTType::NOT_SET && this->uRI.IsEmpty();
    }

    FAWSS3CRTGrantee &fromAWS(const Aws::S3Crt::Model::Grantee &awsGrantee) {
        this->displayName = UTF8_TO_TCHAR(awsGrantee.GetDisplayName().c_str());

        this->emailAddress = UTF8_TO_TCHAR(awsGrantee.GetEmailAddress().c_str());

        this->iD = UTF8_TO_TCHAR(awsGrantee.GetID().c_str());

        switch(awsGrantee.GetType()) {
            case Aws::S3Crt::Model::Type::NOT_SET:
                this->type = EAWSS3CRTType::NOT_SET;
                break;
            case Aws::S3Crt::Model::Type::CanonicalUser:
                this->type = EAWSS3CRTType::CanonicalUser;
                break;
            case Aws::S3Crt::Model::Type::AmazonCustomerByEmail:
                this->type = EAWSS3CRTType::AmazonCustomerByEmail;
                break;
            case Aws::S3Crt::Model::Type::Group:
                this->type = EAWSS3CRTType::Group;
                break;
            default:
                this->type = EAWSS3CRTType::NOT_SET;
                break;
        }

        this->uRI = UTF8_TO_TCHAR(awsGrantee.GetURI().c_str());

        return *this;
    }
#endif
};
