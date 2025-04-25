#pragma once

#include "CoreMinimal.h"

class AActor;
class AStaticMeshActor;

/**
 * Static helper class for drawing debug gizmos like boxes, spheres, and axes in the world.
 */
class RUNTIMEGIZMO_API FDebugGizmoHelper
{
public:

	/** Draws a wireframe box around the actor based on its bounds */
	static void DrawBoxAroundActor(UWorld* World, AActor* Actor, const FColor& Color = FColor::Green, float Thickness = 2.0f, float LifeTime = -1.0f);

	/** Draws world-space transform axes from a transform */
	static void DrawTransformAxes(UWorld* World, const FTransform& Transform, float Scale = 100.0f, float LifeTime = -1.0f, float Thickness = 1.5f);

	/** Draws a debug sphere at the actor's location */
	static void DrawSphereAtActor(UWorld* World, AActor* Actor, float Radius = 30.f, const FColor& Color = FColor::Red, float LifeTime = -1.0f);

	// Add this to your helper's header file
	static void DrawBoxAtTransform(UWorld* World, const FTransform& Transform, const FVector& Extent, const FColor& Color, float Thickness = 1.0f, float LifeTime = -1.0f);

};
