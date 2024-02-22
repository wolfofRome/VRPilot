/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, October 2022
 */
#include "RestfulModule.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FGraphQLModule"

void FRestfulModule::StartupModule()
{   
    if(!FModuleManager::Get().IsModuleLoaded("HTTP"))
    {
        FModuleManager::Get().LoadModule("HTTP");
    }

    if(!FModuleManager::Get().IsModuleLoaded("OpenSSL"))
    {
        FModuleManager::Get().LoadModule("OpenSSL");
    }
}

void FRestfulModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FRestfulModule, Restful)
