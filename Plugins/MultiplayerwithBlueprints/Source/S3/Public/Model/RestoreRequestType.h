/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "RestoreRequestType.generated.h"

UENUM(BlueprintType)
enum class EAWSRestoreRequestType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    SELECT        UMETA(DisplayName = "select"),
};
