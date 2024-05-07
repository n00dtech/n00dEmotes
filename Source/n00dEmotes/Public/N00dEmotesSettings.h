// Copyright (c) Developed by Josh (db) Debelec - Published by n00dbeaver Studios 2020-2024 - All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "N00dEmotesSettings.generated.h"

UCLASS(config = Game, defaultconfig, meta = (DisplayName = "N00d Doors Settings"))
class N00DEMOTES_API UN00dEmotesSettings : public UObject
{

	GENERATED_BODY()

public:

		UN00dEmotesSettings(const FObjectInitializer& ObjectInitializer);


	// Function to get the settings instance in Blueprints
	UFUNCTION(BlueprintPure, Category = "N00d|Settings")
		static UN00dEmotesSettings* GetEmotesSettings();


	///////////////////////////////
	//	DEBUG
	///////////////////////////////

	// Enabling this will print and activate any various debugging info relevant to our plugin
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Debug)
		bool DebugEmotes;
	// Don't use any instances of the components in this plugin for any reason in particular 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, config, Category = Debug)
		bool DisableEmotes;



};
