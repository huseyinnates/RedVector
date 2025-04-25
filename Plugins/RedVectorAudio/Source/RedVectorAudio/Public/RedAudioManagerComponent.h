#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SoundTypes.h"
#include "RedAudioManagerComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class REDVECTORAUDIO_API URedAudioManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	URedAudioManagerComponent();

	UFUNCTION(BlueprintCallable, Category="Audio")
	void PlaySound(ESoundEvent Type, FVector Offset = FVector::ZeroVector);
};
