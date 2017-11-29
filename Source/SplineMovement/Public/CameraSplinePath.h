// Copyright C 2017 Tomasz Figas

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "CameraSplinePath.generated.h"

/**
 * 
 */
UCLASS()
class SPLINEMOVEMENT_API ACameraSplinePath : public AActor
{
	GENERATED_BODY()

public:
	ACameraSplinePath();
	
	UPROPERTY()
	USplineComponent* CameraSpline = nullptr;
	
	
};
