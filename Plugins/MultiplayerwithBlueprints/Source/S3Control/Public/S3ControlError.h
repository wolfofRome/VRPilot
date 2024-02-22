/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK

#include "aws/s3control/S3ControlErrors.h"

#endif

#include "S3ControlError.generated.h"

UENUM(BlueprintType)
enum class ES3ControlError : uint8 {
    //From Core//
    //////////////////////////////////////////////////////////////////////////////////////////
    INCOMPLETE_SIGNATURE UMETA(DisplayName = "Incomplete Signature"),
    INTERNAL_FAILURE UMETA(DisplayName = "Internal Failure"),
    INVALID_ACTION UMETA(DisplayName = "Invalid Action"),
    INVALID_CLIENT_TOKEN_ID UMETA(DisplayName = "Invalid Client Token ID"),
    INVALID_PARAMETER_COMBINATION UMETA(DisplayName = "Invalid Parameter Combination"),
    INVALID_QUERY_PARAMETER UMETA(DisplayName = "Invalid Query Parameter"),
    INVALID_PARAMETER_VALUE UMETA(DisplayName = "Invalid Parameter value"),
    MISSING_ACTION UMETA(DisplayName = "Missing Action"), // SDK should never allow
    MISSING_AUTHENTICATION_TOKEN UMETA(DisplayName = "Missing Authentication"), // SDK should never allow
    MISSING_PARAMETER UMETA(DisplayName = "Missing Parameter"), // SDK should never allow
    OPT_IN_REQUIRED UMETA(DisplayName = "Opt In Required"),
    REQUEST_EXPIRED UMETA(DisplayName = "Request Expired"),
    SERVICE_UNAVAILABLE UMETA(DisplayName = "Service Unavailable"),
    THROTTLING UMETA(DisplayName = "Throttling"),
    VALIDATION UMETA(DisplayName = "Validation"),
    ACCESS_DENIED UMETA(DisplayName = "Access Denied"),
    RESOURCE_NOT_FOUND UMETA(DisplayName = "Resource Not Found"),
    UNRECOGNIZED_CLIENT UMETA(DisplayName = "Unrecognized Client"),
    MALFORMED_QUERY_STRING UMETA(DisplayName = "Malformed Query String"),
    SLOW_DOWN UMETA(DisplayName = "Slow Down"),
    REQUEST_TIME_TOO_SKEWED UMETA(DisplayName = "Request Time Too Skewed"),
    INVALID_SIGNATURE UMETA(DisplayName = "Invalid Signature"),
    SIGNATURE_DOES_NOT_MATCH UMETA(DisplayName = "Signature Does Not Match"),
    INVALID_ACCESS_KEY_ID UMETA(DisplayName = "Invalid Access Key ID"),
    REQUEST_TIMEOUT UMETA(DisplayName = "Request Timeout"),
    NETWORK_CONNECTION UMETA(DisplayName = "Network Connection"),

    UNKNOWN UMETA(DisplayName = "Unknown"),
    ///////////////////////////////////////////////////////////////////////////////////////////

    BAD_REQUEST UMETA(DisplayName = "Bad Request"),
    BUCKET_ALREADY_EXISTS UMETA(DisplayName = "Bad Request"),
    BUCKET_ALREADY_OWNED_BY_YOU UMETA(DisplayName = "Bad Request"),
    IDEMPOTENCY UMETA(DisplayName = "Idempotency"),
    INTERNAL_SERVICE UMETA(DisplayName = "Internal Service"),
    INVALID_NEXT_TOKEN UMETA(DisplayName = "Invalid Next Token"),
    INVALID_REQUEST UMETA(DisplayName = "Invalid Request"),
    JOB_STATUS UMETA(DisplayName = "Job Status"),
    NOT_FOUND UMETA(DisplayName = "Not Found"),
    NO_SUCH_PUBLIC_ACCESS_BLOCK_CONFIGURATION UMETA(DisplayName = "No Such Public Access Block Configuration"),
    TOO_MANY_REQUESTS UMETA(DisplayName = "Too Many Requests"),
    TOO_MANY_TAGS UMETA(DisplayName = "Too Many Tags"),
};
