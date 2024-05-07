// Copyright Epic Games, Inc. All Rights Reserved.

#include "n00dEmotes.h"

#define LOCTEXT_NAMESPACE "Fn00dEmotesModule"

// Startup
void Fn00dEmotesModule::StartupModule()
{
	RegisterSettings();
}

// Shutdown
void Fn00dEmotesModule::ShutdownModule()
{
	if (UObjectInitialized())
	{
		UnregisterSettings();
	}
}

/////////////////////////////////
// Overrides for ISettingsModule
/////////////////////////////////

// Support for dynamic reloading
bool Fn00dEmotesModule::SupportsDynamicReloading()
{
	return true;
}

// Callback for when the settings were saved.
bool Fn00dEmotesModule::HandleSettingsSaved()
{
	// Validation code to resave the settings in case an invalid value has been entered
	UN00dEmotesSettings* Settings = GetMutableDefault<UN00dEmotesSettings>();
	bool ResaveSettings = false;

	if (ResaveSettings)
	{
		Settings->SaveConfig();
	}

	return true;
}

// Register settings
void Fn00dEmotesModule::RegisterSettings()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{

	// Registering some settings is just a matter of exposing the default UObject of
	// your desired class, these are the global settings we want to expose to LDs or artists.

		// Create the new category
		ISettingsContainerPtr SettingsContainer = SettingsModule->GetContainer("Project");

		SettingsContainer->DescribeCategory("n00d",
			LOCTEXT("RuntimeWDCategoryName", "n00d"),
			LOCTEXT("RuntimeWDCategoryDescription", "Global configuration for n00d assets"));

		// Register the settings
		ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "n00d", "Emotes",
			LOCTEXT("RuntimeGeneralSettingsName", "Emotes"),
			LOCTEXT("RuntimeGeneralSettingsDescription", "n00dEmotes Global Config"),
			GetMutableDefault<UN00dEmotesSettings>()
		);

		// Register the save handler to our settings, we might want to use it to
		// validate those or just act to settings changes.
		if (SettingsSection.IsValid())
		{
			SettingsSection->OnModified().BindRaw(this, &Fn00dEmotesModule::HandleSettingsSaved);
		}
	}
}

// Unregister settings
void Fn00dEmotesModule::UnregisterSettings()
{
	// Ensure to unregister all of our registered settings here, hot-reload would
	// otherwise yield unexpected results.
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "n00d", "Emotes");
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(Fn00dEmotesModule, n00dEmotes)