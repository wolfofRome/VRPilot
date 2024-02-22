/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTCompressionType.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTCompressionType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    NONE        UMETA(DisplayName = "none"),
    GZIP        UMETA(DisplayName = "gzip"),
    BZIP2        UMETA(DisplayName = "bzip2"),
};
