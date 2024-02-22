/* Copyright (C) Siqi.Wu - All Rights Reserved
* Written by Siqi.Wu<lion547016@gmail.com>, September 2020
*/

#pragma once

#include "CoreMinimal.h"

#if WITH_S3CLIENTSDK && WITH_CORE

#include "aws/core/utils/FileSystemUtils.h"
#include "aws/s3/model/GetObjectTorrentResult.h"

#endif

#include "Model/RequestCharged.h"

#include "GetObjectTorrentResult.generated.h"

USTRUCT(BlueprintType)
struct FGetObjectTorrentResult {
GENERATED_BODY()

    /**
    *  <p>A Bencoded dictionary as defined by the BitTorrent specification</p>
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    FString body;

    /**
    * 
    **/
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "S3 Client")
    EAWSRequestCharged requestCharged = EAWSRequestCharged::NOT_SET;

#if WITH_S3CLIENTSDK && WITH_CORE
public:
    FGetObjectTorrentResult &fromAWS(const Aws::S3::Model::GetObjectTorrentResult &awsGetObjectTorrentResult) {
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
            case Aws::S3::Model::RequestCharged::NOT_SET:
                this->requestCharged = EAWSRequestCharged::NOT_SET;
                break;
            case Aws::S3::Model::RequestCharged::requester:
                this->requestCharged = EAWSRequestCharged::requester;
                break;
            default:
                this->requestCharged = EAWSRequestCharged::NOT_SET;
                break;
        }

        return *this;
    }
#endif
};
