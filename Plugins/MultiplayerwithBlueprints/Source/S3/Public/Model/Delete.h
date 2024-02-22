/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/s3/model/Delete.h"

#endif

#include "Model/ObjectIdentifier.h"

#include "Delete.generated.h"

USTRUCT(BlueprintType)
struct FS3Delete {
GENERATED_BODY()

    /**
    *  <p>The objects to delete.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    TArray<FObjectIdentifier> objects;

    /**
    *  <p>Element to enable quiet mode for the request. When you add this element, you must set its value to true.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    bool quiet = false;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    Aws::S3::Model::Delete toAWS() const {
        Aws::S3::Model::Delete awsDelete;

        for (const FObjectIdentifier& elem : this->objects) {
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
