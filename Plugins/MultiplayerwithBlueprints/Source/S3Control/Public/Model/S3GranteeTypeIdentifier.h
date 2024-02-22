/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#include "S3GranteeTypeIdentifier.generated.h"

UENUM(BlueprintType)
enum class EAWSS3GranteeTypeIdentifier : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    id        UMETA(DisplayName = "id"),
    emailAddress        UMETA(DisplayName = "emailaddress"),
    uri        UMETA(DisplayName = "uri"),
};
