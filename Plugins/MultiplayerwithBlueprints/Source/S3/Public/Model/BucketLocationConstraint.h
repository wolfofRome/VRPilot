/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "BucketLocationConstraint.generated.h"

UENUM(BlueprintType)
enum class EAWSBucketLocationConstraint : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    af_south_1        UMETA(DisplayName = "af south 1"),
    ap_east_1        UMETA(DisplayName = "ap east 1"),
    ap_northeast_1        UMETA(DisplayName = "ap northeast 1"),
    ap_northeast_2        UMETA(DisplayName = "ap northeast 2"),
    ap_northeast_3        UMETA(DisplayName = "ap northeast 3"),
    ap_south_1        UMETA(DisplayName = "ap south 1"),
    ap_southeast_1        UMETA(DisplayName = "ap southeast 1"),
    ap_southeast_2        UMETA(DisplayName = "ap southeast 2"),
    ap_southeast_3        UMETA(DisplayName = "ap southeast 3"),
    ca_central_1        UMETA(DisplayName = "ca central 1"),
    cn_north_1        UMETA(DisplayName = "cn north 1"),
    cn_northwest_1        UMETA(DisplayName = "cn northwest 1"),
    EU        UMETA(DisplayName = "eu"),
    eu_central_1        UMETA(DisplayName = "eu central 1"),
    eu_north_1        UMETA(DisplayName = "eu north 1"),
    eu_south_1        UMETA(DisplayName = "eu south 1"),
    eu_west_1        UMETA(DisplayName = "eu west 1"),
    eu_west_2        UMETA(DisplayName = "eu west 2"),
    eu_west_3        UMETA(DisplayName = "eu west 3"),
    me_south_1        UMETA(DisplayName = "me south 1"),
    sa_east_1        UMETA(DisplayName = "sa east 1"),
    us_east_2        UMETA(DisplayName = "us east 2"),
    us_gov_east_1        UMETA(DisplayName = "us gov east 1"),
    us_gov_west_1        UMETA(DisplayName = "us gov west 1"),
    us_west_1        UMETA(DisplayName = "us west 1"),
    us_west_2        UMETA(DisplayName = "us west 2"),
    us_iso_west_1        UMETA(DisplayName = "us iso west 1"),
    us_east_1        UMETA(DisplayName = "us east 1"),
};
