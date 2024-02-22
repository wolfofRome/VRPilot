/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/CreateBucketConfiguration.h"

#endif

#include "Model/AWSS3CRTBucketLocationConstraint.h"

#include "AWSS3CRTCreateBucketConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTCreateBucketConfiguration {
GENERATED_BODY()

    /**
    *  <p>Specifies the Region where the bucket will be created. If you don't specify a Region, the bucket is created in the US East (N. Virginia) Region (us-east-1).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTBucketLocationConstraint locationConstraint = EAWSS3CRTBucketLocationConstraint::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::CreateBucketConfiguration toAWS() const {
        Aws::S3Crt::Model::CreateBucketConfiguration awsCreateBucketConfiguration;

        switch(this->locationConstraint) {
            case EAWSS3CRTBucketLocationConstraint::af_south_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::af_south_1);
                break;
            case EAWSS3CRTBucketLocationConstraint::ap_east_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::ap_east_1);
                break;
            case EAWSS3CRTBucketLocationConstraint::ap_northeast_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::ap_northeast_1);
                break;
            case EAWSS3CRTBucketLocationConstraint::ap_northeast_2:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::ap_northeast_2);
                break;
            case EAWSS3CRTBucketLocationConstraint::ap_northeast_3:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::ap_northeast_3);
                break;
            case EAWSS3CRTBucketLocationConstraint::ap_south_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::ap_south_1);
                break;
            case EAWSS3CRTBucketLocationConstraint::ap_southeast_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::ap_southeast_1);
                break;
            case EAWSS3CRTBucketLocationConstraint::ap_southeast_2:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::ap_southeast_2);
                break;
            case EAWSS3CRTBucketLocationConstraint::ca_central_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::ca_central_1);
                break;
            case EAWSS3CRTBucketLocationConstraint::cn_north_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::cn_north_1);
                break;
            case EAWSS3CRTBucketLocationConstraint::cn_northwest_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::cn_northwest_1);
                break;
            case EAWSS3CRTBucketLocationConstraint::EU:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::EU);
                break;
            case EAWSS3CRTBucketLocationConstraint::eu_central_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::eu_central_1);
                break;
            case EAWSS3CRTBucketLocationConstraint::eu_north_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::eu_north_1);
                break;
            case EAWSS3CRTBucketLocationConstraint::eu_south_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::eu_south_1);
                break;
            case EAWSS3CRTBucketLocationConstraint::eu_west_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::eu_west_1);
                break;
            case EAWSS3CRTBucketLocationConstraint::eu_west_2:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::eu_west_2);
                break;
            case EAWSS3CRTBucketLocationConstraint::eu_west_3:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::eu_west_3);
                break;
            case EAWSS3CRTBucketLocationConstraint::me_south_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::me_south_1);
                break;
            case EAWSS3CRTBucketLocationConstraint::sa_east_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::sa_east_1);
                break;
            case EAWSS3CRTBucketLocationConstraint::us_east_2:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::us_east_2);
                break;
            case EAWSS3CRTBucketLocationConstraint::us_gov_east_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::us_gov_east_1);
                break;
            case EAWSS3CRTBucketLocationConstraint::us_gov_west_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::us_gov_west_1);
                break;
            case EAWSS3CRTBucketLocationConstraint::us_west_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::us_west_1);
                break;
            case EAWSS3CRTBucketLocationConstraint::us_west_2:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::us_west_2);
                break;
            case EAWSS3CRTBucketLocationConstraint::us_east_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3Crt::Model::BucketLocationConstraint::us_east_1);
                break;
            default:
                break;
        }

        return awsCreateBucketConfiguration;
    }

    bool IsEmpty() const {
        return this->locationConstraint == EAWSS3CRTBucketLocationConstraint::NOT_SET;
    }
#endif
};
