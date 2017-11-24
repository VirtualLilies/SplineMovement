// Copyright C 2017 Tomasz Figas

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "PlayerSplinePath.generated.h"

/**
 * 
 */
UCLASS()
class SPLINEMOVEMENT_API APlayerSplinePath : public AActor
{
	GENERATED_BODY()
	
public:
	APlayerSplinePath();

protected:
	USplineComponent* PlayerSpline = nullptr;
	
	
};
