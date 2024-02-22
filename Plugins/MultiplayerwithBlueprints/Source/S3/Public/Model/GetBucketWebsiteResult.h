/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketWebsiteResult.h"

#endif

#include "Model/RedirectAllRequestsTo.h"
#include "Model/IndexDocument.h"
#include "Model/ErrorDocument.h"
#include "Model/RoutingRule.h"

#include "GetBucketWebsiteResult.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketWebsiteResult {
GENERATED_BODY()

    /**
    *  <p>Specifies the redirect behavior of all requests to a website endpoint of an Amazon S3 bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FRedirectAllRequestsTo redirectAllRequestsTo;

    /**
    *  <p>The name of the index document for the website (for example <code>index.html</code>).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FIndexDocument indexDocument;

    /**
    *  <p>The object key name of the website error document to use for 4XX class errors.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FErrorDocument errorDocument;

    /**
    *  <p>Rules that define when a redirect is applied and the redirect behavior.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FRoutingRule> routingRules;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetBucketWebsiteResult &fromAWS(const Aws::S3::Model::GetBucketWebsiteResult &awsGetBucketWebsiteResult) {
        this->redirectAllRequestsTo.fromAWS(awsGetBucketWebsiteResult.GetRedirectAllRequestsTo());

        this->indexDocument.fromAWS(awsGetBucketWebsiteResult.GetIndexDocument());

        this->errorDocument.fromAWS(awsGetBucketWebsiteResult.GetErrorDocument());

        this->routingRules.Empty();
        for (const Aws::S3::Model::RoutingRule& elem : awsGetBucketWebsiteResult.GetRoutingRules()) {
            this->routingRules.Add(FRoutingRule().fromAWS(elem));
        }

        return *this;
    }
#endif
};
