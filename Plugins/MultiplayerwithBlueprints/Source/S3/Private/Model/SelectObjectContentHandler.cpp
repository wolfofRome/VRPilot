/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#include "Model/SelectObjectContentHandler.h"

void USelectObjectContentHandler::RecordsEventCallback_Implementation(const FRecordsEvent &recordsEvent) {
}

void USelectObjectContentHandler::StatsEventCallback_Implementation(const FStatsEvent &statsEvent) {
}

void USelectObjectContentHandler::ProgressEventCallback_Implementation(const FProgressEvent &progressEvent) {
}

void USelectObjectContentHandler::ContinuationEventCallback_Implementation() {
}

void USelectObjectContentHandler::EndEventCallback_Implementation() {
}

void USelectObjectContentHandler::ErrorCallback_Implementation(const ES3Error &recordsEvent) {
}

#if WITH_S3CLIENTSDK && WITH_CORE
Aws::S3::Model::SelectObjectContentHandler USelectObjectContentHandler::toAWS() {
    Aws::S3::Model::SelectObjectContentHandler awsSelectObjectContentHandler;

    awsSelectObjectContentHandler.SetRecordsEventCallback([this](
            Aws::S3::Model::RecordsEvent awsRecordsEvent) -> void {
        RecordsEventCallback(FRecordsEvent().fromAWS(awsRecordsEvent));
    });

    awsSelectObjectContentHandler.SetStatsEventCallback([this](
            Aws::S3::Model::StatsEvent awsStatsEvent) -> void {
        StatsEventCallback(FStatsEvent().fromAWS(awsStatsEvent));
    });

    awsSelectObjectContentHandler.SetProgressEventCallback([this](
            Aws::S3::Model::ProgressEvent awsProgressEvent) -> void {
        ProgressEventCallback(FProgressEvent().fromAWS(awsProgressEvent));
    });

    awsSelectObjectContentHandler.SetContinuationEventCallback([this]() -> void {
        ContinuationEventCallback();
    });

    awsSelectObjectContentHandler.SetEndEventCallback([this]() -> void {
        EndEventCallback();
    });

    awsSelectObjectContentHandler.SetOnErrorCallback([this](
            const Aws::Client::AWSError<Aws::S3::S3Errors>& error) -> void {
        switch (error.GetErrorType()) {
            case Aws::S3::S3Errors::INCOMPLETE_SIGNATURE:
                ErrorCallback(ES3Error::INCOMPLETE_SIGNATURE);
                break;
            case Aws::S3::S3Errors::INTERNAL_FAILURE:
                ErrorCallback(ES3Error::INTERNAL_FAILURE);
                break;
            case Aws::S3::S3Errors::INVALID_ACTION:
                ErrorCallback(ES3Error::INVALID_ACTION);
                break;
            case Aws::S3::S3Errors::INVALID_CLIENT_TOKEN_ID:
                ErrorCallback(ES3Error::INVALID_CLIENT_TOKEN_ID);
                break;
            case Aws::S3::S3Errors::INVALID_PARAMETER_COMBINATION:
                ErrorCallback(ES3Error::INVALID_PARAMETER_COMBINATION);
                break;
            case Aws::S3::S3Errors::INVALID_QUERY_PARAMETER:
                ErrorCallback(ES3Error::INVALID_QUERY_PARAMETER);
                break;
            case Aws::S3::S3Errors::INVALID_PARAMETER_VALUE:
                ErrorCallback(ES3Error::INVALID_PARAMETER_VALUE);
                break;
            case Aws::S3::S3Errors::MISSING_ACTION:
                ErrorCallback(ES3Error::MISSING_ACTION);
                break;
            case Aws::S3::S3Errors::MISSING_AUTHENTICATION_TOKEN:
                ErrorCallback(ES3Error::MISSING_AUTHENTICATION_TOKEN);
                break;
            case Aws::S3::S3Errors::MISSING_PARAMETER:
                ErrorCallback(ES3Error::MISSING_PARAMETER);
                break;
            case Aws::S3::S3Errors::OPT_IN_REQUIRED:
                ErrorCallback(ES3Error::OPT_IN_REQUIRED);
                break;
            case Aws::S3::S3Errors::REQUEST_EXPIRED:
                ErrorCallback(ES3Error::REQUEST_EXPIRED);
                break;
            case Aws::S3::S3Errors::SERVICE_UNAVAILABLE:
                ErrorCallback(ES3Error::SERVICE_UNAVAILABLE);
                break;
            case Aws::S3::S3Errors::THROTTLING:
                ErrorCallback(ES3Error::THROTTLING);
                break;
            case Aws::S3::S3Errors::VALIDATION:
                ErrorCallback(ES3Error::VALIDATION);
                break;
            case Aws::S3::S3Errors::ACCESS_DENIED:
                ErrorCallback(ES3Error::ACCESS_DENIED);
                break;
            case Aws::S3::S3Errors::RESOURCE_NOT_FOUND:
                ErrorCallback(ES3Error::RESOURCE_NOT_FOUND);
                break;
            case Aws::S3::S3Errors::UNRECOGNIZED_CLIENT:
                ErrorCallback(ES3Error::UNRECOGNIZED_CLIENT);
                break;
            case Aws::S3::S3Errors::MALFORMED_QUERY_STRING:
                ErrorCallback(ES3Error::MALFORMED_QUERY_STRING);
                break;
            case Aws::S3::S3Errors::SLOW_DOWN:
                ErrorCallback(ES3Error::SLOW_DOWN);
                break;
            case Aws::S3::S3Errors::REQUEST_TIME_TOO_SKEWED:
                ErrorCallback(ES3Error::REQUEST_TIME_TOO_SKEWED);
                break;
            case Aws::S3::S3Errors::INVALID_SIGNATURE:
                ErrorCallback(ES3Error::INVALID_SIGNATURE);
                break;
            case Aws::S3::S3Errors::SIGNATURE_DOES_NOT_MATCH:
                ErrorCallback(ES3Error::SIGNATURE_DOES_NOT_MATCH);
                break;
            case Aws::S3::S3Errors::INVALID_ACCESS_KEY_ID:
                ErrorCallback(ES3Error::INVALID_ACCESS_KEY_ID);
                break;
            case Aws::S3::S3Errors::REQUEST_TIMEOUT:
                ErrorCallback(ES3Error::REQUEST_TIMEOUT);
                break;
            case Aws::S3::S3Errors::NETWORK_CONNECTION:
                ErrorCallback(ES3Error::NETWORK_CONNECTION);
                break;
            case Aws::S3::S3Errors::UNKNOWN:
                ErrorCallback(ES3Error::UNKNOWN);
                break;
            case Aws::S3::S3Errors::BUCKET_ALREADY_EXISTS:
                ErrorCallback(ES3Error::BUCKET_ALREADY_EXISTS);
                break;
            case Aws::S3::S3Errors::BUCKET_ALREADY_OWNED_BY_YOU:
                ErrorCallback(ES3Error::BUCKET_ALREADY_OWNED_BY_YOU);
                break;
            case Aws::S3::S3Errors::NO_SUCH_BUCKET:
                ErrorCallback(ES3Error::NO_SUCH_BUCKET);
                break;
            case Aws::S3::S3Errors::NO_SUCH_KEY:
                ErrorCallback(ES3Error::NO_SUCH_KEY);
                break;
            case Aws::S3::S3Errors::NO_SUCH_UPLOAD:
                ErrorCallback(ES3Error::NO_SUCH_UPLOAD);
                break;
            case Aws::S3::S3Errors::OBJECT_ALREADY_IN_ACTIVE_TIER:
                ErrorCallback(ES3Error::OBJECT_ALREADY_IN_ACTIVE_TIER);
                break;
            case Aws::S3::S3Errors::OBJECT_NOT_IN_ACTIVE_TIER:
                ErrorCallback(ES3Error::OBJECT_NOT_IN_ACTIVE_TIER);
                break;
            default:
                ErrorCallback(ES3Error::UNKNOWN);
                break;
        }
    });

    return awsSelectObjectContentHandler;
}
#endif