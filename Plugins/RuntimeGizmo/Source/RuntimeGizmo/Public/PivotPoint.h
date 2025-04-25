#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PivotPoint.generated.h"

UCLASS()
class RUNTIMEGIZMO_API UPivotPoint : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Applies a simulated pivot rotation to a StaticMeshComponent by attaching it to a new rotated SceneComponent.
	 * This does not affect the mesh asset or change its origin.
	 */
	UFUNCTION(BlueprintCallable, Category = "Pivot")
	static void ApplyPivotRotation(UStaticMeshComponent* MeshComp, const FRotator& PivotRotation);
};
