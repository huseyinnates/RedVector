// Copyright Epic Games, Inc. All Rights Reserved.

#include "RedVectorAudio.h"
#include "AudioLibrary.h"
#define LOCTEXT_NAMESPACE "FRedVectorAudioModule"

void FRedVectorAudioModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	UAudioLibrary::Initialize();
}

void FRedVectorAudioModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRedVectorAudioModule, RedVectorAudio)