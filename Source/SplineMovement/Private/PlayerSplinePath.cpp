// Copyright C 2017 Tomasz Figas

#include "PlayerSplinePath.h"


APlayerSplinePath::APlayerSplinePath()
{
	PlayerSpline = CreateDefaultSubobject<USplineComponent>(FName("Spline"));
}

