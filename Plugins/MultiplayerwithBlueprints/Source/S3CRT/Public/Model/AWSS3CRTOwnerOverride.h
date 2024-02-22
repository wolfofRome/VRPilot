/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTOwnerOverride.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTOwnerOverride : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Destination        UMETA(DisplayName = "destination"),
};
