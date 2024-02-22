/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/SelectParameters.h"

#endif

#include "Model/AWSS3CRTInputSerialization.h"
#include "Model/AWSS3CRTExpressionType.h"
#include "Model/AWSS3CRTOutputSerialization.h"

#include "AWSS3CRTSelectParameters.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTSelectParameters {
GENERATED_BODY()

    /**
    *  <p>Describes the serialization format of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTInputSerialization inputSerialization;

    /**
    *  <p>The type of the provided expression (for example, SQL).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTExpressionType expressionType = EAWSS3CRTExpressionType::NOT_SET;

    /**
    *  <p>The expression that is used to query the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString expression;

    /**
    *  <p>Describes how the results of the Select job are serialized.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTOutputSerialization outputSerialization;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::SelectParameters toAWS() const {
        Aws::S3Crt::Model::SelectParameters awsSelectParameters;

        if (!(this->inputSerialization.IsEmpty())) {
            awsSelectParameters.SetInputSerialization(this->inputSerialization.toAWS());
        }

        switch(this->expressionType) {
            case EAWSS3CRTExpressionType::SQL:
                awsSelectParameters.SetExpressionType(Aws::S3Crt::Model::ExpressionType::SQL);
                break;
            default:
                break;
        }

        if (!(this->expression.IsEmpty())) {
            awsSelectParameters.SetExpression(TCHAR_TO_UTF8(*this->expression));
        }

        if (!(this->outputSerialization.IsEmpty())) {
            awsSelectParameters.SetOutputSerialization(this->outputSerialization.toAWS());
        }

        return awsSelectParameters;
    }

    bool IsEmpty() const {
        return this->inputSerialization.IsEmpty() && this->expressionType == EAWSS3CRTExpressionType::NOT_SET && this->expression.IsEmpty() && this->outputSerialization.IsEmpty();
    }
#endif
};
