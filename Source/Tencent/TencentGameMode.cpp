// Copyright Epic Games, Inc. All Rights Reserved.

#include "TencentGameMode.h"
#include "TencentCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATencentGameMode::ATencentGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
