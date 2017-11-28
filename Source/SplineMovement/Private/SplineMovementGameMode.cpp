// Copyright C 2017 Tomasz Figas

#include "SplineMovementGameMode.h"
#include "SplineMovement.h"
#include "CustomPlayerController.h"
#include "BaseCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASplineMovementGameMode::ASplineMovementGameMode()
{
	// Set default PlayerController class
	PlayerControllerClass = ACustomPlayerController::StaticClass();

	// Set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_PlayerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

}




