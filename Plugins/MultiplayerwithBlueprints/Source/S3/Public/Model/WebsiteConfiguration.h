/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/WebsiteConfiguration.h"

#endif

#include "Model/ErrorDocument.h"
#include "Model/IndexDocument.h"
#include "Model/RedirectAllRequestsTo.h"
#include "Model/RoutingRule.h"

#include "WebsiteConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FWebsiteConfiguration {
GENERATED_BODY()

    /**
    *  <p>The name of the error document for the website.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FErrorDocument errorDocument;

    /**
    *  <p>The name of the index document for the website.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FIndexDocument indexDocument;

    /**
    *  <p>The redirect behavior for every request to this bucket's website endpoint.</p>  <p>If you specify this property, you can't specify any other property.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FRedirectAllRequestsTo redirectAllRequestsTo;

    /**
    *  <p>Rules that define when a redirect is applied and the redirect behavior.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FRoutingRule> routingRules;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::WebsiteConfiguration toAWS() const {
        Aws::S3::Model::WebsiteConfiguration awsWebsiteConfiguration;

        if (!(this->errorDocument.IsEmpty())) {
            awsWebsiteConfiguration.SetErrorDocument(this->errorDocument.toAWS());
        }

        if (!(this->indexDocument.IsEmpty())) {
            awsWebsiteConfiguration.SetIndexDocument(this->indexDocument.toAWS());
        }

        if (!(this->redirectAllRequestsTo.IsEmpty())) {
            awsWebsiteConfiguration.SetRedirectAllRequestsTo(this->redirectAllRequestsTo.toAWS());
        }

        for (const FRoutingRule& elem : this->routingRules) {
            awsWebsiteConfiguration.AddRoutingRules(elem.toAWS());
        }

        return awsWebsiteConfiguration;
    }

    bool IsEmpty() const {
        return this->errorDocument.IsEmpty() && this->indexDocument.IsEmpty() && this->redirectAllRequestsTo.IsEmpty() && this->routingRules.Num() == 0;
    }
#endif
};
