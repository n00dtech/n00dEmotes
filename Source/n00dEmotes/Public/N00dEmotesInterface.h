// Copyright (c) Developed by Josh (db) Debelec - Published by n00dbeaver Studios 2022 - All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"

#include "N00dEmotesInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UN00dEmotesInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class N00DEMOTES_API IN00dEmotesInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	// Emote
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00d|Emotes|Interface")
		void N00dEmote (FGameplayTag Tag);

	// The name of the animation that's currently playing
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00d|Emotes|Interface")
		void N00dDebugEmote(const FString &Emote);
	// The number of active sounds
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00d|Emotes|Interface")
		void N00dDebugEmoteActiveSounds(int32 NumCurrentlyActive);
	// The tag related to the current emote
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00d|Emotes|Interface")
		void N00dDebugEmoteTag(FGameplayTag Tag);
	// The slot thie emote is playing on
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00d|Emotes|Interface")
		void N00dDebugEmoteSlot(FName Slot);
	// Is the movement disabled
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "N00d|Emotes|Interface")
		void N00dDebugEmoteMovementDisabled(bool Disabled);

};
