/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/StorageClassAnalysis.h"

#endif

#include "Model/AWSS3CRTStorageClassAnalysisDataExport.h"

#include "AWSS3CRTStorageClassAnalysis.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTStorageClassAnalysis {
GENERATED_BODY()

    /**
    *  <p>Specifies how data related to the storage class analysis for an Amazon S3 bucket should be exported.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FAWSS3CRTStorageClassAnalysisDataExport dataExport;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::StorageClassAnalysis toAWS() const {
        Aws::S3Crt::Model::StorageClassAnalysis awsStorageClassAnalysis;

        if (!(this->dataExport.IsEmpty())) {
            awsStorageClassAnalysis.SetDataExport(this->dataExport.toAWS());
        }

        return awsStorageClassAnalysis;
    }

    bool IsEmpty() const {
        return this->dataExport.IsEmpty();
    }

    FAWSS3CRTStorageClassAnalysis &fromAWS(const Aws::S3Crt::Model::StorageClassAnalysis &awsStorageClassAnalysis) {
        this->dataExport = FAWSS3CRTStorageClassAnalysisDataExport().fromAWS(awsStorageClassAnalysis.GetDataExport());

        return *this;
    }
#endif
};
