/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/ObjectLambdaConfiguration.h"

#endif

#include "Model/AWSS3ControlObjectLambdaAllowedFeature.h"
#include "Model/AWSS3ControlObjectLambdaTransformationConfiguration.h"

#include "AWSS3ControlObjectLambdaConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlObjectLambdaConfiguration {
GENERATED_BODY()

    /**
    *  <p>Standard access point associated with the Object Lambda Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString supportingAccessPoint;

    /**
    *  <p>A container for whether the CloudWatch metrics configuration is enabled.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    bool cloudWatchMetricsEnabled = false;

    /**
    *  <p>A container for allowed features. Valid inputs are <code>GetObject-Range</code> and <code>GetObject-PartNumber</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<EAWSS3ControlObjectLambdaAllowedFeature> allowedFeatures;

    /**
    *  <p>A container for transformation configurations for an Object Lambda Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FAWSS3ControlObjectLambdaTransformationConfiguration> transformationConfigurations;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::ObjectLambdaConfiguration toAWS() const {
        Aws::S3Control::Model::ObjectLambdaConfiguration awsObjectLambdaConfiguration;

        if (!(this->supportingAccessPoint.IsEmpty())) {
            awsObjectLambdaConfiguration.SetSupportingAccessPoint(TCHAR_TO_UTF8(*this->supportingAccessPoint));
        }

        if (!(false)) {
            awsObjectLambdaConfiguration.SetCloudWatchMetricsEnabled(this->cloudWatchMetricsEnabled);
        }

        for (const EAWSS3ControlObjectLambdaAllowedFeature& elem : this->allowedFeatures) {
		    switch(elem) {
                case EAWSS3ControlObjectLambdaAllowedFeature::GetObject_Range:
                    awsObjectLambdaConfiguration.AddAllowedFeatures(Aws::S3Control::Model::ObjectLambdaAllowedFeature::GetObject_Range);
                    break;
                case EAWSS3ControlObjectLambdaAllowedFeature::GetObject_PartNumber:
                    awsObjectLambdaConfiguration.AddAllowedFeatures(Aws::S3Control::Model::ObjectLambdaAllowedFeature::GetObject_PartNumber);
                    break;
                case EAWSS3ControlObjectLambdaAllowedFeature::HeadObject_Range:
                    awsObjectLambdaConfiguration.AddAllowedFeatures(Aws::S3Control::Model::ObjectLambdaAllowedFeature::HeadObject_Range);
                    break;
                case EAWSS3ControlObjectLambdaAllowedFeature::HeadObject_PartNumber:
                    awsObjectLambdaConfiguration.AddAllowedFeatures(Aws::S3Control::Model::ObjectLambdaAllowedFeature::HeadObject_PartNumber);
                    break;
                default:
                    break;
            };
        }

        for (const FAWSS3ControlObjectLambdaTransformationConfiguration& elem : this->transformationConfigurations) {
            awsObjectLambdaConfiguration.AddTransformationConfigurations(elem.toAWS());
        }

        return awsObjectLambdaConfiguration;
    }

    bool IsEmpty() const {
        return this->supportingAccessPoint.IsEmpty() && false && this->allowedFeatures.Num() == 0 && this->transformationConfigurations.Num() == 0;
    }

    FAWSS3ControlObjectLambdaConfiguration &fromAWS(const Aws::S3Control::Model::ObjectLambdaConfiguration &awsObjectLambdaConfiguration) {
        this->supportingAccessPoint = UTF8_TO_TCHAR(awsObjectLambdaConfiguration.GetSupportingAccessPoint().c_str());

        this->cloudWatchMetricsEnabled = awsObjectLambdaConfiguration.GetCloudWatchMetricsEnabled();

        this->allowedFeatures.Empty();
        for (const Aws::S3Control::Model::ObjectLambdaAllowedFeature& elem : awsObjectLambdaConfiguration.GetAllowedFeatures()) {
            switch(elem) {
                case Aws::S3Control::Model::ObjectLambdaAllowedFeature::NOT_SET:
                    this->allowedFeatures.Add(EAWSS3ControlObjectLambdaAllowedFeature::NOT_SET);
                    break;
                case Aws::S3Control::Model::ObjectLambdaAllowedFeature::GetObject_Range:
                    this->allowedFeatures.Add(EAWSS3ControlObjectLambdaAllowedFeature::GetObject_Range);
                    break;
                case Aws::S3Control::Model::ObjectLambdaAllowedFeature::GetObject_PartNumber:
                    this->allowedFeatures.Add(EAWSS3ControlObjectLambdaAllowedFeature::GetObject_PartNumber);
                    break;
                case Aws::S3Control::Model::ObjectLambdaAllowedFeature::HeadObject_Range:
                    this->allowedFeatures.Add(EAWSS3ControlObjectLambdaAllowedFeature::HeadObject_Range);
                    break;
                case Aws::S3Control::Model::ObjectLambdaAllowedFeature::HeadObject_PartNumber:
                    this->allowedFeatures.Add(EAWSS3ControlObjectLambdaAllowedFeature::HeadObject_PartNumber);
                    break;
                default:
                    break;
		    };
        }

        this->transformationConfigurations.Empty();
        for (const Aws::S3Control::Model::ObjectLambdaTransformationConfiguration& elem : awsObjectLambdaConfiguration.GetTransformationConfigurations()) {
            this->transformationConfigurations.Add(FAWSS3ControlObjectLambdaTransformationConfiguration().fromAWS(elem));
        }

        return *this;
    }
#endif
};
