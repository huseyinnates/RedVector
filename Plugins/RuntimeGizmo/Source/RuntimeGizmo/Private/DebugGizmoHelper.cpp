#include "DebugGizmoHelper.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

void FDebugGizmoHelper::DrawBoxAroundActor(UWorld* World, AActor* Actor, const FColor& Color, float Thickness, float LifeTime)
{
	if (!World || !Actor) return;

	FVector Origin, Extent;
	Actor->GetActorBounds(false, Origin, Extent);

	DrawDebugBox(World, Origin, Extent, Color, false, LifeTime, 0, Thickness);
}

void FDebugGizmoHelper::DrawTransformAxes(UWorld* World, const FTransform& Transform, float Scale, float LifeTime, float Thickness)
{
	if (!World) return;

	const FVector Location = Transform.GetLocation();
	const FVector X = Transform.GetUnitAxis(EAxis::X) * Scale;
	const FVector Y = Transform.GetUnitAxis(EAxis::Y) * Scale;
	const FVector Z = Transform.GetUnitAxis(EAxis::Z) * Scale;

	DrawDebugLine(World, Location, Location + X, FColor::Red, false, LifeTime, 0, Thickness);   // X Axis
	DrawDebugLine(World, Location, Location + Y, FColor::Green, false, LifeTime, 0, Thickness); // Y Axis
	DrawDebugLine(World, Location, Location + Z, FColor::Blue, false, LifeTime, 0, Thickness);  // Z Axis
}

void FDebugGizmoHelper::DrawSphereAtActor(UWorld* World, AActor* Actor, float Radius, const FColor& Color, float LifeTime)
{
	if (!World || !Actor) return;

	const FVector Location = Actor->GetActorLocation();
	DrawDebugSphere(World, Location, Radius, 16, Color, false, LifeTime);
}

void FDebugGizmoHelper::DrawBoxAtTransform(UWorld* World, const FTransform& Transform, const FVector& Extent, const FColor& Color, float Thickness, float LifeTime)
{
	if (!World) return;

	DrawDebugBox(
		World,
		Transform.GetLocation(),
		Extent,
		Transform.GetRotation(),
		Color,
		false,
		LifeTime,
		0,
		Thickness
	);
}
