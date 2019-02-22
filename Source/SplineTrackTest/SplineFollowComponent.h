// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SplineFollowComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPLINETRACKTEST_API USplineFollowComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USplineFollowComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(Category = Game, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USplineComponent * SplineComponent;

	UPROPERTY(Category = Game, EditAnywhere, BlueprintReadWrite)
		AActor * SplineOwningActor;

	UPROPERTY(Category = Game, EditAnywhere, BlueprintReadWrite)
		float MoveSpeed = 4.0f;

	float CurrentSplinePosition = 0.0f;

	UFUNCTION(BlueprintCallable)
		void SetSplineOwningActor(AActor * act);
	
};
