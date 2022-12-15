// Copyright (c) Developed by Josh (db) Debelec - Published by n00dbeaver Studios 2022 - All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "FN00dEmotesData.h"
#include "Net/UnrealNetwork.h"
#include "GameFramework/Character.h"
#include "Animation/AnimSequence.h"

#include "N00dEmotesComponent.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class N00DEMOTES_API UN00dEmotesComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UN00dEmotesComponent();

protected:

/////////////////////////////////////////////// PROPERTIES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

///////////////////////////////
//	HIDDEN FROM DESIGNER
///////////////////////////////

	// These values can only be written to or read from

	// The emote cache built from our emote data table
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Emotes")
		TArray<FN00dEmotesData> Emotes;
	// The currently selected emote
	UPROPERTY(Replicated, BlueprintReadWrite, Category = "N00d|Emotes")
		FN00dEmotesData SelectedEmote;
	// The mesh of the owning actor
	UPROPERTY(Replicated, BlueprintReadWrite, Category = "N00d|Emotes")
		USkeletalMeshComponent* EmoteMesh;
	// The character whom owns the Emote component
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Emotes")
		ACharacter* EmoteCharacter;
	// The loaded animation that we wish to play
	UPROPERTY(Replicated, BlueprintReadWrite, Category = "N00d|Emotes")
		UAnimSequence* LoadedEmote;
	// The loaded montage that we wish to play
	UPROPERTY(Replicated, BlueprintReadWrite, Category = "N00d|Emotes")
		UAnimMontage* LoadedMontage;
	// The current movement mode of the owning character
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Emotes")
		TEnumAsByte<EMovementMode> EmotesCurrentMovementMode;
	// Is the movement currently disabled
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Emotes")
		bool IsEmoteMovementDisabled;
	// A timer to indicate when to re-enable movement
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Emotes")
		FTimerHandle EmotesDisableMovementTimer;
	UPROPERTY(BlueprintReadWrite, Category = "N00d|Emotes")
		class UUserWidget* DebugWidget;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


protected:

/////////////////////////////////////////////// FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

///////////////////////////
// DEBUG
///////////////////////////

	// Check to see if the component is disabled
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "N00d|Emotes|Debug")
		bool IsEmoteComponentDisabled();
	// Show the debug widget if we're debugging
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Emotes|Debug")
		bool ShowEmotesDebugWidget();
	
///////////////////////////
// EMOTE FUNCTIONS
///////////////////////////
		
	// Setup the emotes component with our owner values
	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, BlueprintCallable, Category = "N00d|Emotes|System")
		bool InitialiseEmotes(UDataTable* EmotesTable);
	// Perform the emote. This is the primary function to call when initiating the emote
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Emotes|System")
		bool Emote(FGameplayTag Tag);
	// Find the emote in the cache
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Emotes|System")
		bool FindEmote(FGameplayTag Tag);
	// Load the animation from the selected emote
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Emotes|System")
		void LoadEmoteAnimation(const TSoftObjectPtr<UObject> &SoftAnimation, FName OnSlot);
	// Play the loaded animation
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Emotes|System")
		bool PlayEmote(FName OnSlot);
	// Re-enable movement if we are disabled
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Emotes|System")
		void EnableEmotesCharacterMovement();
	// If the Emote was a looping animation, this interrupts its execution. You would call 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Emotes|System")
		bool InterruptEmote();
	// A looping timer event that exists only if the emote is looping that checks if the player has moved, so that we may interrupt the animation. 
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Emotes|System")
		void MovementCheck();
	// Build references to the owner objects we care about
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Emotes|System")
		bool BuildReferences();
	// Load the plugin's settings
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00d|Footsteps|System")
		void LoadEmotesSettings();

	
///////////////////////////
// NETWORKING
///////////////////////////

	// Route the emote action via the server
	UFUNCTION(Server, Unreliable, BlueprintCallable, Category = "N00d|Emotes|Networked")
		void ServerEmote(FGameplayTag Tag);
	// Route the emote action via the server
	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "N00d|Emotes|Networked")
		void MulticastPlayEmote(FName OnSlot);

///////////////////////////
// SETTINGS
///////////////////////////

	// Get the emotes settings
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "N00d|Emotes|System")
		void GetEmotesSettings(UN00dEmotesSettings*& EmotesSettings);

};
