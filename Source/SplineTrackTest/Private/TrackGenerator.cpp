// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include "TrackGenerator.h"


// Sets default values
ATrackGenerator::ATrackGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("RoadSpline"));
	SplineComponent->SetupAttachment(RootComponent);
}

void ATrackGenerator::OnConstruction(const FTransform & Transform)
{
	// Store # of spline points
	NumberOfSplinePoints = SplineComponent->GetNumberOfSplinePoints();

	// Build RoadData array
	int32 countDataEntries = RoadDataArray.Num();

	while (countDataEntries != NumberOfSplinePoints)
	{
		if (countDataEntries > NumberOfSplinePoints)
		{
			RoadDataArray.RemoveAt(countDataEntries - 1);
			countDataEntries--;
		}
		if (countDataEntries < NumberOfSplinePoints)
		{
			FRoadData roadData;
			RoadDataArray.Add(roadData);
			countDataEntries++;
		}
	}

	// ConstructTrackMesh
	for (int32 i = 0; i <= NumberOfSplinePoints - (LoopingTrack ? 1 : 2); i++)
	{
		BuildTrackElement(i, RoadMesh);

		if (RoadDataArray[i].LeftGuardRail)
			BuildTrackElement(i, LeftGuardMesh);
		if (RoadDataArray[i].RightGuardRail)
			BuildTrackElement(i, RightGuardMesh);
	}

	// Draw point #s
	if (DrawTrackPointNumbers)
	{
		for (int32 i = 0; i < NumberOfSplinePoints; i++)
		{
			FVector location, tangent;
			SplineComponent->GetLocationAndTangentAtSplinePoint(i, location, tangent, ESplineCoordinateSpace::Local);

			FRotator rotation = (tangent * -1.0f).Rotation();
			
			UTextRenderComponent* TextRender = NewObject<UTextRenderComponent>(this);
			TextRender->CreationMethod = EComponentCreationMethod::UserConstructionScript;
			TextRender->SetupAttachment(RootComponent);

			TextRender->SetRelativeLocation(location + FVector::UpVector * 50);
			TextRender->SetRelativeRotation(rotation);

			TextRender->SetText(FString::FromInt(i));
			TextRender->SetTextRenderColor(FColor(255, 90, 112));
		}
	}

	RegisterAllComponents();
}

void ATrackGenerator::BuildTrackElement(int32 LoopIndex, UStaticMesh * TrackElementMesh)
{
	int32 nextLoopIndex = (LoopIndex + 1) % NumberOfSplinePoints;
	FVector startLocation, startTangent, endLocation, endTangent;

	SplineComponent->GetLocationAndTangentAtSplinePoint(LoopIndex, startLocation, startTangent, ESplineCoordinateSpace::Local);
	SplineComponent->GetLocationAndTangentAtSplinePoint(nextLoopIndex, endLocation, endTangent, ESplineCoordinateSpace::Local);

	USplineMeshComponent* SplineMesh = NewObject<USplineMeshComponent>(this);
	SplineMesh->CreationMethod = EComponentCreationMethod::UserConstructionScript;
	SplineMesh->SetupAttachment(RootComponent);

	//Set mesh (with start and end)
	SplineMesh->SetMobility(EComponentMobility::Movable);
	SplineMesh->SetStaticMesh(TrackElementMesh);
	SplineMesh->SetStartAndEnd(startLocation, startTangent, endLocation, endTangent);

	//Set roll
	SplineMesh->SetStartRoll(RoadDataArray[LoopIndex].TrackBank);
	SplineMesh->SetEndRoll(RoadDataArray[nextLoopIndex].TrackBank);

	//Set scale
	FVector2D startScale = FVector2D(RoadDataArray[LoopIndex].TrackWidth, RoadDataArray[LoopIndex].TrackThickness);
	FVector2D endScale = FVector2D(RoadDataArray[nextLoopIndex].TrackWidth, RoadDataArray[nextLoopIndex].TrackThickness);
	SplineMesh->SetStartScale(startScale);
	SplineMesh->SetEndScale(endScale);
	
	//Set track collision
	SplineMesh->SetCollisionEnabled(Collisions ? ECollisionEnabled::QueryAndPhysics : ECollisionEnabled::NoCollision);

}