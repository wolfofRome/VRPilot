/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/ObjectLambdaTransformationConfiguration.h"

#endif

#include "Model/AWSS3ControlObjectLambdaTransformationConfigurationAction.h"
#include "Model/AWSS3ControlObjectLambdaContentTransformation.h"

#include "AWSS3ControlObjectLambdaTransformationConfiguration.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlObjectLambdaTransformationConfiguration {
GENERATED_BODY()

    /**
    *  <p>A container for the action of an Object Lambda Access Point configuration. Valid input is <code>GetObject</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<EAWSS3ControlObjectLambdaTransformationConfigurationAction> actions;

    /**
    *  <p>A container for the content transformation of an Object Lambda Access Point configuration.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FAWSS3ControlObjectLambdaContentTransformation contentTransformation;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    Aws::S3Control::Model::ObjectLambdaTransformationConfiguration toAWS() const {
        Aws::S3Control::Model::ObjectLambdaTransformationConfiguration awsObjectLambdaTransformationConfiguration;

        for (const EAWSS3ControlObjectLambdaTransformationConfigurationAction& elem : this->actions) {
		    switch(elem) {
                case EAWSS3ControlObjectLambdaTransformationConfigurationAction::GetObject:
                    awsObjectLambdaTransformationConfiguration.AddActions(Aws::S3Control::Model::ObjectLambdaTransformationConfigurationAction::GetObject);
                    break;
                case EAWSS3ControlObjectLambdaTransformationConfigurationAction::HeadObject:
                    awsObjectLambdaTransformationConfiguration.AddActions(Aws::S3Control::Model::ObjectLambdaTransformationConfigurationAction::HeadObject);
                    break;
                case EAWSS3ControlObjectLambdaTransformationConfigurationAction::ListObjects:
                    awsObjectLambdaTransformationConfiguration.AddActions(Aws::S3Control::Model::ObjectLambdaTransformationConfigurationAction::ListObjects);
                    break;
                case EAWSS3ControlObjectLambdaTransformationConfigurationAction::ListObjectsV2:
                    awsObjectLambdaTransformationConfiguration.AddActions(Aws::S3Control::Model::ObjectLambdaTransformationConfigurationAction::ListObjectsV2);
                    break;
                default:
                    break;
            };
        }

        if (!(this->contentTransformation.IsEmpty())) {
            awsObjectLambdaTransformationConfiguration.SetContentTransformation(this->contentTransformation.toAWS());
        }

        return awsObjectLambdaTransformationConfiguration;
    }

    bool IsEmpty() const {
        return this->actions.Num() == 0 && this->contentTransformation.IsEmpty();
    }

    FAWSS3ControlObjectLambdaTransformationConfiguration &fromAWS(const Aws::S3Control::Model::ObjectLambdaTransformationConfiguration &awsObjectLambdaTransformationConfiguration) {
        this->actions.Empty();
        for (const Aws::S3Control::Model::ObjectLambdaTransformationConfigurationAction& elem : awsObjectLambdaTransformationConfiguration.GetActions()) {
            switch(elem) {
                case Aws::S3Control::Model::ObjectLambdaTransformationConfigurationAction::NOT_SET:
                    this->actions.Add(EAWSS3ControlObjectLambdaTransformationConfigurationAction::NOT_SET);
                    break;
                case Aws::S3Control::Model::ObjectLambdaTransformationConfigurationAction::GetObject:
                    this->actions.Add(EAWSS3ControlObjectLambdaTransformationConfigurationAction::GetObject);
                    break;
                case Aws::S3Control::Model::ObjectLambdaTransformationConfigurationAction::HeadObject:
                    this->actions.Add(EAWSS3ControlObjectLambdaTransformationConfigurationAction::HeadObject);
                    break;
                case Aws::S3Control::Model::ObjectLambdaTransformationConfigurationAction::ListObjects:
                    this->actions.Add(EAWSS3ControlObjectLambdaTransformationConfigurationAction::ListObjects);
                    break;
                case Aws::S3Control::Model::ObjectLambdaTransformationConfigurationAction::ListObjectsV2:
                    this->actions.Add(EAWSS3ControlObjectLambdaTransformationConfigurationAction::ListObjectsV2);
                    break;
                default:
                    break;
		    };
        }

        this->contentTransformation.fromAWS(awsObjectLambdaTransformationConfiguration.GetContentTransformation());

        return *this;
    }
#endif
};
