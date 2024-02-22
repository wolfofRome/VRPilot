/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/CreateBucketConfiguration.h"

#endif

#include "Model/AWSS3ControlBucketLocationConstraint.h"

#include "AWSS3ControlCreateBucketConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlCreateBucketConfiguration {
GENERATED_BODY()

    /**
    *  <p>Specifies the Region where the bucket will be created. If you are creating a bucket on the US East (N. Virginia) Region (us-east-1), you do not need to specify the location. </p>  <p>This is not supported by Amazon S3 on Outposts buckets.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ControlBucketLocationConstraint locationConstraint = EAWSS3ControlBucketLocationConstraint::NOT_SET;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::CreateBucketConfiguration toAWS() const {
        Aws::S3Control::Model::CreateBucketConfiguration awsCreateBucketConfiguration;

        switch(this->locationConstraint) {
            case EAWSS3ControlBucketLocationConstraint::EU:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Control::Model::BucketLocationConstraint::EU);
                break;
            case EAWSS3ControlBucketLocationConstraint::eu_west_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Control::Model::BucketLocationConstraint::eu_west_1);
                break;
            case EAWSS3ControlBucketLocationConstraint::us_west_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Control::Model::BucketLocationConstraint::us_west_1);
                break;
            case EAWSS3ControlBucketLocationConstraint::us_west_2:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Control::Model::BucketLocationConstraint::us_west_2);
                break;
            case EAWSS3ControlBucketLocationConstraint::ap_south_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Control::Model::BucketLocationConstraint::ap_south_1);
                break;
            case EAWSS3ControlBucketLocationConstraint::ap_southeast_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Control::Model::BucketLocationConstraint::ap_southeast_1);
                break;
            case EAWSS3ControlBucketLocationConstraint::ap_southeast_2:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Control::Model::BucketLocationConstraint::ap_southeast_2);
                break;
            case EAWSS3ControlBucketLocationConstraint::ap_northeast_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Control::Model::BucketLocationConstraint::ap_northeast_1);
                break;
            case EAWSS3ControlBucketLocationConstraint::sa_east_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Control::Model::BucketLocationConstraint::sa_east_1);
                break;
            case EAWSS3ControlBucketLocationConstraint::cn_north_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Control::Model::BucketLocationConstraint::cn_north_1);
                break;
            case EAWSS3ControlBucketLocationConstraint::eu_central_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Control::Model::BucketLocationConstraint::eu_central_1);
                break;
            default:
                break;
            }
        return awsCreateBucketConfiguration;
    }

    bool IsEmpty() const {
        return this->locationConstraint == EAWSS3ControlBucketLocationConstraint::NOT_SET;
    }
#endif
};
