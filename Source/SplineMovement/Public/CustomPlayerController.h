// Copyright C 2017 Tomasz Figas

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CustomPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SPLINEMOVEMENT_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void MoveRight(float AxisValue);
	
	
};