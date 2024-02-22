/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTEncodingType.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTEncodingType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    url        UMETA(DisplayName = "url"),
};
