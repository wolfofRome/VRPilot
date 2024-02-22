/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/GetBucketLocationResult.h"

#endif

#include "Model/BucketLocationConstraint.h"

#include "GetBucketLocationResult.generated.h"

USTRUCT(BlueprintType)
struct FGetBucketLocationResult {
GENERATED_BODY()

    /**
    *  <p>Specifies the Region where the bucket resides. For a list of all the Amazon S3 supported location constraints by Region, see <a href="https://docs.aws.amazon.com/general/latest/gr/rande.html#s3_region">Regions and Endpoints</a>. Buckets in Region <code>us-east-1</code> have a LocationConstraint of <code>null</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSBucketLocationConstraint locationConstraint = EAWSBucketLocationConstraint::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetBucketLocationResult &fromAWS(const Aws::S3::Model::GetBucketLocationResult &awsGetBucketLocationResult) {
        switch(awsGetBucketLocationResult.GetLocationConstraint()) {
            case Aws::S3::Model::BucketLocationConstraint::NOT_SET:
                this->locationConstraint = EAWSBucketLocationConstraint::NOT_SET;
                break;
            case Aws::S3::Model::BucketLocationConstraint::af_south_1:
                this->locationConstraint = EAWSBucketLocationConstraint::af_south_1;
                break;
            case Aws::S3::Model::BucketLocationConstraint::ap_east_1:
                this->locationConstraint = EAWSBucketLocationConstraint::ap_east_1;
                break;
            case Aws::S3::Model::BucketLocationConstraint::ap_northeast_1:
                this->locationConstraint = EAWSBucketLocationConstraint::ap_northeast_1;
                break;
            case Aws::S3::Model::BucketLocationConstraint::ap_northeast_2:
                this->locationConstraint = EAWSBucketLocationConstraint::ap_northeast_2;
                break;
            case Aws::S3::Model::BucketLocationConstraint::ap_northeast_3:
                this->locationConstraint = EAWSBucketLocationConstraint::ap_northeast_3;
                break;
            case Aws::S3::Model::BucketLocationConstraint::ap_south_1:
                this->locationConstraint = EAWSBucketLocationConstraint::ap_south_1;
                break;
            case Aws::S3::Model::BucketLocationConstraint::ap_southeast_1:
                this->locationConstraint = EAWSBucketLocationConstraint::ap_southeast_1;
                break;
            case Aws::S3::Model::BucketLocationConstraint::ap_southeast_2:
                this->locationConstraint = EAWSBucketLocationConstraint::ap_southeast_2;
                break;
            case Aws::S3::Model::BucketLocationConstraint::ap_southeast_3:
                this->locationConstraint = EAWSBucketLocationConstraint::ap_southeast_3;
                break;
            case Aws::S3::Model::BucketLocationConstraint::ca_central_1:
                this->locationConstraint = EAWSBucketLocationConstraint::ca_central_1;
                break;
            case Aws::S3::Model::BucketLocationConstraint::cn_north_1:
                this->locationConstraint = EAWSBucketLocationConstraint::cn_north_1;
                break;
            case Aws::S3::Model::BucketLocationConstraint::cn_northwest_1:
                this->locationConstraint = EAWSBucketLocationConstraint::cn_northwest_1;
                break;
            case Aws::S3::Model::BucketLocationConstraint::EU:
                this->locationConstraint = EAWSBucketLocationConstraint::EU;
                break;
            case Aws::S3::Model::BucketLocationConstraint::eu_central_1:
                this->locationConstraint = EAWSBucketLocationConstraint::eu_central_1;
                break;
            case Aws::S3::Model::BucketLocationConstraint::eu_north_1:
                this->locationConstraint = EAWSBucketLocationConstraint::eu_north_1;
                break;
            case Aws::S3::Model::BucketLocationConstraint::eu_south_1:
                this->locationConstraint = EAWSBucketLocationConstraint::eu_south_1;
                break;
            case Aws::S3::Model::BucketLocationConstraint::eu_west_1:
                this->locationConstraint = EAWSBucketLocationConstraint::eu_west_1;
                break;
            case Aws::S3::Model::BucketLocationConstraint::eu_west_2:
                this->locationConstraint = EAWSBucketLocationConstraint::eu_west_2;
                break;
            case Aws::S3::Model::BucketLocationConstraint::eu_west_3:
                this->locationConstraint = EAWSBucketLocationConstraint::eu_west_3;
                break;
            case Aws::S3::Model::BucketLocationConstraint::me_south_1:
                this->locationConstraint = EAWSBucketLocationConstraint::me_south_1;
                break;
            case Aws::S3::Model::BucketLocationConstraint::sa_east_1:
                this->locationConstraint = EAWSBucketLocationConstraint::sa_east_1;
                break;
            case Aws::S3::Model::BucketLocationConstraint::us_east_2:
                this->locationConstraint = EAWSBucketLocationConstraint::us_east_2;
                break;
            case Aws::S3::Model::BucketLocationConstraint::us_gov_east_1:
                this->locationConstraint = EAWSBucketLocationConstraint::us_gov_east_1;
                break;
            case Aws::S3::Model::BucketLocationConstraint::us_gov_west_1:
                this->locationConstraint = EAWSBucketLocationConstraint::us_gov_west_1;
                break;
            case Aws::S3::Model::BucketLocationConstraint::us_west_1:
                this->locationConstraint = EAWSBucketLocationConstraint::us_west_1;
                break;
            case Aws::S3::Model::BucketLocationConstraint::us_west_2:
                this->locationConstraint = EAWSBucketLocationConstraint::us_west_2;
                break;
            case Aws::S3::Model::BucketLocationConstraint::us_iso_west_1:
                this->locationConstraint = EAWSBucketLocationConstraint::us_iso_west_1;
                break;
            case Aws::S3::Model::BucketLocationConstraint::us_east_1:
                this->locationConstraint = EAWSBucketLocationConstraint::us_east_1;
                break;
            default:
                this->locationConstraint = EAWSBucketLocationConstraint::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
