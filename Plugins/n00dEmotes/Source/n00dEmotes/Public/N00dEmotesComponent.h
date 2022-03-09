/* © Copyright 2020-2021 | n00dbeaver Studios | Developed by db AKA DebellicA */

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

///////////////////////////
// UNIVERSAL PROPERTIES
///////////////////////////


	// Should we enable debugging
	UPROPERTY(EditAnywhere, Category = "N00dComponents|Master|Debug")
		bool DebugEmoteComponent;
	// Should we disable this component
	UPROPERTY(EditAnywhere, Category = "N00dComponents|Master|Debug")
		bool DisableEmoteComponent;
	
///////////////////////////
// EMOTE PROPERTIES
///////////////////////////

	// The emote cache built from our emote data table
	UPROPERTY(BlueprintReadWrite, Category = "N00dComponents|Emotes|System")
		TArray<FN00dEmotesData> Emotes;
	// The currently selected emote
	UPROPERTY(Replicated, BlueprintReadWrite, Category = "N00dComponents|Emotes|System")
		FN00dEmotesData SelectedEmote;
	// The mesh of the owning actor
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "N00dComponents|Emotes|System")
		USkeletalMeshComponent* EmoteMesh;
	// The character whom owns the Emote component
	UPROPERTY(BlueprintReadWrite, Category = "N00dComponents|Emotes|System")
		ACharacter* EmoteCharacter;
	// The Data Table that specifies what Emotes that exist
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "N00dComponents|Emotes|System")
		UDataTable* EmoteTable;
	// The loaded animation that wish wish to play
	UPROPERTY(Replicated, BlueprintReadWrite, Category = "N00dComponents|Emotes|System")
		UAnimSequence* LoadedEmote;
	// The current movement mode of the owning character
	UPROPERTY(BlueprintReadWrite, Category = "N00dComponents|Emotes|System")
		TEnumAsByte<EMovementMode> EmotesCurrentMovementMode;
	// Is the movement currently disabled
	UPROPERTY(BlueprintReadWrite, Category = "N00dComponents|Emotes|System")
		bool IsEmoteMovementDisabled;
	// A timer to indicate when to re-enable movement
	UPROPERTY(BlueprintReadWrite, Category = "N00dComponents|Emotes|System")
		FTimerHandle EmotesDisableMovementTimer;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


///////////////////////////
// UNIVERSAL FUNCTIONS
///////////////////////////

	// Check to see if the component is disabled
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "N00dComponents|Master|Callable")
		bool IsEmoteComponentDisabled();
	
///////////////////////////
// EMOTE FUNCTIONS
///////////////////////////
		
	// Setup the emotes component with our owner values
	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, BlueprintCallable, Category = "N00dComponents|Emotes|Callable")
		bool InitialiseEmotes(USkeletalMeshComponent* OwningMesh);
	// Perform the emote. This is the primary function to call when initiating the emote
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Emotes|Callable")
		bool Emote(FGameplayTag Tag);
	// Find the emote in the cache
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Emotes|Callable")
		bool FindEmote(FGameplayTag Tag);
	// Load the animation from the selected emote
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Emotes|Callable")
		void LoadEmoteAnimation(const TSoftObjectPtr<UObject> &SoftAnimation, FName OnSlot);
	// Play the loaded animation
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Emotes|Callable")
		bool PlayEmote(FName OnSlot);
	// Re-enable movement if we are disabled
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "N00dComponents|Emotes|Callable")
		void EnableEmotesCharacterMovement();
	// Route the emote action via the server
	UFUNCTION(Server, Unreliable, BlueprintCallable, Category = "N00dComponents|Emotes|Callable")
		void ServerEmote(FGameplayTag Tag);
	// Route the emote action via the server
	UFUNCTION(NetMulticast, Unreliable, BlueprintCallable, Category = "N00dComponents|Emotes|Callable")
		void MulticastPlayEmote(FName OnSlot);

};
