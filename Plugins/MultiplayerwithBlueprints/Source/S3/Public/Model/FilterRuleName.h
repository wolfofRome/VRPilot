/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "FilterRuleName.generated.h"

UENUM(BlueprintType)
enum class EAWSFilterRuleName : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    prefix        UMETA(DisplayName = "prefix"),
    suffix        UMETA(DisplayName = "suffix"),
};
