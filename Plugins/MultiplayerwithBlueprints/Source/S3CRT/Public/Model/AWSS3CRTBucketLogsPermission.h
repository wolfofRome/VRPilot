/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTBucketLogsPermission.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTBucketLogsPermission : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    FULL_CONTROL        UMETA(DisplayName = "full control"),
    READ        UMETA(DisplayName = "read"),
    WRITE        UMETA(DisplayName = "write"),
};
