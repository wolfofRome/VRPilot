/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "S3SSEAlgorithm.generated.h"

UENUM(BlueprintType)
enum class EAWSS3SSEAlgorithm : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    AES256        UMETA(DisplayName = "aes256"),
    KMS        UMETA(DisplayName = "kms"),
};
