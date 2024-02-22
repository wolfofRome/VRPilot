/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/Grantee.h"

#endif

#include "Model/Type.h"

#include "Grantee.generated.h"

USTRUCT(BlueprintType)
struct FGrantee {
GENERATED_BODY()

    /**
    *  <p>Screen name of the grantee.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString displayName;

    /**
    *  <p>Email address of the grantee.</p>  <p>Using email addresses to specify a grantee is only supported in the following AWS Regions: </p> <ul> <li> <p>US East (N. Virginia)</p> </li> <li> <p>US West (N. California)</p> </li> <li> <p> US West (Oregon)</p> </li> <li> <p> Asia Pacific (Singapore)</p> </li> <li> <p>Asia Pacific (Sydney)</p> </li> <li> <p>Asia Pacific (Tokyo)</p> </li> <li> <p>Europe (Ireland)</p> </li> <li> <p>South America (São Paulo)</p> </li> </ul> <p>For a list of all the Amazon S3 supported Regions and endpoints, see <a href="https://docs.aws.amazon.com/general/latest/gr/rande.html#s3_region">Regions and Endpoints</a> in the AWS General Reference.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString emailAddress;

    /**
    *  <p>The canonical user ID of the grantee.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString iD;

    /**
    *  <p>Type of grantee</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSType type = EAWSType::NOT_SET;

    /**
    *  <p>URI of the grantee group.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString uRI;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::Grantee toAWS() const {
        Aws::S3::Model::Grantee awsGrantee;

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
            case EAWSType::CanonicalUser:
                awsGrantee.SetType(Aws::S3::Model::Type::CanonicalUser);
                break;
            case EAWSType::AmazonCustomerByEmail:
                awsGrantee.SetType(Aws::S3::Model::Type::AmazonCustomerByEmail);
                break;
            case EAWSType::Group:
                awsGrantee.SetType(Aws::S3::Model::Type::Group);
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
        return this->displayName.IsEmpty() && this->emailAddress.IsEmpty() && this->iD.IsEmpty() && type == EAWSType::NOT_SET && this->uRI.IsEmpty();
    }

    FGrantee &fromAWS(const Aws::S3::Model::Grantee &awsGrantee) {
        this->displayName = UTF8_TO_TCHAR(awsGrantee.GetDisplayName().c_str());

        this->emailAddress = UTF8_TO_TCHAR(awsGrantee.GetEmailAddress().c_str());

        this->iD = UTF8_TO_TCHAR(awsGrantee.GetID().c_str());

        switch(awsGrantee.GetType()) {
            case Aws::S3::Model::Type::NOT_SET:
                this->type = EAWSType::NOT_SET;
                break;
            case Aws::S3::Model::Type::CanonicalUser:
                this->type = EAWSType::CanonicalUser;
                break;
            case Aws::S3::Model::Type::AmazonCustomerByEmail:
                this->type = EAWSType::AmazonCustomerByEmail;
                break;
            case Aws::S3::Model::Type::Group:
                this->type = EAWSType::Group;
                break;
            default:
                this->type = EAWSType::NOT_SET;
                break;
        }

        this->uRI = UTF8_TO_TCHAR(awsGrantee.GetURI().c_str());

        return *this;
    }
#endif
};
