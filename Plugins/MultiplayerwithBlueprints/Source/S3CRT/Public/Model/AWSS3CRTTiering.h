/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Tiering.h"

#endif

#include "Model/AWSS3CRTIntelligentTieringAccessTier.h"

#include "AWSS3CRTTiering.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTTiering {
GENERATED_BODY()

    /**
    *  <p>The number of consecutive days of no access after which an object will be eligible to be transitioned to the corresponding tier. The minimum number of days specified for Archive Access tier must be at least 90 days and Deep Archive Access tier must be at least 180 days. The maximum can be up to 2 years (730 days).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    int days = 0;

    /**
    *  <p>S3 Intelligent-Tiering access tier. See <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/storage-class-intro.html#sc-dynamic-data-access">Storage class for automatically optimizing frequently and infrequently accessed objects</a> for a list of access tiers in the S3 Intelligent-Tiering storage class.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTIntelligentTieringAccessTier accessTier = EAWSS3CRTIntelligentTieringAccessTier::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::Tiering toAWS() const {
        Aws::S3Crt::Model::Tiering awsTiering;

        if (!(this->days == 0)) {
            awsTiering.SetDays(this->days);
        }

        switch(this->accessTier) {
            case EAWSS3CRTIntelligentTieringAccessTier::ARCHIVE_ACCESS:
                awsTiering.SetAccessTier(Aws::S3Crt::Model::IntelligentTieringAccessTier::ARCHIVE_ACCESS);
                break;
            case EAWSS3CRTIntelligentTieringAccessTier::DEEP_ARCHIVE_ACCESS:
                awsTiering.SetAccessTier(Aws::S3Crt::Model::IntelligentTieringAccessTier::DEEP_ARCHIVE_ACCESS);
                break;
            default:
                break;
        }

        return awsTiering;
    }

    bool IsEmpty() const {
        return this->days == 0 && this->accessTier == EAWSS3CRTIntelligentTieringAccessTier::NOT_SET;
    }

    FAWSS3CRTTiering &fromAWS(const Aws::S3Crt::Model::Tiering &awsTiering) {
		this->days = awsTiering.GetDays();

        switch(awsTiering.GetAccessTier()) {
            case Aws::S3Crt::Model::IntelligentTieringAccessTier::NOT_SET:
                this->accessTier = EAWSS3CRTIntelligentTieringAccessTier::NOT_SET;
                break;
            case Aws::S3Crt::Model::IntelligentTieringAccessTier::ARCHIVE_ACCESS:
                this->accessTier = EAWSS3CRTIntelligentTieringAccessTier::ARCHIVE_ACCESS;
                break;
            case Aws::S3Crt::Model::IntelligentTieringAccessTier::DEEP_ARCHIVE_ACCESS:
                this->accessTier = EAWSS3CRTIntelligentTieringAccessTier::DEEP_ARCHIVE_ACCESS;
                break;
            default:
                this->accessTier = EAWSS3CRTIntelligentTieringAccessTier::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
