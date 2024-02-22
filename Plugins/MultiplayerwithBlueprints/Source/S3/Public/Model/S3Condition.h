/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/Condition.h"

#endif

#include "S3Condition.generated.h"

USTRUCT(BlueprintType)
struct FS3Condition {
GENERATED_BODY()

    /**
    *  <p>The HTTP error code when the redirect is applied. In the event of an error, if the error code equals this value, then the specified redirect is applied. Required when parent element <code>Condition</code> is specified and sibling <code>KeyPrefixEquals</code> is not specified. If both are specified, then both must be true for the redirect to be applied.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString httpErrorCodeReturnedEquals;

    /**
    *  <p>The object key name prefix when the redirect is applied. For example, to redirect requests for <code>ExamplePage.html</code>, the key prefix will be <code>ExamplePage.html</code>. To redirect request for all pages with the prefix <code>docs/</code>, the key prefix will be <code>/docs</code>, which identifies all objects in the <code>docs/</code> folder. Required when the parent element <code>Condition</code> is specified and sibling <code>HttpErrorCodeReturnedEquals</code> is not specified. If both conditions are specified, both must be true for the redirect to be applied.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString keyPrefixEquals;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::Condition toAWS() const {
        Aws::S3::Model::Condition awsCondition;

		if (!(this->httpErrorCodeReturnedEquals.IsEmpty())) {
            awsCondition.SetHttpErrorCodeReturnedEquals(TCHAR_TO_UTF8(*this->httpErrorCodeReturnedEquals));
        }

		if (!(this->keyPrefixEquals.IsEmpty())) {
            awsCondition.SetKeyPrefixEquals(TCHAR_TO_UTF8(*this->keyPrefixEquals));
        }

        return awsCondition;
    }

    bool IsEmpty() const {
        return this->httpErrorCodeReturnedEquals.IsEmpty() && this->keyPrefixEquals.IsEmpty();
    }

    FS3Condition &fromAWS(const Aws::S3::Model::Condition &awsCondition) {
        this->httpErrorCodeReturnedEquals = UTF8_TO_TCHAR(awsCondition.GetHttpErrorCodeReturnedEquals().c_str());

        this->keyPrefixEquals = UTF8_TO_TCHAR(awsCondition.GetKeyPrefixEquals().c_str());

        return *this;
    }
#endif
};
