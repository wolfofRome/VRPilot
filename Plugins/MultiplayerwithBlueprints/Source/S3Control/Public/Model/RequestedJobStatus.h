/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "RequestedJobStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSRequestedJobStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Cancelled        UMETA(DisplayName = "cancelled"),
    Ready        UMETA(DisplayName = "ready"),
};
