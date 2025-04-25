#include "BaseActor.h"
#include "DebugGizmoHelper.h" // Make sure your plugin is added to the project & module
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"

ABaseActor::ABaseActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABaseActor::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawRuntimeGizmos();
}
void ABaseActor::DrawRuntimeGizmos()
{
	UWorld* World = GetWorld();
	if (!World) return;

	// Draw a box around the actor (root)
	//FDebugGizmoHelper::DrawBoxAroundActor(World, this, FColor::Yellow, 2.0f);

	// Draw actor's root transform axes
	FDebugGizmoHelper::DrawTransformAxes(World, GetActorTransform(), 75.0f, -1.0f);

	// Get Static Mesh Component
	UStaticMeshComponent* StaticMeshComp = FindComponentByClass<UStaticMeshComponent>();
	if (StaticMeshComp)
	{
		// Draw gizmo (axes) for the mesh component's local transform
		FTransform MeshTransform = StaticMeshComp->GetComponentTransform();
		FDebugGizmoHelper::DrawTransformAxes(World, MeshTransform, 50.0f, -1.0f);

		// Optional: Draw bounds box for visual clarity
		//FVector Extent = StaticMeshComp->Bounds.BoxExtent;
		//FDebugGizmoHelper::DrawBoxAtTransform(World, MeshTransform, Extent, FColor::Green, 2.0f);
	}
}

