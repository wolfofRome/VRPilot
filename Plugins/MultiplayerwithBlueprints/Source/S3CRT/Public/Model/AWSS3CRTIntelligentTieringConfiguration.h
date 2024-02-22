/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/IntelligentTieringConfiguration.h"

#endif

#include "Model/AWSS3CRTIntelligentTieringFilter.h"
#include "Model/AWSS3CRTIntelligentTieringStatus.h"
#include "Model/AWSS3CRTTiering.h"

#include "AWSS3CRTIntelligentTieringConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTIntelligentTieringConfiguration {
GENERATED_BODY()

    /**
    *  <p>The ID used to identify the S3 Intelligent-Tiering configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString id;

    /**
    *  <p>Specifies a bucket filter. The configuration only includes objects that meet the filter's criteria.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTIntelligentTieringFilter filter;

    /**
    *  <p>Specifies the status of the configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTIntelligentTieringStatus status = EAWSS3CRTIntelligentTieringStatus::NOT_SET;

    /**
    *  <p>Specifies the S3 Intelligent-Tiering storage class tier of the configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTTiering> tierings;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::IntelligentTieringConfiguration toAWS() const {
        Aws::S3Crt::Model::IntelligentTieringConfiguration awsIntelligentTieringConfiguration;

        if (!(this->id.IsEmpty())) {
            awsIntelligentTieringConfiguration.SetId(TCHAR_TO_UTF8(*this->id));
        }
        if (!(this->filter.IsEmpty())) {
            awsIntelligentTieringConfiguration.SetFilter(this->filter.toAWS());
        }

        switch(this->status) {
            case EAWSS3CRTIntelligentTieringStatus::Enabled:
                awsIntelligentTieringConfiguration.SetStatus(Aws::S3Crt::Model::IntelligentTieringStatus::Enabled);
                break;
            case EAWSS3CRTIntelligentTieringStatus::Disabled:
                awsIntelligentTieringConfiguration.SetStatus(Aws::S3Crt::Model::IntelligentTieringStatus::Disabled);
                break;
            default:
                break;
        }

        for (const FAWSS3CRTTiering& elem : this->tierings) {
            awsIntelligentTieringConfiguration.AddTierings(elem.toAWS());
        }

        return awsIntelligentTieringConfiguration;
    }

    bool IsEmpty() const {
        return this->id.IsEmpty() && this->filter.IsEmpty() && this->status == EAWSS3CRTIntelligentTieringStatus::NOT_SET && this->tierings.Num() == 0;
    }

    FAWSS3CRTIntelligentTieringConfiguration &fromAWS(const Aws::S3Crt::Model::IntelligentTieringConfiguration &awsIntelligentTieringConfiguration) {
        this->id = UTF8_TO_TCHAR(awsIntelligentTieringConfiguration.GetId().c_str());

        this->filter = FAWSS3CRTIntelligentTieringFilter().fromAWS(awsIntelligentTieringConfiguration.GetFilter());

        switch(awsIntelligentTieringConfiguration.GetStatus()) {
            case Aws::S3Crt::Model::IntelligentTieringStatus::NOT_SET:
                this->status = EAWSS3CRTIntelligentTieringStatus::NOT_SET;
                break;
            case Aws::S3Crt::Model::IntelligentTieringStatus::Enabled:
                this->status = EAWSS3CRTIntelligentTieringStatus::Enabled;
                break;
            case Aws::S3Crt::Model::IntelligentTieringStatus::Disabled:
                this->status = EAWSS3CRTIntelligentTieringStatus::Disabled;
                break;
            default:
                this->status = EAWSS3CRTIntelligentTieringStatus::NOT_SET;
                break;
        }

        this->tierings.Empty();
        for (const Aws::S3Crt::Model::Tiering& elem : awsIntelligentTieringConfiguration.GetTierings()) {
            this->tierings.Add(FAWSS3CRTTiering().fromAWS(elem));
        }

        return *this;
    }
#endif
};
