/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, January 2023
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE

#include "aws/s3control/model/MultiRegionAccessPointReport.h"

#endif

#include "Model/S3ControlPublicAccessBlockConfiguration.h"
#include "Model/AWSS3ControlMultiRegionAccessPointStatus.h"
#include "Model/AWSS3ControlRegionReport.h"

#include "AWSS3ControlMultiRegionAccessPointReport.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3ControlMultiRegionAccessPointReport {
GENERATED_BODY()

    /**
    *  <p>The name of the Multi-Region Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString name;

    /**
    *  <p>The alias for the Multi-Region Access Point. For more information about the distinction between the name and the alias of an Multi-Region Access Point, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/CreatingMultiRegionAccessPoints.html#multi-region-access-point-naming">Managing Multi-Region Access Points</a>.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FString alias;

    /**
    *  <p>When the Multi-Region Access Point create request was received.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FDateTime createdAt;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    FS3ControlPublicAccessBlockConfiguration publicAccessBlock;

    /**
    *  <p>The current status of the Multi-Region Access Point.</p> <p> <code>CREATING</code> and <code>DELETING</code> are temporary states that exist while the request is propagating and being completed. If a Multi-Region Access Point has a status of <code>PARTIALLY_CREATED</code>, you can retry creation or send a request to delete the Multi-Region Access Point. If a Multi-Region Access Point has a status of <code>PARTIALLY_DELETED</code>, you can retry a delete request to finish the deletion of the Multi-Region Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    EAWSS3ControlMultiRegionAccessPointStatus status = EAWSS3ControlMultiRegionAccessPointStatus::NOT_SET;

    /**
    *  <p>A collection of the Regions and buckets associated with the Multi-Region Access Point.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3Control Client")
    TArray<FAWSS3ControlRegionReport> regions;

#if WITH_S3CONTROLCLIENTSDK && WITH_CORE
public:
    FAWSS3ControlMultiRegionAccessPointReport &fromAWS(const Aws::S3Control::Model::MultiRegionAccessPointReport &awsMultiRegionAccessPointReport) {
        this->name = UTF8_TO_TCHAR(awsMultiRegionAccessPointReport.GetName().c_str());

        this->alias = UTF8_TO_TCHAR(awsMultiRegionAccessPointReport.GetAlias().c_str());

        this->createdAt = FDateTime(1970, 1, 1) + FTimespan(awsMultiRegionAccessPointReport.GetCreatedAt().Millis() * ETimespan::TicksPerMillisecond);

        this->publicAccessBlock.fromAWS(awsMultiRegionAccessPointReport.GetPublicAccessBlock());

        switch(awsMultiRegionAccessPointReport.GetStatus()) {
            case Aws::S3Control::Model::MultiRegionAccessPointStatus::NOT_SET:
                this->status = EAWSS3ControlMultiRegionAccessPointStatus::NOT_SET;
                break;
            case Aws::S3Control::Model::MultiRegionAccessPointStatus::READY:
                this->status = EAWSS3ControlMultiRegionAccessPointStatus::READY;
                break;
            case Aws::S3Control::Model::MultiRegionAccessPointStatus::INCONSISTENT_ACROSS_REGIONS:
                this->status = EAWSS3ControlMultiRegionAccessPointStatus::INCONSISTENT_ACROSS_REGIONS;
                break;
            case Aws::S3Control::Model::MultiRegionAccessPointStatus::CREATING:
                this->status = EAWSS3ControlMultiRegionAccessPointStatus::CREATING;
                break;
            case Aws::S3Control::Model::MultiRegionAccessPointStatus::PARTIALLY_CREATED:
                this->status = EAWSS3ControlMultiRegionAccessPointStatus::PARTIALLY_CREATED;
                break;
            case Aws::S3Control::Model::MultiRegionAccessPointStatus::PARTIALLY_DELETED:
                this->status = EAWSS3ControlMultiRegionAccessPointStatus::PARTIALLY_DELETED;
                break;
            case Aws::S3Control::Model::MultiRegionAccessPointStatus::DELETING:
                this->status = EAWSS3ControlMultiRegionAccessPointStatus::DELETING;
                break;
            default:
                this->status = EAWSS3ControlMultiRegionAccessPointStatus::NOT_SET;
                break;
        }

        this->regions.Empty();
        for (const Aws::S3Control::Model::RegionReport& elem : awsMultiRegionAccessPointReport.GetRegions()) {
            this->regions.Add(FAWSS3ControlRegionReport().fromAWS(elem));
        }

        return *this;
    }
#endif
};
