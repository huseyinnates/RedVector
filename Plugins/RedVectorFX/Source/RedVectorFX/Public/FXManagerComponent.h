#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FXTypes.h"
#include "FXManagerComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class REDVECTORFX_API UFXManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFXManagerComponent();

	/** Play FX based on enum, with optional location offset and rotation */
	UFUNCTION(BlueprintCallable, Category = "FX")
	void PlayFX(FFXTypes Type, FVector Offset = FVector::ZeroVector, FRotator Rotation = FRotator::ZeroRotator);
};
