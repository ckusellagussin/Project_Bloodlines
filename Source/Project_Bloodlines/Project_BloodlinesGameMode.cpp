// Copyright Epic Games, Inc. All Rights Reserved.

#include "Project_BloodlinesGameMode.h"
#include "Project_BloodlinesPlayerController.h"
#include "Project_BloodlinesCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProject_BloodlinesGameMode::AProject_BloodlinesGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AProject_BloodlinesPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}