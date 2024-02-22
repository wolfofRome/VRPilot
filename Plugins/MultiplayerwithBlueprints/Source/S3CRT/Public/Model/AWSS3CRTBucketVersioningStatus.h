/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTBucketVersioningStatus.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTBucketVersioningStatus : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Enabled        UMETA(DisplayName = "enabled"),
    Suspended        UMETA(DisplayName = "suspended"),
};
