// Copyright Epic Games, Inc. All Rights Reserved.

#include "n00dEmotes.h"

#define LOCTEXT_NAMESPACE "Fn00dEmotesModule"

void Fn00dEmotesModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void Fn00dEmotesModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(Fn00dEmotesModule, n00dEmotes)