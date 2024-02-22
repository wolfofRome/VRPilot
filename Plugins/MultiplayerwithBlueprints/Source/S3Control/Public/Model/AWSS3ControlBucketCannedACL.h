/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3ControlBucketCannedACL.generated.h"

UENUM(BlueprintType)
enum class EAWSS3ControlBucketCannedACL : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    private_        UMETA(DisplayName = "private "),
    public_read        UMETA(DisplayName = "public read"),
    public_read_write        UMETA(DisplayName = "public read write"),
    authenticated_read        UMETA(DisplayName = "authenticated read"),
};
