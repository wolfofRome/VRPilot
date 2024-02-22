/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, May 2019
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK

#include "aws/s3-crt/ClientConfiguration.h"

#endif

#include "Http/AWSHttpTypes.h"

#include "AWSS3CRTClientConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTClientConfiguration {
    GENERATED_USTRUCT_BODY()

    FAWSS3CRTClientConfiguration() :
            scheme("https"),
            region("us-east-1"),
            useDualStack(false),
            enableHostPrefixInjection(false),
            throughputTargetGbps(2.0),
            partSize(5 * 1024 * 1024) {
    }

public:

    /**
     * Http scheme to use. E.g. Http or Https. Default HTTPS
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="S3CRT Client")
    FString scheme;

    /**
     * AWS Region to use in signing requests. Should be lower case. Default us-east-1
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="S3CRT Client")
    FString region;

    /**
     * Use dual stack endpoint in the endpoint calculation. It is your responsibility to verify that the service supports ipv6 in the region you select.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="S3CRT Client")
    bool useDualStack = false;

    /**
     * Override the http endpoint used to talk to a service.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="S3CRT Client")
    FString endpointOverride;

    /**
     * Enable host prefix injection.
     * For services whose endpoint is injectable. e.g. servicediscovery, you can modify the http host's prefix so as to add "data-" prefix for DiscoverInstances request.
     * Default to true, enabled. You can disable it for testing purpose.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="S3CRT Client")
    bool enableHostPrefixInjection = false;

    /* Throughput target in Gbps that we are trying to reach. Normally it's the NIC's throughput */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="S3CRT Client")
    float throughputTargetGbps = 0.0f;

    /* Size of parts the files will be downloaded or uploaded in. Useful for Put/GetObject APIs. defaults to 5MB, if user set it to be less than 5MB, SDK will set it to 5MB. */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="S3CRT Client")
    int partSize = 0;

#if WITH_S3CRTCLIENTSDK
public:
    Aws::S3Crt::ClientConfiguration toAWS() const {
        Aws::S3Crt::ClientConfiguration awsClientConfiguration;
        awsClientConfiguration.scheme = Aws::Http::SchemeMapper::FromString(TCHAR_TO_UTF8(*this->scheme));
        awsClientConfiguration.region = TCHAR_TO_UTF8(*this->region);
        awsClientConfiguration.endpointOverride = TCHAR_TO_UTF8(*this->endpointOverride);
        awsClientConfiguration.useDualStack = this->useDualStack;
        awsClientConfiguration.throughputTargetGbps = this->throughputTargetGbps;
        awsClientConfiguration.partSize = this->partSize;
        awsClientConfiguration.enableHostPrefixInjection = this->enableHostPrefixInjection;
        return awsClientConfiguration;
    };
#endif
};
