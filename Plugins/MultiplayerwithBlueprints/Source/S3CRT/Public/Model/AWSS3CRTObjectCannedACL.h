/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#include "AWSS3CRTObjectCannedACL.generated.h"

UENUM(BlueprintType)
enum class EAWSS3CRTObjectCannedACL : uint8 {
    NOT_SET        UMETA(DisplayName = "not set"),
    private_        UMETA(DisplayName = "private "),
    public_read        UMETA(DisplayName = "public read"),
    public_read_write        UMETA(DisplayName = "public read write"),
    authenticated_read        UMETA(DisplayName = "authenticated read"),
    aws_exec_read        UMETA(DisplayName = "aws exec read"),
    bucket_owner_read        UMETA(DisplayName = "bucket owner read"),
    bucket_owner_full_control        UMETA(DisplayName = "bucket owner full control"),
};
