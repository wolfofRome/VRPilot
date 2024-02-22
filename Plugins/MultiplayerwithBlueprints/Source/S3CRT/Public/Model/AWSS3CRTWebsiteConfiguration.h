/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/WebsiteConfiguration.h"

#endif

#include "Model/AWSS3CRTErrorDocument.h"
#include "Model/AWSS3CRTIndexDocument.h"
#include "Model/AWSS3CRTRedirectAllRequestsTo.h"
#include "Model/AWSS3CRTRoutingRule.h"

#include "AWSS3CRTWebsiteConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTWebsiteConfiguration {
GENERATED_BODY()

    /**
    *  <p>The name of the error document for the website.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTErrorDocument errorDocument;

    /**
    *  <p>The name of the index document for the website.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTIndexDocument indexDocument;

    /**
    *  <p>The redirect behavior for every request to this bucket's website endpoint.</p>  <p>If you specify this property, you can't specify any other property.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTRedirectAllRequestsTo redirectAllRequestsTo;

    /**
    *  <p>Rules that define when a redirect is applied and the redirect behavior.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTRoutingRule> routingRules;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::WebsiteConfiguration toAWS() const {
        Aws::S3Crt::Model::WebsiteConfiguration awsWebsiteConfiguration;

        if (!(this->errorDocument.IsEmpty())) {
            awsWebsiteConfiguration.SetErrorDocument(this->errorDocument.toAWS());
        }

        if (!(this->indexDocument.IsEmpty())) {
            awsWebsiteConfiguration.SetIndexDocument(this->indexDocument.toAWS());
        }

        if (!(this->redirectAllRequestsTo.IsEmpty())) {
            awsWebsiteConfiguration.SetRedirectAllRequestsTo(this->redirectAllRequestsTo.toAWS());
        }

        for (const FAWSS3CRTRoutingRule& elem : this->routingRules) {
            awsWebsiteConfiguration.AddRoutingRules(elem.toAWS());
        }

        return awsWebsiteConfiguration;
    }

    bool IsEmpty() const {
        return this->errorDocument.IsEmpty() && this->indexDocument.IsEmpty() && this->redirectAllRequestsTo.IsEmpty() && this->routingRules.Num() == 0;
    }
#endif
};
