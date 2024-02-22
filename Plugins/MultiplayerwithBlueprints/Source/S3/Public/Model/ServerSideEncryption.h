/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "ServerSideEncryption.generated.h"

UENUM(BlueprintType)
enum class EAWSServerSideEncryption : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    AES256        UMETA(DisplayName = "aes256"),
    aws_kms        UMETA(DisplayName = "aws kms"),
};
