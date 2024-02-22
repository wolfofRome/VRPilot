/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTServerSideEncryption.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTServerSideEncryption : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    AES256        UMETA(DisplayName = "aes256"),
    aws_kms        UMETA(DisplayName = "aws kms"),
};
