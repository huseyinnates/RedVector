#include "FXLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"

TMap<FFXTypes, UNiagaraSystem*> UFXLibrary::FXMap;

void UFXLibrary::Initialize()
{
	// Fire Effects
	FXMap.Add(FFXTypes::Fire_01, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Fire/NS_Fire_FX_System_01.NS_Fire_FX_System_01")));
	FXMap.Add(FFXTypes::Fire_02, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Fire/NS_Fire_FX_System_02.NS_Fire_FX_System_02")));
	FXMap.Add(FFXTypes::Fire_03, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Fire/NS_Fire_FX_System_03.NS_Fire_FX_System_03")));

	// Explosions
	FXMap.Add(FFXTypes::Explosion_Car, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Explosions/NS_Car_Ex.NS_Car_Ex")));
	FXMap.Add(FFXTypes::Explosion_Barrel, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Explosions/NS_Barrel_Ex.NS_Barrel_Ex")));
	FXMap.Add(FFXTypes::Explosion_Grenade_01, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Explosions/NS_Grenade_Ex_01.NS_Grenade_Ex_01")));
	FXMap.Add(FFXTypes::Explosion_Grenade_02, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Explosions/NS_Grenade_Ex_02.NS_Grenade_Ex_02")));

	FXMap.Add(FFXTypes::Explosion_General_L_01, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Explosions/NS_General_L_Ex_01.NS_General_L_Ex_01")));
	FXMap.Add(FFXTypes::Explosion_General_L_02, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Explosions/NS_General_L_Ex_02.NS_General_L_Ex_02")));
	FXMap.Add(FFXTypes::Explosion_General_L_03, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Explosions/NS_General_L_Ex_03.NS_General_L_Ex_03")));

	FXMap.Add(FFXTypes::Explosion_General_M_01, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Explosions/NS_General_M_Ex_01.NS_General_M_Ex_01")));
	FXMap.Add(FFXTypes::Explosion_General_M_02, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Explosions/NS_General_M_Ex_02.NS_General_M_Ex_02")));
	FXMap.Add(FFXTypes::Explosion_General_M_03, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Explosions/NS_General_M_Ex_03.NS_General_M_Ex_03")));

	FXMap.Add(FFXTypes::Explosion_General_Mass_01, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Explosions/NS_General_Mas_Ex_01.NS_General_Mas_Ex_01")));
	FXMap.Add(FFXTypes::Explosion_General_Mass_02, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Explosions/NS_General_Mas_Ex_02.NS_General_Mas_Ex_02")));
	FXMap.Add(FFXTypes::Explosion_General_Mass_03, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Explosions/NS_General_Mas_Ex_03.NS_General_Mas_Ex_03")));

	FXMap.Add(FFXTypes::Explosion_General_S_01, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Explosions/NS_General_S_Ex_01.NS_General_S_Ex_01")));
	FXMap.Add(FFXTypes::Explosion_General_S_02, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Explosions/NS_General_S_Ex_02.NS_General_S_Ex_02")));
	FXMap.Add(FFXTypes::Explosion_General_S_03, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Explosions/NS_General_S_Ex_03.NS_General_S_Ex_03")));

	// Atomic Bomb
	FXMap.Add(FFXTypes::Atomic_Bomb, LoadObject<UNiagaraSystem>(nullptr, TEXT("/Game/PyroVFX/Niagara_FX/Atomic_Explosion/NS_Atomic_Bomb_Emitter.NS_Atomic_Bomb_Emitter")));
}


UNiagaraSystem* UFXLibrary::GetFX(FFXTypes Type)
{
	return FXMap.Contains(Type) ? FXMap[Type] : nullptr;
}
