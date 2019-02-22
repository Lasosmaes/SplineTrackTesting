// Fill out your copyright notice in the Description page of Project Settings.

#include "SplineFollowComponent.h"
#include "Components/SplineComponent.h"

// Sets default values for this component's properties
USplineFollowComponent::USplineFollowComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USplineFollowComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	if (SplineOwningActor != nullptr)
	{
		SplineComponent = SplineOwningActor->FindComponentByClass<USplineComponent>();
	}

}


// Called every frame
void USplineFollowComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	if (SplineComponent)
	{
		FTransform trans = SplineComponent->GetTransformAtTime(CurrentSplinePosition, ESplineCoordinateSpace::World, false, false);

		GetOwner()->SetActorLocationAndRotation(trans.GetLocation(),

			trans.GetRotation());

		CurrentSplinePosition += DeltaTime * MoveSpeed;
		// wrap if we are past the end of the spline (spline duration)
		if (CurrentSplinePosition > SplineComponent->Duration)
		{
			CurrentSplinePosition -= SplineComponent->Duration;
		}
	}

}

void USplineFollowComponent::SetSplineOwningActor(AActor * act)
{
	SplineOwningActor = act;
	if (SplineOwningActor != nullptr)
	{
		SplineComponent = SplineOwningActor->FindComponentByClass<USplineComponent>();
	}
}
