/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTPermission.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTPermission : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    FULL_CONTROL        UMETA(DisplayName = "full control"),
    WRITE        UMETA(DisplayName = "write"),
    WRITE_ACP        UMETA(DisplayName = "write acp"),
    READ        UMETA(DisplayName = "read"),
    READ_ACP        UMETA(DisplayName = "read acp"),
};
