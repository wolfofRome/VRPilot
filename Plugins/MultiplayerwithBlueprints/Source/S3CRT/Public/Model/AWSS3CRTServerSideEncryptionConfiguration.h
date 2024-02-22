/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ServerSideEncryptionConfiguration.h"

#endif

#include "Model/AWSS3CRTServerSideEncryptionRule.h"

#include "AWSS3CRTServerSideEncryptionConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTServerSideEncryptionConfiguration {
GENERATED_BODY()

    /**
    *  <p>Container for information about a particular server-side encryption configuration rule.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTServerSideEncryptionRule> rules;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::ServerSideEncryptionConfiguration toAWS() const {
        Aws::S3Crt::Model::ServerSideEncryptionConfiguration awsServerSideEncryptionConfiguration;

        for (const FAWSS3CRTServerSideEncryptionRule& elem : this->rules) {
            awsServerSideEncryptionConfiguration.AddRules(elem.toAWS());
        }

        return awsServerSideEncryptionConfiguration;
    }

    bool IsEmpty() const {
        return this->rules.Num() == 0;
    }

    FAWSS3CRTServerSideEncryptionConfiguration &fromAWS(const Aws::S3Crt::Model::ServerSideEncryptionConfiguration &awsServerSideEncryptionConfiguration) {
        this->rules.Empty();
        for (const Aws::S3Crt::Model::ServerSideEncryptionRule& elem : awsServerSideEncryptionConfiguration.GetRules()) {
            this->rules.Add(FAWSS3CRTServerSideEncryptionRule().fromAWS(elem));
        }

        return *this;
    }
#endif
};
