/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "NetworkOrigin.generated.h"

UENUM(BlueprintType)
enum class EAWSNetworkOrigin : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Internet        UMETA(DisplayName = "internet"),
    VPC        UMETA(DisplayName = "vpc"),
};
