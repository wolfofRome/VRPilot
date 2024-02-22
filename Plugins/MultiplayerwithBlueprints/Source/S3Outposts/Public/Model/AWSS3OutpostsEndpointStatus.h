/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3OutpostsEndpointStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSS3OutpostsEndpointStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Pending        UMETA(DisplayName = "pending"),
    Available        UMETA(DisplayName = "available"),
    Deleting        UMETA(DisplayName = "deleting"),
};
