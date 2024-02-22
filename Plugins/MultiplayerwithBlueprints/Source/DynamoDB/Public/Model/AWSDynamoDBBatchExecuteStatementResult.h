/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE

#include "aws/dynamodb/model/BatchExecuteStatementResult.h"

#endif

#include "Model/AWSDynamoDBBatchStatementResponse.h"
#include "Model/ConsumedCapacity.h"

#include "AWSDynamoDBBatchExecuteStatementResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSDynamoDBBatchExecuteStatementResult {
GENERATED_BODY()
    /**
    *  <p> The response to each PartiQL statement in the batch. </p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FAWSDynamoDBBatchStatementResponse> responses;

    /**
    *  <p>The capacity units consumed by the entire operation. The values of the list are ordered according to the ordering of the statements.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DynamoDB Client")
    TArray<FConsumedCapacity> consumedCapacity;

#if WITH_DYNAMODBCLIENTSDK && WITH_CORE
public:
    FAWSDynamoDBBatchExecuteStatementResult &fromAWS(const Aws::DynamoDB::Model::BatchExecuteStatementResult &awsBatchExecuteStatementResult) {
        this->responses.Empty();
        for (const Aws::DynamoDB::Model::BatchStatementResponse& elem : awsBatchExecuteStatementResult.GetResponses()) {
            this->responses.Add(FAWSDynamoDBBatchStatementResponse().fromAWS(elem));
        }

        this->consumedCapacity.Empty();
        for (const Aws::DynamoDB::Model::ConsumedCapacity& elem : awsBatchExecuteStatementResult.GetConsumedCapacity()) {
            this->consumedCapacity.Add(FConsumedCapacity().fromAWS(elem));
        }

        return *this;
    }
#endif
};
