// Fill out your copyright notice in the Description page of Project Settings.


#include "GodCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AGodCharacter::AGodCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 500.0f;
	CameraBoom->SocketOffset = FVector(0.0f, 0.0f, 75.0f);
	CameraBoom->SetUsingAbsoluteRotation(true);
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	// Create an orthographic camera (no perspective) and attach it to the boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;
	SideViewCameraComponent->OrthoWidth = 2048.0f;
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	// Prevent all automatic rotation behavior on the camera, character, and camera component
	CameraBoom->SetUsingAbsoluteRotation(true);
	SideViewCameraComponent->bUsePawnControlRotation = false;
	SideViewCameraComponent->bAutoActivate = true;
}

// Called when the game starts or when spawned
void AGodCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGodCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsValid(pawn1) && IsValid(pawn2))
	{
		float distance = pawn1->GetHorizontalDistanceTo(pawn2);
		SetActorLocation(pawn2->GetActorLocation() + (pawn1->GetActorLocation() - pawn2->GetActorLocation()) / 2);

		//CameraBoom->TargetArmLength = FMath::Clamp(distance, 500.0f, 1500.0f);;
		//CameraBoom->ApplyWorldOffset(FVector(0, distance, 0), false);
		SideViewCameraComponent->OrthoWidth = FMath::Clamp(distance * 1.2f, 2048.0f, 4200.0f);
	}
}

// Called to bind functionality to input
void AGodCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AGodCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AGodCharacter::StopJumping);
	PlayerInputComponent->BindAction("PickUp", IE_Pressed, this, &AGodCharacter::PickUp);
	PlayerInputComponent->BindAxis("MoveAxis", this, &AGodCharacter::MoveAxis);

	PlayerInputComponent->BindAction("Jump2", IE_Pressed, this, &AGodCharacter::Jump2);
	PlayerInputComponent->BindAction("Jump2", IE_Released, this, &AGodCharacter::StopJumping2);
	PlayerInputComponent->BindAction("PickUp2", IE_Pressed, this, &AGodCharacter::PickUp2);
	PlayerInputComponent->BindAxis("MoveAxis2", this, &AGodCharacter::MoveAxis2);

	//PlayerInputComponent->BindTouch(IE_Pressed, this, &AGodCharacter::TouchStarted);
	//PlayerInputComponent->BindTouch(IE_Released, this, &AGodCharacter::TouchStopped);
}

// ********************
// ********************
// Pawn 1

void AGodCharacter::Jump()
{
	if (IsValid(pawn1))
	{
		pawn1->Jump();
	}
}

void AGodCharacter::StopJumping()
{
	if (IsValid(pawn1))
	{
		pawn1->StopJumping();
	}
}

void AGodCharacter::PickUp()
{
	if (IsValid(pawn1))
	{
		pawn1->PickUp();
	}
}

void AGodCharacter::MoveAxis(float Value)
{
	if (IsValid(pawn1))
	{
		pawn1->MoveAxis(Value);
	}
}

// ********************
// ********************
// Pawn 2

void AGodCharacter::Jump2()
{
	if (IsValid(pawn2))
	{
		pawn2->Jump();
	}
}

void AGodCharacter::StopJumping2()
{
	if (IsValid(pawn2))
	{
		pawn2->StopJumping();
	}
}

void AGodCharacter::PickUp2()
{
	if (IsValid(pawn2))
	{
		pawn2->PickUp();
	}
}

void AGodCharacter::MoveAxis2(float Value)
{
	if (IsValid(pawn2))
	{
		pawn2->MoveAxis(Value);
	}
}
