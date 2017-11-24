// Copyright C 2017 Tomasz Figas

#include "CameraSplinePath.h"


ACameraSplinePath::ACameraSplinePath()
{
	CameraSpline = CreateDefaultSubobject<USplineComponent>(FName("Spline"));
}

