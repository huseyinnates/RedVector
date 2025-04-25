#pragma once

#include "CoreMinimal.h"
#include "SoundTypes.h"
#include "AudioLibrary.generated.h"

class USoundBase;

UCLASS()
class REDVECTORAUDIO_API UAudioLibrary : public UObject
{
	GENERATED_BODY()

public:
	static void Initialize();
	static USoundBase* GetSound(ESoundEvent Type);

private:
	static TMap<ESoundEvent, USoundBase*> SoundMap;
};
