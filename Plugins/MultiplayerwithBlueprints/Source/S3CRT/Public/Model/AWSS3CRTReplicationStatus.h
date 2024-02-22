/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTReplicationStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTReplicationStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    COMPLETED        UMETA(DisplayName = "completed"),
    PENDING        UMETA(DisplayName = "pending"),
    FAILED        UMETA(DisplayName = "failed"),
    REPLICA        UMETA(DisplayName = "replica"),
};
