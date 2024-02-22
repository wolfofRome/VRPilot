/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/ServerSideEncryptionConfiguration.h"

#endif

#include "Model/ServerSideEncryptionRule.h"

#include "ServerSideEncryptionConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FServerSideEncryptionConfiguration {
GENERATED_BODY()

    /**
    *  <p>Container for information about a particular server-side encryption configuration rule.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FServerSideEncryptionRule> rules;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::ServerSideEncryptionConfiguration toAWS() const {
        Aws::S3::Model::ServerSideEncryptionConfiguration awsServerSideEncryptionConfiguration;

        for (const FServerSideEncryptionRule& elem : this->rules) {
            awsServerSideEncryptionConfiguration.AddRules(elem.toAWS());
        }

        return awsServerSideEncryptionConfiguration;
    }

    bool IsEmpty() const {
        return this->rules.Num() == 0;
    }

    FServerSideEncryptionConfiguration &fromAWS(const Aws::S3::Model::ServerSideEncryptionConfiguration &awsServerSideEncryptionConfiguration) {
        this->rules.Empty();
        for (const Aws::S3::Model::ServerSideEncryptionRule& elem : awsServerSideEncryptionConfiguration.GetRules()) {
            this->rules.Add(FServerSideEncryptionRule().fromAWS(elem));
        }

        return *this;
    }
#endif
};
