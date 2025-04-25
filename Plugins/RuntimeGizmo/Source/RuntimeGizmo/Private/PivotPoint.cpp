#include "PivotPoint.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

void UPivotPoint::ApplyPivotRotation(UStaticMeshComponent* MeshComp, const FRotator& PivotRotation)
{
	if (!MeshComp || !MeshComp->GetOwner())
	{
		UE_LOG(LogTemp, Warning, TEXT("ApplyPivotRotation: Invalid StaticMeshComponent or no Owner."));
		return;
	}

	AActor* Owner = MeshComp->GetOwner();

	// Get parent component (or fallback to RootComponent)
	USceneComponent* OriginalParent = MeshComp->GetAttachParent();
	FTransform OriginalRelativeTransform = MeshComp->GetRelativeTransform();

	// Create the pivot component
	USceneComponent* PivotComp = NewObject<USceneComponent>(Owner, USceneComponent::StaticClass(), NAME_None, RF_Transient);
	if (!PivotComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("ApplyPivotRotation: Failed to create pivot component."));
		return;
	}

	PivotComp->RegisterComponent();
	PivotComp->AttachToComponent(OriginalParent ? OriginalParent : Owner->GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);

	// Set the pivot's location to where the mesh is
	PivotComp->SetRelativeLocation(OriginalRelativeTransform.GetLocation());

	// Apply the pivot rotation
	PivotComp->SetRelativeRotation(PivotRotation);

	// Compute inverse rotation to keep mesh visually unchanged
	FRotator InverseRotation = PivotRotation.GetInverse();

	// Attach mesh to pivot and apply inverse rotation
	MeshComp->DetachFromComponent(FDetachmentTransformRules::KeepRelativeTransform);
	MeshComp->AttachToComponent(PivotComp, FAttachmentTransformRules::KeepRelativeTransform);

	// Apply inverse rotation to the mesh (to cancel out the pivot rotation)
	MeshComp->SetRelativeRotation(InverseRotation);
	MeshComp->SetRelativeLocation(FVector::ZeroVector);

	UE_LOG(LogTemp, Log, TEXT("ApplyPivotRotation: Pivot rotated (%s), mesh counter-rotated."), *PivotRotation.ToCompactString());
}