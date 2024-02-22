/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/StorageClassAnalysisDataExport.h"

#endif

#include "Model/StorageClassAnalysisSchemaVersion.h"
#include "Model/AnalyticsExportDestination.h"

#include "StorageClassAnalysisDataExport.generated.h"

USTRUCT(BlueprintType)
struct FStorageClassAnalysisDataExport {
GENERATED_BODY()

    /**
    *  <p>The version of the output schema to use when exporting data. Must be <code>V_1</code>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSS3StorageClassAnalysisSchemaVersion outputSchemaVersion = EAWSS3StorageClassAnalysisSchemaVersion::NOT_SET;

    /**
    *  <p>The place to store the data for an analysis.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FAnalyticsExportDestination destination;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::StorageClassAnalysisDataExport toAWS() const {
        Aws::S3::Model::StorageClassAnalysisDataExport awsStorageClassAnalysisDataExport;

        switch(this->outputSchemaVersion) {
            case EAWSS3StorageClassAnalysisSchemaVersion::V_1:
                awsStorageClassAnalysisDataExport.SetOutputSchemaVersion(Aws::S3::Model::StorageClassAnalysisSchemaVersion::V_1);
                break;
            default:
                break;
        }

        if (!(this->destination.IsEmpty())) {
            awsStorageClassAnalysisDataExport.SetDestination(this->destination.toAWS());
        }

        return awsStorageClassAnalysisDataExport;
    }

    bool IsEmpty() const {
        return outputSchemaVersion == EAWSS3StorageClassAnalysisSchemaVersion::NOT_SET && this->destination.IsEmpty();
    }

    FStorageClassAnalysisDataExport &fromAWS(const Aws::S3::Model::StorageClassAnalysisDataExport &awsStorageClassAnalysisDataExport) {
        switch(awsStorageClassAnalysisDataExport.GetOutputSchemaVersion()) {
            case Aws::S3::Model::StorageClassAnalysisSchemaVersion::NOT_SET:
                this->outputSchemaVersion = EAWSS3StorageClassAnalysisSchemaVersion::NOT_SET;
                break;
            case Aws::S3::Model::StorageClassAnalysisSchemaVersion::V_1:
                this->outputSchemaVersion = EAWSS3StorageClassAnalysisSchemaVersion::V_1;
                break;
            default:
                this->outputSchemaVersion = EAWSS3StorageClassAnalysisSchemaVersion::NOT_SET;
                break;
        }

        this->destination.fromAWS(awsStorageClassAnalysisDataExport.GetDestination());

        return *this;
    }
#endif
};
