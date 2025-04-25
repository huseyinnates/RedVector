#include "FXManagerComponent.h"
#include "FXLibrary.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"

UFXManagerComponent::UFXManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false; // No need for tick unless you're updating something every frame
}

void UFXManagerComponent::PlayFX(FFXTypes Type, FVector Offset, FRotator Rotation)
{
	if (UNiagaraSystem* FX = UFXLibrary::GetFX(Type))
	{
		FVector Location = GetOwner()->GetActorLocation() + Offset;
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), FX, Location, Rotation);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("FXManagerComponent: Niagara System not found for FXType: %d"), static_cast<uint8>(Type));
	}
}
