/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/StatsEvent.h"

#endif

#include "Model/AWSS3CRTStats.h"

#include "AWSS3CRTStatsEvent.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTStatsEvent {
GENERATED_BODY()

    /**
     * <p>The Stats event details.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTStats details;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTStatsEvent &fromAWS(const Aws::S3Crt::Model::StatsEvent &awsStats) {
        this->details.fromAWS(awsStats.GetDetails());

        return *this;
    }
#endif
};
