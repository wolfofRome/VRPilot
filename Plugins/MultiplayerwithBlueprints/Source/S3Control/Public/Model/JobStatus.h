/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "JobStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSJobStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Active        UMETA(DisplayName = "active"),
    Cancelled        UMETA(DisplayName = "cancelled"),
    Cancelling        UMETA(DisplayName = "cancelling"),
    Complete        UMETA(DisplayName = "complete"),
    Completing        UMETA(DisplayName = "completing"),
    Failed        UMETA(DisplayName = "failed"),
    Failing        UMETA(DisplayName = "failing"),
    New        UMETA(DisplayName = "new"),
    Paused        UMETA(DisplayName = "paused"),
    Pausing        UMETA(DisplayName = "pausing"),
    Preparing        UMETA(DisplayName = "preparing"),
    Ready        UMETA(DisplayName = "ready"),
    Suspended        UMETA(DisplayName = "suspended"),
};
