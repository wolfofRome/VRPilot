/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3ControlBucketLocationConstraint.generated.h"

UENUM(BlueprintType)
enum class EAWSS3ControlBucketLocationConstraint : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    EU        UMETA(DisplayName = "eu"),
    eu_west_1        UMETA(DisplayName = "eu west 1"),
    us_west_1        UMETA(DisplayName = "us west 1"),
    us_west_2        UMETA(DisplayName = "us west 2"),
    ap_south_1        UMETA(DisplayName = "ap south 1"),
    ap_southeast_1        UMETA(DisplayName = "ap southeast 1"),
    ap_southeast_2        UMETA(DisplayName = "ap southeast 2"),
    ap_northeast_1        UMETA(DisplayName = "ap northeast 1"),
    sa_east_1        UMETA(DisplayName = "sa east 1"),
    cn_north_1        UMETA(DisplayName = "cn north 1"),
    eu_central_1        UMETA(DisplayName = "eu central 1"),
};
