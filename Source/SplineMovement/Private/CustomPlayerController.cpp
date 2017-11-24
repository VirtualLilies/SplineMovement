// Copyright C 2017 Tomasz Figas


#include "CustomPlayerController.h"

void ACustomPlayerController::BeginPlay()
{
	InputComponent->BindAxis("MoveRight", this, &ACustomPlayerController::MoveRight);
}

void ACustomPlayerController::MoveRight(float AxisValue)
{
	if ( (Controller != NULL) || (AxisValue != 0.0f) )
	{
		return;
	}
}
