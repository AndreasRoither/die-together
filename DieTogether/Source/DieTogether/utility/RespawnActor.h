// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PawnMovementComponent.h"
#include "RespawnActor.generated.h"

UCLASS()
class DIETOGETHER_API ARespawnActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARespawnActor();

protected:
	UPROPERTY(EditAnywhere)
		AActor* SpawnLocationActor;

	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnDeath(AActor* actor);
};
