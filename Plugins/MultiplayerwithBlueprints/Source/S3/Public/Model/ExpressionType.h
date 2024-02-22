/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "ExpressionType.generated.h"

UENUM(BlueprintType)
enum class EAWSExpressionType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    SQL        UMETA(DisplayName = "sql"),
};
