#pragma once

#include "CoreMinimal.h"
#include "SoundTypes.generated.h"

UENUM(BlueprintType)
enum class ESoundEvent : uint8
{
	Explosion_Light,
	Explosion_Heavy,
	Fire_Burning,
	Gunshot_Small,
	Gunshot_Large,
	Background_Music_01,
	Background_Music_02,

	Background_AngelsSing,
	Background_Confession,
	Background_Enigma,
	Background_Entombed,
	Background_Grace,
	Background_Sleepover,
	Background_Confinement,
	Background_Grooves,
	Background_Hubris,
	Background_Scorpio,
	Background_FatalError,
	Background_Milder,
	Background_Mysteron,
	Background_Silk,
	Background_Rebirth,
	Background_Tenute
};
