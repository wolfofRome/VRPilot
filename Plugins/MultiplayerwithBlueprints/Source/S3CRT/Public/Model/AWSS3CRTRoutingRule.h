/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/RoutingRule.h"

#endif

#include "Model/AWSS3CRTCondition.h"
#include "Model/AWSS3CRTRedirect.h"

#include "AWSS3CRTRoutingRule.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTRoutingRule {
GENERATED_BODY()

    /**
    *  <p>A container for describing a condition that must be met for the specified redirect to apply. For example, 1. If request is for pages in the <code>/docs</code> folder, redirect to the <code>/documents</code> folder. 2. If request results in HTTP error 4xx, redirect request to another host where you might process the error.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTCondition condition;

    /**
    *  <p>Container for redirect information. You can redirect requests to another host, to another page, or with another protocol. In the event of an error, you can specify a different error code to return.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTRedirect redirect;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::RoutingRule toAWS() const {
        Aws::S3Crt::Model::RoutingRule awsRoutingRule;

        if (!(this->condition.IsEmpty())) {
            awsRoutingRule.SetCondition(this->condition.toAWS());
        }

        if (!(this->redirect.IsEmpty())) {
            awsRoutingRule.SetRedirect(this->redirect.toAWS());
        }

        return awsRoutingRule;
    }

    bool IsEmpty() const {
        return this->condition.IsEmpty() && this->redirect.IsEmpty();
    }

    FAWSS3CRTRoutingRule &fromAWS(const Aws::S3Crt::Model::RoutingRule &awsRoutingRule) {
        this->condition = FAWSS3CRTCondition().fromAWS(awsRoutingRule.GetCondition());

        this->redirect = FAWSS3CRTRedirect().fromAWS(awsRoutingRule.GetRedirect());

        return *this;
    }
#endif
};
