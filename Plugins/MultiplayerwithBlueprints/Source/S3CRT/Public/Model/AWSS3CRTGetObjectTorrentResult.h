/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, May 2021
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CRTCLIENTSDK && WITH_CORE

#include "aws/core/utils/FileSystemUtils.h"
#include "aws/s3-crt/model/GetObjectTorrentResult.h"

#endif

#include "Model/AWSS3CRTRequestCharged.h"

#include "AWSS3CRTGetObjectTorrentResult.generated.h"

USTRUCT(BlueprintType)
struct FAWSS3CRTGetObjectTorrentResult {
GENERATED_BODY()

    /**
    *  <p>A Bencoded dictionary as defined by the BitTorrent specification</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    FString body;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3CRT Client")
    EAWSS3CRTRequestCharged requestCharged = EAWSS3CRTRequestCharged::NOT_SET;

#if WITH_S3CRTCLIENTSDK && WITH_CORE
public:
    FAWSS3CRTGetObjectTorrentResult &fromAWS(const Aws::S3Crt::Model::GetObjectTorrentResult &awsGetObjectTorrentResult) {
        Aws::Utils::FStreamWithFileName awsTempFile("" + Aws::FileSystem::CreateTempFilePath() + ".torrent", std::ios_base::binary | std::ios_base::out);

        Aws::IOStream& awsStream = awsGetObjectTorrentResult.GetBody();
        unsigned int Size = 0;
        TArray<uint8> rawData;
        awsStream.seekg(0, std::ios::end);
        Size = awsStream.tellg();
        awsStream.seekg(0);
        rawData.SetNum(Size);
        awsStream.read((char*)rawData.GetData(), Size);

        awsTempFile.write((char*)rawData.GetData(), Size);
        awsTempFile.close();
        this->body = UTF8_TO_TCHAR(awsTempFile.GetFileName().c_str());

        switch(awsGetObjectTorrentResult.GetRequestCharged()) {
            case Aws::S3Crt::Model::RequestCharged::NOT_SET:
                this->requestCharged = EAWSS3CRTRequestCharged::NOT_SET;
                break;
            case Aws::S3Crt::Model::RequestCharged::requester:
                this->requestCharged = EAWSS3CRTRequestCharged::requester;
                break;
            default:
                this->requestCharged = EAWSS3CRTRequestCharged::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
