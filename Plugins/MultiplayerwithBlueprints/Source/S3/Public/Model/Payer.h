/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "Payer.generated.h"

UENUM(BlueprintType)
enum class EAWSPayer : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Requester        UMETA(DisplayName = "requester"),
    BucketOwner        UMETA(DisplayName = "bucketowner"),
};
