/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/SelectParameters.h"

#endif

#include "Model/InputSerialization.h"
#include "Model/ExpressionType.h"
#include "Model/OutputSerialization.h"

#include "SelectParameters.generated.h"

USTRUCT(BlueprintType)
struct FSelectParameters {
GENERATED_BODY()

    /**
    *  <p>Describes the serialization format of the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FInputSerialization inputSerialization;

    /**
    *  <p>The type of the provided expression (for example, SQL).</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSExpressionType expressionType = EAWSExpressionType::NOT_SET;

    /**
    *  <p>The expression that is used to query the object.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString expression;

    /**
    *  <p>Describes how the results of the Select job are serialized.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FOutputSerialization outputSerialization;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::SelectParameters toAWS() const {
        Aws::S3::Model::SelectParameters awsSelectParameters;

        if (!(this->inputSerialization.IsEmpty())) {
            awsSelectParameters.SetInputSerialization(this->inputSerialization.toAWS());
        }

        switch(this->expressionType) {
            case EAWSExpressionType::SQL:
                awsSelectParameters.SetExpressionType(Aws::S3::Model::ExpressionType::SQL);
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
        return this->inputSerialization.IsEmpty() && expressionType == EAWSExpressionType::NOT_SET && this->expression.IsEmpty() && this->outputSerialization.IsEmpty();
    }
#endif
};
