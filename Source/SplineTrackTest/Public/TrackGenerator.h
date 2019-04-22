// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrackGenerator.generated.h"

USTRUCT(BlueprintType)
struct FRoadData 
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool LeftGuardRail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool RightGuardRail;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TrackBank;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TrackWidth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float TrackThickness;

	FRoadData() {
		LeftGuardRail = false;
		RightGuardRail = false;
		TrackBank = 0.0f;
		TrackWidth = 1.0f;
		TrackThickness = 1.0f;
	}
};

UCLASS()
class SPLINETRACKTEST_API ATrackGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrackGenerator();

protected:

	virtual void BuildTrackElement(int32 LoopIndex, UStaticMesh* TrackElementMesh);

public:	

	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class USplineComponent* SplineComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
		TArray<FRoadData> RoadDataArray;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
		bool LoopingTrack = false;

	//Meshes
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Mesh")
		UStaticMesh* RoadMesh = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Mesh")
		UStaticMesh* LeftGuardMesh = nullptr;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Mesh")
		UStaticMesh* RightGuardMesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		bool Collisions = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Debug")
		bool DrawTrackPointNumbers = true;

private:
	int32 NumberOfSplinePoints = 0;

	
};
