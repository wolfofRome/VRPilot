/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "CompressionType.generated.h"

UENUM(BlueprintType)
enum class EAWSCompressionType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    NONE        UMETA(DisplayName = "none"),
    GZIP        UMETA(DisplayName = "gzip"),
    BZIP2        UMETA(DisplayName = "bzip2"),
};
