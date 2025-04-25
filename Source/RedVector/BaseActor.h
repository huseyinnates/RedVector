#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseActor.generated.h"

UCLASS()
class REDVECTOR_API ABaseActor : public AActor
{
	GENERATED_BODY()

public:
	ABaseActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	// Draw gizmos related to this actor
	void DrawRuntimeGizmos();
};
