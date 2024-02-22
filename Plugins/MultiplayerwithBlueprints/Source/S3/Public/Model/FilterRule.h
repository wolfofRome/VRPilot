/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/FilterRule.h"

#endif

#include "Model/FilterRuleName.h"

#include "FilterRule.generated.h"

USTRUCT(BlueprintType)
struct FFilterRule {
GENERATED_BODY()

    /**
    *  <p>The object key name prefix or suffix identifying one or more objects to which the filtering rule applies. The maximum length is 1,024 characters. Overlapping prefixes and suffixes are not supported. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/dev/NotificationHowTo.html">Configuring Event Notifications</a> in the <i>Amazon Simple Storage Service Developer Guide</i>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSFilterRuleName name = EAWSFilterRuleName::NOT_SET;

    /**
    *  <p>The value that the filter searches for in object key names.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString value;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::FilterRule toAWS() const {
        Aws::S3::Model::FilterRule awsFilterRule;

        switch(this->name) {
            case EAWSFilterRuleName::prefix:
                awsFilterRule.SetName(Aws::S3::Model::FilterRuleName::prefix);
                break;
            case EAWSFilterRuleName::suffix:
                awsFilterRule.SetName(Aws::S3::Model::FilterRuleName::suffix);
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
        return name == EAWSFilterRuleName::NOT_SET && this->value.IsEmpty();
    }

    FFilterRule &fromAWS(const Aws::S3::Model::FilterRule &awsFilterRule) {
        switch(awsFilterRule.GetName()) {
            case Aws::S3::Model::FilterRuleName::NOT_SET:
                this->name = EAWSFilterRuleName::NOT_SET;
                break;
            case Aws::S3::Model::FilterRuleName::prefix:
                this->name = EAWSFilterRuleName::prefix;
                break;
            case Aws::S3::Model::FilterRuleName::suffix:
                this->name = EAWSFilterRuleName::suffix;
                break;
            default:
                this->name = EAWSFilterRuleName::NOT_SET;
                break;
        }

        this->value = UTF8_TO_TCHAR(awsFilterRule.GetValue().c_str());

        return *this;
    }
#endif
};
