// Fill out your copyright notice in the Description page of Project Settings.

#include "CarPawn.h"
#include "SplineTrackTestWheelFront.h"
#include "SplineTrackTestWheelRear.h"
#include "SplineTrackTestHud.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "WheeledVehicleMovementComponent4W.h"
#include "Engine/SkeletalMesh.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/TextRenderComponent.h"
#include "Materials/Material.h"
#include "GameFramework/Controller.h"

const FName ASplineTrackTestPawn::LookUpBinding("LookUp");
const FName ASplineTrackTestPawn::LookRightBinding("LookRight");

#define LOCTEXT_NAMESPACE "VehiclePawn"

// Sets default values
ACarPawn::ACarPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACarPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACarPawn::MoveForward(float Val)
{
}

void ACarPawn::SetupInCarHUD()
{
}

void ACarPawn::UpdatePhysicsMaterial()
{

}

void ACarPawn::MoveRight(float Val)
{

}

void ACarPawn::OnHandbrakePressed()
{

}

void ACarPawn::OnHandbrakeReleased()
{

}

void ACarPawn::OnToggleCamera()
{

}

void ACarPawn::EnableIncarView(const bool bState, const bool bForce /*= false*/)
{

}

void ACarPawn::UpdateHUDStrings()
{

}

// Called every frame
void ACarPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACarPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

