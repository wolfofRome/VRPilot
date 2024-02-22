/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3OutpostsEndpointAccessType.generated.h"

UENUM(BlueprintType)
enum class EAWSS3OutpostsEndpointAccessType : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    Private        UMETA(DisplayName = "private"),
    CustomerOwnedIp        UMETA(DisplayName = "customerownedip"),
};
