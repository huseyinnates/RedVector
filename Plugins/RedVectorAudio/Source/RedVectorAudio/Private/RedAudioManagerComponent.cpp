#include "RedAudioManagerComponent.h"
#include "AudioLibrary.h"
#include "Kismet/GameplayStatics.h"

URedAudioManagerComponent::URedAudioManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void URedAudioManagerComponent::PlaySound(ESoundEvent Type, FVector Offset)
{
	if (USoundBase* Sound = UAudioLibrary::GetSound(Type))
	{
		FVector Location = GetOwner()->GetActorLocation() + Offset;
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), Sound, Location);
	}
}
