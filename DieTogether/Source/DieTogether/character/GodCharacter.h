// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DieTogether/DieTogetherCharacter.h"
#include "GameFramework/Character.h"
#include "GodCharacter.generated.h"

UCLASS()
class DIETOGETHER_API AGodCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGodCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pawn)
	ADieTogetherCharacter* pawn1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pawn)
	ADieTogetherCharacter* pawn2;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void Jump() override;
	void StopJumping() override;
	void PickUp();
	void MoveAxis(float Value);
	void Jump2();
	void StopJumping2();
	void PickUp2();
	void MoveAxis2(float Value);
};
