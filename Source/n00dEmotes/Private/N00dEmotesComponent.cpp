// Copyright (c) Developed by Josh (db) Debelec - Published by n00dbeaver Studios 2022 - All Rights Reserved. 


#include "N00dEmotesComponent.h"

// Sets default values for this component's properties
UN00dEmotesComponent::UN00dEmotesComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicatedByDefault(true);
	// ...
}


// Called when the game starts
void UN00dEmotesComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
	
}


// Called every frame
void UN00dEmotesComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

///////////////////////////
// DEBUG
///////////////////////////

// is component disabled
bool UN00dEmotesComponent::IsEmoteComponentDisabled()
{
	return false;
}

bool UN00dEmotesComponent::ShowEmotesDebugWidget_Implementation()
{
	return false;
}

///////////////////////////
// EMOTE FUNCTIONS
///////////////////////////

// intialise emotes
bool UN00dEmotesComponent::InitialiseEmotes_Implementation(UDataTable* EmotesTable)
{
	return true;
}

// emote
bool UN00dEmotesComponent::Emote_Implementation(FGameplayTag Tag)
{
	return false;
}

// find emote
bool UN00dEmotesComponent::FindEmote_Implementation(FGameplayTag Tag)
{
	return false;
}

// load the animation from the selected emote
void UN00dEmotesComponent::LoadEmoteAnimation_Implementation(const TSoftObjectPtr<UObject> &SoftAnimation, FName OnSlot)
{
}

// play emote
bool UN00dEmotesComponent::PlayEmote_Implementation(FName OnSlot)
{
	return false;
}

// enable character movement
void UN00dEmotesComponent::EnableEmotesCharacterMovement_Implementation()
{
}

// interrupt emote
bool UN00dEmotesComponent::InterruptEmote_Implementation()
{
	return false;
}

// movement check
void UN00dEmotesComponent::MovementCheck_Implementation()
{
}

// build references
bool UN00dEmotesComponent::BuildReferences_Implementation()
{
	return false;
}

// load footsteps settings
void UN00dEmotesComponent::LoadEmotesSettings_Implementation()
{
}

///////////////////////////
// NETWORKING
///////////////////////////

// server emote
void UN00dEmotesComponent::ServerEmote_Implementation(FGameplayTag Tag)
{
	Emote(Tag);
}

// multicast play emote
void UN00dEmotesComponent::MulticastPlayEmote_Implementation(FName OnSlot)
{
	PlayEmote(OnSlot);
}

// get footsteps settings
void UN00dEmotesComponent::GetEmotesSettings(UN00dEmotesSettings*& EmotesSettings)
{
	UN00dEmotesSettings* Settings = GetMutableDefault<UN00dEmotesSettings>();
	EmotesSettings = Settings;
}


///////////////////// PROPERTIES /////////////////////


// Replicate properties
void UN00dEmotesComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UN00dEmotesComponent, SelectedEmote);
	DOREPLIFETIME(UN00dEmotesComponent, LoadedEmote);
	DOREPLIFETIME(UN00dEmotesComponent, EmoteMesh);
	DOREPLIFETIME(UN00dEmotesComponent, LoadedMontage);
	
}


