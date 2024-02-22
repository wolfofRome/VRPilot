/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketWebsiteResult.h"

#endif

#include "Model/AWSS3CRTRedirectAllRequestsTo.h"
#include "Model/AWSS3CRTIndexDocument.h"
#include "Model/AWSS3CRTErrorDocument.h"
#include "Model/AWSS3CRTRoutingRule.h"

#include "AWSS3CRTGetBucketWebsiteResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketWebsiteResult {
GENERATED_BODY()

    /**
    *  <p>Specifies the redirect behavior of all requests to a website endpoint of an Amazon S3 bucket.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTRedirectAllRequestsTo redirectAllRequestsTo;

    /**
    *  <p>The name of the index document for the website (for example <code>index.html</code>).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTIndexDocument indexDocument;

    /**
    *  <p>The object key name of the website error document to use for 4XX class errors.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTErrorDocument errorDocument;

    /**
    *  <p>Rules that define when a redirect is applied and the redirect behavior.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTRoutingRule> routingRules;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetBucketWebsiteResult &fromAWS(const Aws::S3Crt::Model::GetBucketWebsiteResult &awsGetBucketWebsiteResult) {
        this->redirectAllRequestsTo = FAWSS3CRTRedirectAllRequestsTo().fromAWS(awsGetBucketWebsiteResult.GetRedirectAllRequestsTo());

        this->indexDocument = FAWSS3CRTIndexDocument().fromAWS(awsGetBucketWebsiteResult.GetIndexDocument());

        this->errorDocument = FAWSS3CRTErrorDocument().fromAWS(awsGetBucketWebsiteResult.GetErrorDocument());

        this->routingRules.Empty();
        for (const Aws::S3Crt::Model::RoutingRule& elem : awsGetBucketWebsiteResult.GetRoutingRules()) {
            this->routingRules.Add(FAWSS3CRTRoutingRule().fromAWS(elem));
        }

        return *this;
    }
#endif
};
