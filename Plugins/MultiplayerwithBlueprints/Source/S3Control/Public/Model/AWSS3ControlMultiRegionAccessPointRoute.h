/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/MultiRegionAccessPointRoute.h"

#endif

#include "AWSS3ControlMultiRegionAccessPointRoute.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlMultiRegionAccessPointRoute {
GENERATED_BODY()

    /**
    *  <p>The name of the Amazon S3 bucket for which you'll submit a routing configuration change. Either the <code>Bucket</code> or the <code>Region</code> value must be provided. If both are provided, the bucket must be in the specified Region.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString bucket;

    /**
    *  <p>The Amazon Web Services Region to which you'll be submitting a routing configuration change. Either the <code>Bucket</code> or the <code>Region</code> value must be provided. If both are provided, the bucket must be in the specified Region.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString region;

    /**
    *  <p>The traffic state for the specified bucket or Amazon Web Services Region. </p> <p>A value of <code>0</code> indicates a passive state, which means that no new traffic will be routed to the Region. </p> <p>A value of <code>100</code> indicates an active state, which means that traffic will be routed to the specified Region. </p> <p>When the routing configuration for a Region is changed from active to passive, any in-progress operations (uploads, copies, deletes, and so on) to the formerly active Region will continue to run to until a final success or failure status is reached.</p> <p>If all Regions in the routing configuration are designated as passive, you'll receive an <code>InvalidRequest</code> error. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    int trafficDialPercentage = 0;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::MultiRegionAccessPointRoute toAWS() const {
        Aws::S3Control::Model::MultiRegionAccessPointRoute awsMultiRegionAccessPointRoute;

		if (!(this->bucket.IsEmpty())) {
            awsMultiRegionAccessPointRoute.SetBucket(TCHAR_TO_UTF8(*this->bucket));
        }

        if (!(this->region.IsEmpty())) {
            awsMultiRegionAccessPointRoute.SetRegion(TCHAR_TO_UTF8(*this->region));
        }

        if (!(this->trafficDialPercentage == 0)) {
            awsMultiRegionAccessPointRoute.SetTrafficDialPercentage(this->trafficDialPercentage);
        }

        return awsMultiRegionAccessPointRoute;
    }

    bool IsEmpty() const {
        return this->bucket.IsEmpty() && this->region.IsEmpty() && this->trafficDialPercentage == 0;
    }

    FAWSS3ControlMultiRegionAccessPointRoute &fromAWS(const Aws::S3Control::Model::MultiRegionAccessPointRoute &awsMultiRegionAccessPointRoute) {
        this->bucket = UTF8_TO_TCHAR(awsMultiRegionAccessPointRoute.GetBucket().c_str());

        this->region = UTF8_TO_TCHAR(awsMultiRegionAccessPointRoute.GetRegion().c_str());

		this->trafficDialPercentage = awsMultiRegionAccessPointRoute.GetTrafficDialPercentage();

        return *this;
    }
#endif
};
