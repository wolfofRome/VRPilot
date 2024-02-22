/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "ReplicationStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSReplicationStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    COMPLETED        UMETA(DisplayName = "completed"),
    PENDING        UMETA(DisplayName = "pending"),
    FAILED        UMETA(DisplayName = "failed"),
    REPLICA        UMETA(DisplayName = "replica"),
};
