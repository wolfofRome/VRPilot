/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/StatsEvent.h"

#endif

#include "Model/S3Stats.h"

#include "StatsEvent.generated.h"

USTRUCT(BlueprintType)
struct FStatsEvent {
GENERATED_BODY()

    /**
     * <p>The Stats event details.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FS3Stats details;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FStatsEvent &fromAWS(const Aws::S3::Model::StatsEvent &awsStats) {
        this->details.fromAWS(awsStats.GetDetails());

        return *this;
    }
#endif
};
