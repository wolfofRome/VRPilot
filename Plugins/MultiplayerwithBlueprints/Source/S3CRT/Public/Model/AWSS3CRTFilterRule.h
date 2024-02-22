/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/FilterRule.h"

#endif

#include "Model/AWSS3CRTFilterRuleName.h"

#include "AWSS3CRTFilterRule.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTFilterRule {
GENERATED_BODY()

    /**
    *  <p>The object key name prefix or suffix identifying one or more objects to which the filtering rule applies. The maximum length is 1,024 characters. Overlapping prefixes and suffixes are not supported. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/NotificationHowTo.html">Configuring Event Notifications</a> in the <i>Amazon S3 User Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTFilterRuleName name = EAWSS3CRTFilterRuleName::NOT_SET;

    /**
    *  <p>The value that the filter searches for in object key names.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString value;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::FilterRule toAWS() const {
        Aws::S3Crt::Model::FilterRule awsFilterRule;

        switch(this->name) {
            case EAWSS3CRTFilterRuleName::prefix:
                awsFilterRule.SetName(Aws::S3Crt::Model::FilterRuleName::prefix);
                break;
            case EAWSS3CRTFilterRuleName::suffix:
                awsFilterRule.SetName(Aws::S3Crt::Model::FilterRuleName::suffix);
                break;
            default:
                break;
        }

        if (!(this->value.IsEmpty())) {
            awsFilterRule.SetValue(TCHAR_TO_UTF8(*this->value));
        }

        return awsFilterRule;
    }

    bool IsEmpty() const {
        return this->name == EAWSS3CRTFilterRuleName::NOT_SET && this->value.IsEmpty();
    }

    FAWSS3CRTFilterRule &fromAWS(const Aws::S3Crt::Model::FilterRule &awsFilterRule) {
        switch(awsFilterRule.GetName()) {
            case Aws::S3Crt::Model::FilterRuleName::NOT_SET:
                this->name = EAWSS3CRTFilterRuleName::NOT_SET;
                break;
            case Aws::S3Crt::Model::FilterRuleName::prefix:
                this->name = EAWSS3CRTFilterRuleName::prefix;
                break;
            case Aws::S3Crt::Model::FilterRuleName::suffix:
                this->name = EAWSS3CRTFilterRuleName::suffix;
                break;
            default:
                this->name = EAWSS3CRTFilterRuleName::NOT_SET;
                break;
        }

        this->value = UTF8_TO_TCHAR(awsFilterRule.GetValue().c_str());

        return *this;
    }
#endif
};
