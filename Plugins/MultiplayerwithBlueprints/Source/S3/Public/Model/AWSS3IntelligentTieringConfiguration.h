/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/IntelligentTieringConfiguration.h"

#endif

#include "Model/AWSS3IntelligentTieringFilter.h"
#include "Model/AWSS3IntelligentTieringStatus.h"
#include "Model/AWSS3Tiering.h"

#include "AWSS3IntelligentTieringConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3IntelligentTieringConfiguration {
GENERATED_BODY()

    /**
    *  <p>The ID used to identify the S3 Intelligent-Tiering configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString id;

    /**
    *  <p>Specifies a bucket filter. The configuration only includes objects that meet the filter's criteria.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FAWSS3IntelligentTieringFilter filter;

    /**
    *  <p>Specifies the status of the configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3IntelligentTieringStatus status = EAWSS3IntelligentTieringStatus::NOT_SET;

    /**
    *  <p>Specifies the S3 Intelligent-Tiering storage class tier of the configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FAWSS3Tiering> tierings;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::IntelligentTieringConfiguration toAWS() const {
        Aws::S3::Model::IntelligentTieringConfiguration awsIntelligentTieringConfiguration;

        if (!(this->id.IsEmpty())) {
            awsIntelligentTieringConfiguration.SetId(TCHAR_TO_UTF8(*this->id));
        }

        if (!(this->filter.IsEmpty())) {
            awsIntelligentTieringConfiguration.SetFilter(this->filter.toAWS());
        }

        switch(this->status) {
            case EAWSS3IntelligentTieringStatus::Enabled:
                awsIntelligentTieringConfiguration.SetStatus(Aws::S3::Model::IntelligentTieringStatus::Enabled);
                break;
            case EAWSS3IntelligentTieringStatus::Disabled:
                awsIntelligentTieringConfiguration.SetStatus(Aws::S3::Model::IntelligentTieringStatus::Disabled);
                break;
            default:
                break;
        }

        for (const FAWSS3Tiering& elem : this->tierings) {
            awsIntelligentTieringConfiguration.AddTierings(elem.toAWS());
        }

        return awsIntelligentTieringConfiguration;
    }

    bool IsEmpty() const {
        return this->id.IsEmpty() && this->filter.IsEmpty() && this->status == EAWSS3IntelligentTieringStatus::NOT_SET && this->tierings.Num() == 0;
    }

    FAWSS3IntelligentTieringConfiguration &fromAWS(const Aws::S3::Model::IntelligentTieringConfiguration &awsIntelligentTieringConfiguration) {
        this->id = UTF8_TO_TCHAR(awsIntelligentTieringConfiguration.GetId().c_str());

        this->filter.fromAWS(awsIntelligentTieringConfiguration.GetFilter());

        switch(awsIntelligentTieringConfiguration.GetStatus()) {
            case Aws::S3::Model::IntelligentTieringStatus::NOT_SET:
                this->status = EAWSS3IntelligentTieringStatus::NOT_SET;
                break;
            case Aws::S3::Model::IntelligentTieringStatus::Enabled:
                this->status = EAWSS3IntelligentTieringStatus::Enabled;
                break;
            case Aws::S3::Model::IntelligentTieringStatus::Disabled:
                this->status = EAWSS3IntelligentTieringStatus::Disabled;
                break;
            default:
                this->status = EAWSS3IntelligentTieringStatus::NOT_SET;
                break;
        }

        this->tierings.Empty();
        for (const Aws::S3::Model::Tiering& elem : awsIntelligentTieringConfiguration.GetTierings()) {
            this->tierings.Add(FAWSS3Tiering().fromAWS(elem));
        }

        return *this;
    }
#endif
};
