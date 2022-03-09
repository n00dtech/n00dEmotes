/* © Copyright 2020-2021 | n00dbeaver Studios | Developed by db AKA DebellicA */


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
// UNIVERSAL FUNCTIONS
///////////////////////////

// is component disabled
bool UN00dEmotesComponent::IsEmoteComponentDisabled()
{
	return DisableEmoteComponent;

}





///////////////////////////
// EMOTE FUNCTIONS
///////////////////////////

// intialise emotes
bool UN00dEmotesComponent::InitialiseEmotes_Implementation(USkeletalMeshComponent * OwningMesh)
{
	EmoteMesh = OwningMesh;
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


///////////////////// PROPERTIES /////////////////////


// Replicate properties
void UN00dEmotesComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UN00dEmotesComponent, SelectedEmote);
	DOREPLIFETIME(UN00dEmotesComponent, LoadedEmote);
	DOREPLIFETIME(UN00dEmotesComponent, EmoteMesh);
}

