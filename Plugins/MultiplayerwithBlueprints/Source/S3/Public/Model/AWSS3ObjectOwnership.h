/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3ObjectOwnership.generated.h"

UENUM(BlueprintType)
enum class EAWSS3ObjectOwnership : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    BucketOwnerPreferred        UMETA(DisplayName = "bucketownerpreferred"),
    ObjectWriter        UMETA(DisplayName = "objectwriter"),
    BucketOwnerEnforced        UMETA(DisplayName = "bucketownerenforced"),
};
