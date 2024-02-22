/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/StorageLensConfiguration.h"

#endif

#include "Model/AWSS3ControlAccountLevel.h"
#include "Model/AWSS3ControlInclude.h"
#include "Model/AWSS3ControlExclude.h"
#include "Model/AWSS3ControlStorageLensDataExport.h"
#include "Model/AWSS3ControlStorageLensAwsOrg.h"

#include "AWSS3ControlStorageLensConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlStorageLensConfiguration {
GENERATED_BODY()

    /**
    *  <p>A container for the Amazon S3 Storage Lens configuration ID.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString id;

    /**
    *  <p>A container for all the account-level configurations of your S3 Storage Lens configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlAccountLevel accountLevel;

    /**
    *  <p>A container for what is included in this configuration. This container can only be valid if there is no <code>Exclude</code> container submitted, and it's not empty. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlInclude include;

    /**
    *  <p>A container for what is excluded in this configuration. This container can only be valid if there is no <code>Include</code> container submitted, and it's not empty. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlExclude exclude;

    /**
    *  <p>A container to specify the properties of your S3 Storage Lens metrics export including, the destination, schema and format.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlStorageLensDataExport dataExport;

    /**
    *  <p>A container for whether the S3 Storage Lens configuration is enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool isEnabled = false;

    /**
    *  <p>A container for the AWS organization for this S3 Storage Lens configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlStorageLensAwsOrg awsOrg;

    /**
    *  <p>The Amazon Resource Name (ARN) of the S3 Storage Lens configuration. This property is read-only and follows the following format: <code> arn:aws:s3:<i>us-east-1</i>:<i>example-account-id</i>:storage-lens/<i>your-dashboard-name</i> </code> </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString storageLensArn;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::StorageLensConfiguration toAWS() const {
        Aws::S3Control::Model::StorageLensConfiguration awsStorageLensConfiguration;

        if (!(this->id.IsEmpty())) {
            awsStorageLensConfiguration.SetId(TCHAR_TO_UTF8(*this->id));
        }

        if (!(this->accountLevel.IsEmpty())) {
            awsStorageLensConfiguration.SetAccountLevel(this->accountLevel.toAWS());
        }

        if (!(this->include.IsEmpty())) {
            awsStorageLensConfiguration.SetInclude(this->include.toAWS());
        }

        if (!(this->exclude.IsEmpty())) {
            awsStorageLensConfiguration.SetExclude(this->exclude.toAWS());
        }

        if (!(this->dataExport.IsEmpty())) {
            awsStorageLensConfiguration.SetDataExport(this->dataExport.toAWS());
        }

        if (!(false)) {
            awsStorageLensConfiguration.SetIsEnabled(this->isEnabled);
        }

        if (!(this->awsOrg.IsEmpty())) {
            awsStorageLensConfiguration.SetAwsOrg(this->awsOrg.toAWS());
        }

        if (!(this->storageLensArn.IsEmpty())) {
            awsStorageLensConfiguration.SetStorageLensArn(TCHAR_TO_UTF8(*this->storageLensArn));
        }

        return awsStorageLensConfiguration;
    }

    bool IsEmpty() const {
        return this->id.IsEmpty() && this->accountLevel.IsEmpty() && this->include.IsEmpty() && this->exclude.IsEmpty() && this->dataExport.IsEmpty() && false && this->awsOrg.IsEmpty() && this->storageLensArn.IsEmpty();
    }

    FAWSS3ControlStorageLensConfiguration &fromAWS(const Aws::S3Control::Model::StorageLensConfiguration &awsStorageLensConfiguration) {
        this->id = UTF8_TO_TCHAR(awsStorageLensConfiguration.GetId().c_str());

        this->accountLevel.fromAWS(awsStorageLensConfiguration.GetAccountLevel());

        this->include.fromAWS(awsStorageLensConfiguration.GetInclude());

        this->exclude.fromAWS(awsStorageLensConfiguration.GetExclude());

        this->dataExport.fromAWS(awsStorageLensConfiguration.GetDataExport());

        this->isEnabled = awsStorageLensConfiguration.GetIsEnabled();

        this->awsOrg.fromAWS(awsStorageLensConfiguration.GetAwsOrg());

        this->storageLensArn = UTF8_TO_TCHAR(awsStorageLensConfiguration.GetStorageLensArn().c_str());

        return *this;
    }
#endif
};
