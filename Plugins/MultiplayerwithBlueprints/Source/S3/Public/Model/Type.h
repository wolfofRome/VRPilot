/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "Type.generated.h"

UENUM(BlueprintType)
enum class EAWSType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    CanonicalUser        UMETA(DisplayName = "canonicaluser"),
    AmazonCustomerByEmail        UMETA(DisplayName = "amazoncustomerbyemail"),
    Group        UMETA(DisplayName = "group"),
};
