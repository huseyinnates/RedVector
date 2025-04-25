#include "AudioLibrary.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"

TMap<ESoundEvent, USoundBase*> UAudioLibrary::SoundMap;

void UAudioLibrary::Initialize()
{
	SoundMap.Add(ESoundEvent::Background_AngelsSing, LoadObject<USoundBase>(nullptr, TEXT("/Game/Assets/Audio/MP3/01_Angels_sing.01_Angels_sing")));
	SoundMap.Add(ESoundEvent::Background_Confession, LoadObject<USoundBase>(nullptr, TEXT("/Game/Assets/Audio/MP3/01_Confession.01_Confession")));
	SoundMap.Add(ESoundEvent::Background_Enigma, LoadObject<USoundBase>(nullptr, TEXT("/Game/Assets/Audio/MP3/02_Enigma.02_Enigma")));
	SoundMap.Add(ESoundEvent::Background_Entombed, LoadObject<USoundBase>(nullptr, TEXT("/Game/Assets/Audio/MP3/02_Entombed.02_Entombed")));
	SoundMap.Add(ESoundEvent::Background_Grace, LoadObject<USoundBase>(nullptr, TEXT("/Game/Assets/Audio/MP3/03_Grace.03_Grace")));
	SoundMap.Add(ESoundEvent::Background_Sleepover, LoadObject<USoundBase>(nullptr, TEXT("/Game/Assets/Audio/MP3/03_Sleepover.03_Sleepover")));
	SoundMap.Add(ESoundEvent::Background_Confinement, LoadObject<USoundBase>(nullptr, TEXT("/Game/Assets/Audio/MP3/04_Confinement.04_Confinement")));
	SoundMap.Add(ESoundEvent::Background_Grooves, LoadObject<USoundBase>(nullptr, TEXT("/Game/Assets/Audio/MP3/04_Grooves.04_Grooves")));
	SoundMap.Add(ESoundEvent::Background_Hubris, LoadObject<USoundBase>(nullptr, TEXT("/Game/Assets/Audio/MP3/05_Hubris.05_Hubris")));
	SoundMap.Add(ESoundEvent::Background_Scorpio, LoadObject<USoundBase>(nullptr, TEXT("/Game/Assets/Audio/MP3/05_Scorpio.05_Scorpio")));
	SoundMap.Add(ESoundEvent::Background_FatalError, LoadObject<USoundBase>(nullptr, TEXT("/Game/Assets/Audio/MP3/06_Fatal_error.06_Fatal_error")));
	SoundMap.Add(ESoundEvent::Background_Milder, LoadObject<USoundBase>(nullptr, TEXT("/Game/Assets/Audio/MP3/06_Milder.06_Milder")));
	SoundMap.Add(ESoundEvent::Background_Mysteron, LoadObject<USoundBase>(nullptr, TEXT("/Game/Assets/Audio/MP3/07_Mysteron.07_Mysteron")));
	SoundMap.Add(ESoundEvent::Background_Silk, LoadObject<USoundBase>(nullptr, TEXT("/Game/Assets/Audio/MP3/07_Silk.07_Silk")));
	SoundMap.Add(ESoundEvent::Background_Rebirth, LoadObject<USoundBase>(nullptr, TEXT("/Game/Assets/Audio/MP3/08_Rebirth.08_Rebirth")));
	SoundMap.Add(ESoundEvent::Background_Tenute, LoadObject<USoundBase>(nullptr, TEXT("/Game/Assets/Audio/MP3/08_Tenute.08_Tenute")));
}

USoundBase* UAudioLibrary::GetSound(ESoundEvent Type)
{
	return SoundMap.Contains(Type) ? SoundMap[Type] : nullptr;
}
