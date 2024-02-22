/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3ControlObjectLambdaAllowedFeature.generated.h"

UENUM(BlueprintType)
enum class EAWSS3ControlObjectLambdaAllowedFeature : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    GetObject_Range        UMETA(DisplayName = "get object range"),
    GetObject_PartNumber        UMETA(DisplayName = "get object part number"),
    HeadObject_Range        UMETA(DisplayName = "headobject range"),
    HeadObject_PartNumber        UMETA(DisplayName = "headobject partnumber"),
};
