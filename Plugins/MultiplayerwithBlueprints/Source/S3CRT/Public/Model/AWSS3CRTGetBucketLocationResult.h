/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/GetBucketLocationResult.h"

#endif

#include "Model/AWSS3CRTBucketLocationConstraint.h"

#include "AWSS3CRTGetBucketLocationResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetBucketLocationResult {
GENERATED_BODY()

    /**
    *  <p>Specifies the Region where the bucket resides. For a list of all the Amazon S3 supported location constraints by Region, see <a href="https://docs.aws.amazon.com/general/latest/gr/rande.html#s3_region">Regions and Endpoints</a>. Buckets in Region <code>us-east-1</code> have a LocationConstraint of <code>null</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTBucketLocationConstraint locationConstraint = EAWSS3CRTBucketLocationConstraint::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetBucketLocationResult &fromAWS(const Aws::S3Crt::Model::GetBucketLocationResult &awsGetBucketLocationResult) {
        switch(awsGetBucketLocationResult.GetLocationConstraint()) {
            case Aws::S3Crt::Model::BucketLocationConstraint::NOT_SET:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::NOT_SET;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::af_south_1:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::af_south_1;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::ap_east_1:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::ap_east_1;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::ap_northeast_1:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::ap_northeast_1;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::ap_northeast_2:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::ap_northeast_2;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::ap_northeast_3:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::ap_northeast_3;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::ap_south_1:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::ap_south_1;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::ap_southeast_1:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::ap_southeast_1;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::ap_southeast_2:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::ap_southeast_2;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::ca_central_1:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::ca_central_1;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::cn_north_1:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::cn_north_1;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::cn_northwest_1:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::cn_northwest_1;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::EU:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::EU;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::eu_central_1:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::eu_central_1;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::eu_north_1:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::eu_north_1;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::eu_south_1:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::eu_south_1;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::eu_west_1:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::eu_west_1;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::eu_west_2:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::eu_west_2;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::eu_west_3:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::eu_west_3;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::me_south_1:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::me_south_1;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::sa_east_1:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::sa_east_1;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::us_east_2:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::us_east_2;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::us_gov_east_1:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::us_gov_east_1;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::us_gov_west_1:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::us_gov_west_1;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::us_west_1:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::us_west_1;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::us_west_2:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::us_west_2;
                break;
            case Aws::S3Crt::Model::BucketLocationConstraint::us_east_1:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::us_east_1;
                break;
            default:
                this->locationConstraint = EAWSS3CRTBucketLocationConstraint::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
