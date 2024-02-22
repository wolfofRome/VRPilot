/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/StorageLensAwsOrg.h"

#endif

#include "AWSS3ControlStorageLensAwsOrg.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlStorageLensAwsOrg {
GENERATED_BODY()

    /**
    *  <p>A container for the Amazon Resource Name (ARN) of the AWS organization. This property is read-only and follows the following format: <code> arn:aws:organizations:<i>us-east-1</i>:<i>example-account-id</i>:organization/<i>o-ex2l495dck</i> </code> </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString arn;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::StorageLensAwsOrg toAWS() const {
        Aws::S3Control::Model::StorageLensAwsOrg awsStorageLensAwsOrg;

        if (!(this->arn.IsEmpty())) {
            awsStorageLensAwsOrg.SetArn(TCHAR_TO_UTF8(*this->arn));
        }

        return awsStorageLensAwsOrg;
    }

    bool IsEmpty() const {
        return this->arn.IsEmpty();
    }

    FAWSS3ControlStorageLensAwsOrg &fromAWS(const Aws::S3Control::Model::StorageLensAwsOrg &awsStorageLensAwsOrg) {
        this->arn = UTF8_TO_TCHAR(awsStorageLensAwsOrg.GetArn().c_str());

        return *this;
    }
#endif
};
