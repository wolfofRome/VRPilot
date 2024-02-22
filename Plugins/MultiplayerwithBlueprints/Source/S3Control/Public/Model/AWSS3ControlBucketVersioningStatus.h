/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3ControlBucketVersioningStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSS3ControlBucketVersioningStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Enabled        UMETA(DisplayName = "enabled"),
    Suspended        UMETA(DisplayName = "suspended"),
};
