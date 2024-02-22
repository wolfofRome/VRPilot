/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/CreateBucketConfiguration.h"

#endif

#include "Model/BucketLocationConstraint.h"

#include "CreateBucketConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FCreateBucketConfiguration {
GENERATED_BODY()

    /**
    *  <p>Specifies the Region where the bucket will be created. If you don't specify a Region, the bucket is created in the US East (N. Virginia) Region (us-east-1).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSBucketLocationConstraint locationConstraint = EAWSBucketLocationConstraint::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::CreateBucketConfiguration toAWS() const {
        Aws::S3::Model::CreateBucketConfiguration awsCreateBucketConfiguration;

        switch(this->locationConstraint) {
            case EAWSBucketLocationConstraint::af_south_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::af_south_1);
                break;
            case EAWSBucketLocationConstraint::ap_east_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::ap_east_1);
                break;
            case EAWSBucketLocationConstraint::ap_northeast_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::ap_northeast_1);
                break;
            case EAWSBucketLocationConstraint::ap_northeast_2:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::ap_northeast_2);
                break;
            case EAWSBucketLocationConstraint::ap_northeast_3:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::ap_northeast_3);
                break;
            case EAWSBucketLocationConstraint::ap_south_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::ap_south_1);
                break;
            case EAWSBucketLocationConstraint::ap_southeast_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::ap_southeast_1);
                break;
            case EAWSBucketLocationConstraint::ap_southeast_2:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::ap_southeast_2);
                break;
            case EAWSBucketLocationConstraint::ap_southeast_3:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::ap_southeast_3);
                break;
            case EAWSBucketLocationConstraint::ca_central_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::ca_central_1);
                break;
            case EAWSBucketLocationConstraint::cn_north_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::cn_north_1);
                break;
            case EAWSBucketLocationConstraint::cn_northwest_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::cn_northwest_1);
                break;
            case EAWSBucketLocationConstraint::EU:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::EU);
                break;
            case EAWSBucketLocationConstraint::eu_central_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::eu_central_1);
                break;
            case EAWSBucketLocationConstraint::eu_north_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::eu_north_1);
                break;
            case EAWSBucketLocationConstraint::eu_south_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::eu_south_1);
                break;
            case EAWSBucketLocationConstraint::eu_west_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::eu_west_1);
                break;
            case EAWSBucketLocationConstraint::eu_west_2:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::eu_west_2);
                break;
            case EAWSBucketLocationConstraint::eu_west_3:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::eu_west_3);
                break;
            case EAWSBucketLocationConstraint::me_south_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::me_south_1);
                break;
            case EAWSBucketLocationConstraint::sa_east_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::sa_east_1);
                break;
            case EAWSBucketLocationConstraint::us_east_2:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::us_east_2);
                break;
            case EAWSBucketLocationConstraint::us_gov_east_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::us_gov_east_1);
                break;
            case EAWSBucketLocationConstraint::us_gov_west_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::us_gov_west_1);
                break;
            case EAWSBucketLocationConstraint::us_west_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::us_west_1);
                break;
            case EAWSBucketLocationConstraint::us_west_2:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::us_west_2);
                break;
            case EAWSBucketLocationConstraint::us_iso_west_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::us_iso_west_1);
                break;
            case EAWSBucketLocationConstraint::us_east_1:
                awsCreateBucketConfiguration.SetLocationConstraint(Aws::S3::Model::BucketLocationConstraint::us_east_1);
                break;
            default:
                break;
        }

        return awsCreateBucketConfiguration;
    }

    bool IsEmpty() const {
        return locationConstraint == EAWSBucketLocationConstraint::NOT_SET;
    }
#endif
};
