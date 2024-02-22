/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTPayer.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTPayer : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Requester        UMETA(DisplayName = "requester"),
    BucketOwner        UMETA(DisplayName = "bucketowner"),
};
