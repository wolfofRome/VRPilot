/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, June 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_LAMBDACLIENTSDK && WITH_CORE

#include "aws/lambda/model/GetFunctionEventInvokeConfigRequest.h"

#endif

#include "GetFunctionEventInvokeConfigRequest.generated.h"

USTRUCT(BlueprintType)
struct FGetFunctionEventInvokeConfigRequest {
GENERATED_BODY()

    /**
    *  <p>The name of the Lambda function, version, or alias.</p> <p class="title"> <b>Name formats</b> </p> <ul> <li> <p> <b>Function name</b> - <code>my-function</code> (name-only), <code>my-function:v1</code> (with alias).</p> </li> <li> <p> <b>Function ARN</b> - <code>arn:aws:lambda:us-west-2:123456789012:function:my-function</code>.</p> </li> <li> <p> <b>Partial ARN</b> - <code>123456789012:function:my-function</code>.</p> </li> </ul> <p>You can append a version number or alias to any of the formats. The length constraint applies only to the full ARN. If you specify only the function name, it is limited to 64 characters in length.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString functionName;

    /**
    *  <p>A version number or alias name.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lambda Client")
    FString qualifier;

#if WITH_LAMBDACLIENTSDK && WITH_CORE
public:
    Aws::Lambda::Model::GetFunctionEventInvokeConfigRequest toAWS() const {
        Aws::Lambda::Model::GetFunctionEventInvokeConfigRequest awsGetFunctionEventInvokeConfigRequest;

		if (!(this->functionName.IsEmpty())) {
            awsGetFunctionEventInvokeConfigRequest.SetFunctionName(TCHAR_TO_UTF8(*this->functionName));
        }

		if (!(this->qualifier.IsEmpty())) {
            awsGetFunctionEventInvokeConfigRequest.SetQualifier(TCHAR_TO_UTF8(*this->qualifier));
        }

        return awsGetFunctionEventInvokeConfigRequest;
    }

    bool IsEmpty() const {
        return this->functionName.IsEmpty() && this->qualifier.IsEmpty();
    }
#endif
};
