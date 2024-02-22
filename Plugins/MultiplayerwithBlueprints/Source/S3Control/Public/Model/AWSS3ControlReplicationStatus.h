/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3ControlReplicationStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSS3ControlReplicationStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    COMPLETED        UMETA(DisplayName = "completed"),
    FAILED        UMETA(DisplayName = "failed"),
    REPLICA        UMETA(DisplayName = "replica"),
    NONE        UMETA(DisplayName = "none"),
};
