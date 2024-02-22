/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/StorageClassAnalysis.h"

#endif

#include "Model/StorageClassAnalysisDataExport.h"

#include "StorageClassAnalysis.generated.h"

USTRUCT(BlueprintType)
struct FStorageClassAnalysis {
GENERATED_BODY()

    /**
    *  <p>Specifies how data related to the storage class analysis for an Amazon S3 bucket should be exported.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FStorageClassAnalysisDataExport dataExport;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::StorageClassAnalysis toAWS() const {
        Aws::S3::Model::StorageClassAnalysis awsStorageClassAnalysis;

        if (!(this->dataExport.IsEmpty())) {
            awsStorageClassAnalysis.SetDataExport(this->dataExport.toAWS());
        }

        return awsStorageClassAnalysis;
    }

    bool IsEmpty() const {
        return this->dataExport.IsEmpty();
    }

    FStorageClassAnalysis &fromAWS(const Aws::S3::Model::StorageClassAnalysis &awsStorageClassAnalysis) {
        this->dataExport.fromAWS(awsStorageClassAnalysis.GetDataExport());

        return *this;
    }
#endif
};
