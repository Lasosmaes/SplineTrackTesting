// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "SplineTrackTestGameMode.h"
#include "SplineTrackTestPawn.h"
#include "SplineTrackTestHud.h"

ASplineTrackTestGameMode::ASplineTrackTestGameMode()
{
	DefaultPawnClass = ASplineTrackTestPawn::StaticClass();
	HUDClass = ASplineTrackTestHud::StaticClass();
}
