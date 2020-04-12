// Fill out your copyright notice in the Description page of Project Settings.


#include "DieTogetherCharacter_coop.h"
#include "GameFramework/Controller.h"
#include "Components/InputComponent.h"

// Sets default values
ADieTogetherCharacter_coop::ADieTogetherCharacter_coop():ADieTogetherCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADieTogetherCharacter_coop::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADieTogetherCharacter_coop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADieTogetherCharacter_coop::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// don't call super, just override
	//Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Note: the 'Jump' action and the 'MoveRight' axis are bound to actual keys/buttons/sticks in DefaultInput.ini (editable from Project Settings..Input)
	PlayerInputComponent->BindAction("Jump2", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump2", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("PickUp2", IE_Pressed, this, &ADieTogetherCharacter_coop::PickUp);

	PlayerInputComponent->BindAxis("MoveAxis2", this, &ADieTogetherCharacter_coop::MoveAxis);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &ADieTogetherCharacter_coop::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ADieTogetherCharacter_coop::TouchStopped);
}

