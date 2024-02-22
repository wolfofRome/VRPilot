/* Copyright (C) Siqi.Wu - All Rights Reserved

 * Written by Siqi.Wu <lion547016@gmail.com>, December 2018
 */

#pragma once

#include "Modules/ModuleManager.h"

class FS3EncryptionModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:

#ifndef WITH_KMSCLIENTSDK
    static void* KMSLibraryHandle;
#endif
#if WITH_EDITOR
	static void* S3EncryptionLibraryHandle;
	static bool LoadDependency(const FString& Dir, const FString& Name, void*& Handle);
	static void FreeDependency(void*& Handle);
#endif
};