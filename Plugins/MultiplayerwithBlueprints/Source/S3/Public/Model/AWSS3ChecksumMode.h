/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3ChecksumMode.generated.h"

UENUM(BlueprintType)
enum class EAWSS3ChecksumMode : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    ENABLED        UMETA(DisplayName = "enabled"),
};
