// Copyright (c) Developed by Josh (db) Debelec - Published by n00dbeaver Studios 2022 - All Rights Reserved. 

#include "n00dEmotes.h"

#define LOCTEXT_NAMESPACE "Fn00dEmotesModule"

void Fn00dEmotesModule::StartupModule()
{
	RegisterSettings();
}

void Fn00dEmotesModule::ShutdownModule()
{
	if (UObjectInitialized())
	{
		UnregisterSettings();
	}
}

// Overridden for settings

// Support for dynamic reloading
bool Fn00dEmotesModule::SupportsDynamicReloading()
{
	return true;
}

// Callback for when the settings were saved.
bool Fn00dEmotesModule::HandleSettingsSaved()
{

	UN00dEmotesSettings* Settings = GetMutableDefault<UN00dEmotesSettings>();
	bool ResaveSettings = false;

	// You can put any validation code in here and resave the settings in case an invalid
	// value has been entered

	if (ResaveSettings)
	{
		Settings->SaveConfig();
	}

	return true;
}

// Register the settings
void Fn00dEmotesModule::RegisterSettings()
{
	// Registering some settings is just a matter of exposing the default UObject of
	// your desired class, feel free to add here all those settings you want to expose
	// to your LDs or artists.

	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		// Create the new category
		ISettingsContainerPtr SettingsContainer = SettingsModule->GetContainer("Project");

		SettingsContainer->DescribeCategory("n00d",
			LOCTEXT("RuntimeWDCategoryName", "n00d"),
			LOCTEXT("RuntimeWDCategoryDescription", "Configuration for n00d assets"));

		// Register the settings
		ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "n00d", "Emotes",
			LOCTEXT("RuntimeGeneralSettingsName", "Emotes"),
			LOCTEXT("RuntimeGeneralSettingsDescription", "n00dEmotes Config"),
			GetMutableDefault<UN00dEmotesSettings>()
		);

		// Register the save handler to your settings, you might want to use it to
		// validate those or just act to settings changes.
		if (SettingsSection.IsValid())
		{
			SettingsSection->OnModified().BindRaw(this, &Fn00dEmotesModule::HandleSettingsSaved);
		}
	}

}

// Unregister the settings
void Fn00dEmotesModule::UnregisterSettings()
{
	// Ensure to unregister all of your registered settings here, hot-reload would
	// otherwise yield unexpected results.

	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "n00d", "Emotes");
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(Fn00dEmotesModule, n00dEmotes)