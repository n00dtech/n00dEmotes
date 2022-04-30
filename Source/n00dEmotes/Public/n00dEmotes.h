/* © Copyright 2020-2021 | n00dbeaver Studios | Developed by db AKA DebellicA */

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class Fn00dEmotesModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
