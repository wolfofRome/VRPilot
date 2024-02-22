/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/Delete.h"

#endif

#include "Model/AWSS3CRTObjectIdentifier.h"

#include "AWSS3CRTDelete.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTDelete {
GENERATED_BODY()

    /**
    *  <p>The objects to delete.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    TArray<FAWSS3CRTObjectIdentifier> objects;

    /**
    *  <p>Element to enable quiet mode for the request. When you add this element, you must set its value to true.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    bool quiet = false;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::Delete toAWS() const {
        Aws::S3Crt::Model::Delete awsDelete;

        for (const FAWSS3CRTObjectIdentifier& elem : this->objects) {
            awsDelete.AddObjects(elem.toAWS());
        }

        if (!(false)) {
            awsDelete.SetQuiet(this->quiet);
        }

        return awsDelete;
    }

    bool IsEmpty() const {
        return this->objects.Num() == 0 && false;
    }
#endif
};
