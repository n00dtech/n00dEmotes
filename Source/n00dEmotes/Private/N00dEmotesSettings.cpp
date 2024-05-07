// Copyright (c) Developed by Josh (db) Debelec - Published by n00dbeaver Studios 2020-2024 - All Rights Reserved. 

#include "N00dEmotesSettings.h"

UN00dEmotesSettings::UN00dEmotesSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// initialise defaults
	DebugEmotes = false;
	DisableEmotes = false;
}

UN00dEmotesSettings* UN00dEmotesSettings::GetEmotesSettings()
{
	// Return the singleton instance of the settings class
	return GetMutableDefault<UN00dEmotesSettings>();
}
