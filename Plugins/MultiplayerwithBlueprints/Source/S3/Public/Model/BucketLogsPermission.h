/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "BucketLogsPermission.generated.h"

UENUM(BlueprintType)
enum class EAWSBucketLogsPermission : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    FULL_CONTROL        UMETA(DisplayName = "full control"),
    READ        UMETA(DisplayName = "read"),
    WRITE        UMETA(DisplayName = "write"),
};
