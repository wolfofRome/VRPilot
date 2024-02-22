/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTType.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    CanonicalUser        UMETA(DisplayName = "canonicaluser"),
    AmazonCustomerByEmail        UMETA(DisplayName = "amazoncustomerbyemail"),
    Group        UMETA(DisplayName = "group"),
};
