/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#include "Model/AWSS3CRTSelectObjectContentHandler.h"

void UAWSS3CRTSelectObjectContentHandler::RecordsEventCallback_Implementation(const FAWSS3CRTRecordsEvent &recordsEvent) {
}

void UAWSS3CRTSelectObjectContentHandler::StatsEventCallback_Implementation(const FAWSS3CRTStatsEvent &statsEvent) {
}

void UAWSS3CRTSelectObjectContentHandler::ProgressEventCallback_Implementation(const FAWSS3CRTProgressEvent &progressEvent) {
}

void UAWSS3CRTSelectObjectContentHandler::ContinuationEventCallback_Implementation() {
}

void UAWSS3CRTSelectObjectContentHandler::EndEventCallback_Implementation() {
}

void UAWSS3CRTSelectObjectContentHandler::ErrorCallback_Implementation(const ES3CRTError &recordsEvent) {
}

#if WITH_S3CRTCLIENTSDK && WITH_CORE
Aws::S3Crt::Model::SelectObjectContentHandler UAWSS3CRTSelectObjectContentHandler::toAWS() {
    Aws::S3Crt::Model::SelectObjectContentHandler awsSelectObjectContentHandler;

    awsSelectObjectContentHandler.SetRecordsEventCallback([this](
            Aws::S3Crt::Model::RecordsEvent awsRecordsEvent) -> void {
        RecordsEventCallback(FAWSS3CRTRecordsEvent().fromAWS(awsRecordsEvent));
    });

    awsSelectObjectContentHandler.SetStatsEventCallback([this](
            Aws::S3Crt::Model::StatsEvent awsStatsEvent) -> void {
        StatsEventCallback(FAWSS3CRTStatsEvent().fromAWS(awsStatsEvent));
    });

    awsSelectObjectContentHandler.SetProgressEventCallback([this](
            Aws::S3Crt::Model::ProgressEvent awsProgressEvent) -> void {
        ProgressEventCallback(FAWSS3CRTProgressEvent().fromAWS(awsProgressEvent));
    });

    awsSelectObjectContentHandler.SetContinuationEventCallback([this]() -> void {
        ContinuationEventCallback();
    });

    awsSelectObjectContentHandler.SetEndEventCallback([this]() -> void {
        EndEventCallback();
    });

    awsSelectObjectContentHandler.SetOnErrorCallback([this](
            const Aws::Client::AWSError<Aws::S3Crt::S3CrtErrors>& error) -> void {
        switch (error.GetErrorType()) {
            case Aws::S3Crt::S3CrtErrors::INCOMPLETE_SIGNATURE:
                ErrorCallback(ES3CRTError::INCOMPLETE_SIGNATURE);
                break;
            case Aws::S3Crt::S3CrtErrors::INTERNAL_FAILURE:
                ErrorCallback(ES3CRTError::INTERNAL_FAILURE);
                break;
            case Aws::S3Crt::S3CrtErrors::INVALID_ACTION:
                ErrorCallback(ES3CRTError::INVALID_ACTION);
                break;
            case Aws::S3Crt::S3CrtErrors::INVALID_CLIENT_TOKEN_ID:
                ErrorCallback(ES3CRTError::INVALID_CLIENT_TOKEN_ID);
                break;
            case Aws::S3Crt::S3CrtErrors::INVALID_PARAMETER_COMBINATION:
                ErrorCallback(ES3CRTError::INVALID_PARAMETER_COMBINATION);
                break;
            case Aws::S3Crt::S3CrtErrors::INVALID_QUERY_PARAMETER:
                ErrorCallback(ES3CRTError::INVALID_QUERY_PARAMETER);
                break;
            case Aws::S3Crt::S3CrtErrors::INVALID_PARAMETER_VALUE:
                ErrorCallback(ES3CRTError::INVALID_PARAMETER_VALUE);
                break;
            case Aws::S3Crt::S3CrtErrors::MISSING_ACTION:
                ErrorCallback(ES3CRTError::MISSING_ACTION);
                break;
            case Aws::S3Crt::S3CrtErrors::MISSING_AUTHENTICATION_TOKEN:
                ErrorCallback(ES3CRTError::MISSING_AUTHENTICATION_TOKEN);
                break;
            case Aws::S3Crt::S3CrtErrors::MISSING_PARAMETER:
                ErrorCallback(ES3CRTError::MISSING_PARAMETER);
                break;
            case Aws::S3Crt::S3CrtErrors::OPT_IN_REQUIRED:
                ErrorCallback(ES3CRTError::OPT_IN_REQUIRED);
                break;
            case Aws::S3Crt::S3CrtErrors::REQUEST_EXPIRED:
                ErrorCallback(ES3CRTError::REQUEST_EXPIRED);
                break;
            case Aws::S3Crt::S3CrtErrors::SERVICE_UNAVAILABLE:
                ErrorCallback(ES3CRTError::SERVICE_UNAVAILABLE);
                break;
            case Aws::S3Crt::S3CrtErrors::THROTTLING:
                ErrorCallback(ES3CRTError::THROTTLING);
                break;
            case Aws::S3Crt::S3CrtErrors::VALIDATION:
                ErrorCallback(ES3CRTError::VALIDATION);
                break;
            case Aws::S3Crt::S3CrtErrors::ACCESS_DENIED:
                ErrorCallback(ES3CRTError::ACCESS_DENIED);
                break;
            case Aws::S3Crt::S3CrtErrors::RESOURCE_NOT_FOUND:
                ErrorCallback(ES3CRTError::RESOURCE_NOT_FOUND);
                break;
            case Aws::S3Crt::S3CrtErrors::UNRECOGNIZED_CLIENT:
                ErrorCallback(ES3CRTError::UNRECOGNIZED_CLIENT);
                break;
            case Aws::S3Crt::S3CrtErrors::MALFORMED_QUERY_STRING:
                ErrorCallback(ES3CRTError::MALFORMED_QUERY_STRING);
                break;
            case Aws::S3Crt::S3CrtErrors::SLOW_DOWN:
                ErrorCallback(ES3CRTError::SLOW_DOWN);
                break;
            case Aws::S3Crt::S3CrtErrors::REQUEST_TIME_TOO_SKEWED:
                ErrorCallback(ES3CRTError::REQUEST_TIME_TOO_SKEWED);
                break;
            case Aws::S3Crt::S3CrtErrors::INVALID_SIGNATURE:
                ErrorCallback(ES3CRTError::INVALID_SIGNATURE);
                break;
            case Aws::S3Crt::S3CrtErrors::SIGNATURE_DOES_NOT_MATCH:
                ErrorCallback(ES3CRTError::SIGNATURE_DOES_NOT_MATCH);
                break;
            case Aws::S3Crt::S3CrtErrors::INVALID_ACCESS_KEY_ID:
                ErrorCallback(ES3CRTError::INVALID_ACCESS_KEY_ID);
                break;
            case Aws::S3Crt::S3CrtErrors::REQUEST_TIMEOUT:
                ErrorCallback(ES3CRTError::REQUEST_TIMEOUT);
                break;
            case Aws::S3Crt::S3CrtErrors::NETWORK_CONNECTION:
                ErrorCallback(ES3CRTError::NETWORK_CONNECTION);
                break;
            case Aws::S3Crt::S3CrtErrors::UNKNOWN:
                ErrorCallback(ES3CRTError::UNKNOWN);
                break;
            case Aws::S3Crt::S3CrtErrors::BUCKET_ALREADY_EXISTS:
                ErrorCallback(ES3CRTError::BUCKET_ALREADY_EXISTS);
                break;
            case Aws::S3Crt::S3CrtErrors::BUCKET_ALREADY_OWNED_BY_YOU:
                ErrorCallback(ES3CRTError::BUCKET_ALREADY_OWNED_BY_YOU);
                break;
            case Aws::S3Crt::S3CrtErrors::INVALID_OBJECT_STATE:
                ErrorCallback(ES3CRTError::INVALID_OBJECT_STATE);
                break;
            case Aws::S3Crt::S3CrtErrors::NO_SUCH_BUCKET:
                ErrorCallback(ES3CRTError::NO_SUCH_BUCKET);
                break;
            case Aws::S3Crt::S3CrtErrors::NO_SUCH_KEY:
                ErrorCallback(ES3CRTError::NO_SUCH_KEY);
                break;
            case Aws::S3Crt::S3CrtErrors::NO_SUCH_UPLOAD:
                ErrorCallback(ES3CRTError::NO_SUCH_UPLOAD);
                break;
            case Aws::S3Crt::S3CrtErrors::OBJECT_ALREADY_IN_ACTIVE_TIER:
                ErrorCallback(ES3CRTError::OBJECT_ALREADY_IN_ACTIVE_TIER);
                break;
            case Aws::S3Crt::S3CrtErrors::OBJECT_NOT_IN_ACTIVE_TIER:
                ErrorCallback(ES3CRTError::OBJECT_NOT_IN_ACTIVE_TIER);
                break;
            default:
                ErrorCallback(ES3CRTError::UNKNOWN);
                break;
        }
    });

    return awsSelectObjectContentHandler;
}
#endif