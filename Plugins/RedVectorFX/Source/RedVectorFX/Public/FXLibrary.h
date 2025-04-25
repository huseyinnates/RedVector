#pragma once

#include "CoreMinimal.h"
#include "FXTypes.h"
#include "FXLibrary.generated.h"

class UNiagaraSystem;

UCLASS()
class REDVECTORFX_API UFXLibrary : public UObject
{
	GENERATED_BODY()

public:
	static void Initialize();
	static UNiagaraSystem* GetFX(FFXTypes Type);

private:
	static TMap<FFXTypes, UNiagaraSystem*> FXMap;
};
