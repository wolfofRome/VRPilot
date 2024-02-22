/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/s3-crt/model/ObjectIdentifier.h"

#endif

#include "AWSS3CRTObjectIdentifier.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTObjectIdentifier {
GENERATED_BODY()

    /**
    *  <p>Key name of the object.</p>  <p>Replacement must be made for object keys containing special characters (such as carriage returns) when using XML requests. For more information, see <a href="https://docs.aws.amazon.com/AmazonS3/latest/userguide/object-keys.html#object-key-xml-related-constraints"> XML related object key constraints</a>.</p> 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString key;

    /**
    *  <p>VersionId for the specific version of the object to delete.</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString versionId;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    Aws::S3Crt::Model::ObjectIdentifier toAWS() const {
        Aws::S3Crt::Model::ObjectIdentifier awsObjectIdentifier;

        if (!(this->key.IsEmpty())) {
            awsObjectIdentifier.SetKey(TCHAR_TO_UTF8(*this->key));
        }

        if (!(this->versionId.IsEmpty())) {
            awsObjectIdentifier.SetVersionId(TCHAR_TO_UTF8(*this->versionId));
        }

        return awsObjectIdentifier;
    }

    bool IsEmpty() const {
        return this->key.IsEmpty() && this->versionId.IsEmpty();
    }
#endif
};
