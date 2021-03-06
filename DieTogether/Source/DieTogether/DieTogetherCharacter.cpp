// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "DieTogetherCharacter.h"
#include "PaperFlipbookComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Camera/CameraComponent.h"

DEFINE_LOG_CATEGORY_STATIC(SideScrollerCharacter, Log, All);

//////////////////////////////////////////////////////////////////////////
// ADieTogetherCharacter

ADieTogetherCharacter::ADieTogetherCharacter()
{
	// Use only Yaw from the controller and ignore the rest of the rotation.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;
	bPickedUp = false;
	bGoingRight = true;

	// Set the size of our collision capsule.
	GetCapsuleComponent()->SetCapsuleHalfHeight(96.0f);
	GetCapsuleComponent()->SetCapsuleRadius(40.0f);

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 500.0f;
	CameraBoom->SocketOffset = FVector(0.0f, 0.0f, 0.0f);
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
	GetCharacterMovement()->bOrientRotationToMovement = false;

	// Configure character movement
	GetCharacterMovement()->GravityScale = 2.0f;
	GetCharacterMovement()->AirControl = 1.0f;
	GetCharacterMovement()->AirControlBoostMultiplier = 1.0f;
	GetCharacterMovement()->JumpZVelocity = 500.0f;
	GetCharacterMovement()->GroundFriction = 3.0f;
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	GetCharacterMovement()->MaxFlySpeed = 600.0f;

	// Lock character motion onto the XZ plane, so the character can't move in or out of the screen
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintNormal(FVector(0.0f, -1.0f, 0.0f));

	// Behave like a traditional 2D platformer character, with a flat bottom instead of a curved capsule bottom
	// Note: This can cause a little floating when going up inclines; you can choose the tradeoff between better
	// behavior on the edge of a ledge versus inclines by setting this to true or false
	GetCharacterMovement()->bUseFlatBaseForFloorChecks = true;

	// 	TextComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("IncarGear"));
	// 	TextComponent->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));
	// 	TextComponent->SetRelativeLocation(FVector(35.0f, 5.0f, 20.0f));
	// 	TextComponent->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
	// 	TextComponent->SetupAttachment(RootComponent);

	// Enable replication on the Sprite component so animations show up when networked
	GetSprite()->SetIsReplicated(true);
	bReplicates = true;

	// picked up item
	CurrentPickedUpActor = nullptr;
}

//////////////////////////////////////////////////////////////////////////
// Animation

void ADieTogetherCharacter::UpdateAnimation()
{
	const FVector PlayerVelocity = GetVelocity();
	const float PlayerSpeedSqr = PlayerVelocity.SizeSquared();

	// Are we moving or standing still?
	UPaperFlipbook* DesiredAnimation = (PlayerSpeedSqr > 0.0f) ? RunningAnimation : IdleAnimation;
	if (GetSprite()->GetFlipbook() != DesiredAnimation)
	{
		GetSprite()->SetFlipbook(DesiredAnimation);
	}
}

void ADieTogetherCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UpdateCharacter();
	UpdatePickedUpElement();
}


//////////////////////////////////////////////////////////////////////////
// Input

void ADieTogetherCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Note: the 'Jump' action and the 'MoveRight' axis are bound to actual keys/buttons/sticks in DefaultInput.ini (editable from Project Settings..Input)
	/*PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("PickUp", IE_Pressed, this, &ADieTogetherCharacter::PickUp);

	PlayerInputComponent->BindAxis("MoveAxis", this, &ADieTogetherCharacter::MoveAxis);

	//PlayerInputComponent->BindTouch(IE_Pressed, this, &ADieTogetherCharacter::TouchStarted);
	//PlayerInputComponent->BindTouch(IE_Released, this, &ADieTogetherCharacter::TouchStopped);*/
}

void ADieTogetherCharacter::PickUp()
{
	if (bPickedUp) return;

	if (IsValid(CurrentPickedUpActor))
	{
		Drop();
	}
	else
	{
		TArray<AActor*> actors;
		GetOverlappingActors(actors);

		const FName Tag = FName(*PickAbleTag);
		actors = actors.FilterByPredicate([&](AActor* PredicateActor) { return PredicateActor->ActorHasTag(Tag); });

		if (actors.Num() == 0) return;

		AActor* ClosestActor = *actors.GetData();
		float ClosestDistance = ClosestActor->GetDistanceTo(this);

		for (auto Actor : actors)
		{
			if (!Actor->ActorHasTag(FName(*PickAbleTag)))
				continue;

			const float TempDistance = Actor->GetDistanceTo(this);

			if (Actor->GetDistanceTo(this) < ClosestDistance)
			{
				ClosestDistance = TempDistance;
				ClosestActor = Actor;
			}
		}

		if (IsValid(ClosestActor))
		{
			CurrentPickedUpActor = ClosestActor;

			ADieTogetherCharacter* Character = dynamic_cast<ADieTogetherCharacter*>(CurrentPickedUpActor);

			if (IsValid(Character))
			{
				Character->GetCharacterMovement()->Velocity = FVector(0, 0, 0);
				Character->GetCharacterMovement()->GravityScale = 0.0f;
				Character->bPickedUp = true;
				//Character->CurrentPickedUpActor = this;
			}

			FAttachmentTransformRules rules = FAttachmentTransformRules(EAttachmentRule::SnapToTarget,
			                                                            EAttachmentRule::KeepWorld,
			                                                            EAttachmentRule::KeepWorld, false);

			CurrentPickedUpActor->AttachToComponent(GetSprite(), rules, FName(*PickableSocketTag));
		}
	}
}

void ADieTogetherCharacter::Drop()
{
	if (bPickedUp)
	{
		ADieTogetherCharacter* Character = dynamic_cast<ADieTogetherCharacter*>(GetAttachParentActor());

		if (IsValid(Character))
		{
			this->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);

			this->GetCharacterMovement()->GravityScale = 2.0f;
			this->LaunchCharacter(FVector(Character->GetVelocity().X, 0, 800 + Character->GetVelocity().Z / 5) * 1.2f,
			                      false, false);

			bPickedUp = false;
			Character->CurrentPickedUpActor = nullptr;
		}
	}

	if (IsValid(CurrentPickedUpActor))
	{
		CurrentPickedUpActor->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		ADieTogetherCharacter* Character = dynamic_cast<ADieTogetherCharacter*>(CurrentPickedUpActor);

		if (IsValid(Character))
		{
			Character->LaunchCharacter(FVector(GetVelocity().X, 0, 800 + GetVelocity().Z / 5) * 1.2f, false, false);
			Character->GetCharacterMovement()->GravityScale = 2.0f;
			Character->CurrentPickedUpActor = nullptr;
			Character->bPickedUp = false;
		}

		CurrentPickedUpActor = nullptr;
	}
}

void ADieTogetherCharacter::UpdatePickedUpElement()
{
}

void ADieTogetherCharacter::MoveAxis(float Value)
{
	if (bPickedUp) return;

	// Apply the input to the character motion
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
}

void ADieTogetherCharacter::Jump()
{
	if (bPickedUp)
	{
		Drop();
	}
	else
	{
		Super::Jump();
	}
}

void ADieTogetherCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	Super::Jump();
}

void ADieTogetherCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// Cease jumping once touch stopped
	StopJumping();
}

void ADieTogetherCharacter::UpdateCharacter()
{
	// Update animation to match the motion
	UpdateAnimation();

	if (bPickedUp) return;

	// Now setup the rotation of the controller based on the direction we are travelling
	const FVector PlayerVelocity = GetVelocity();
	float TravelDirection = PlayerVelocity.X;

	if (TravelDirection < 0.0f)
	{
		SetActorRotation(FRotator(0, -180, 0));
	}
	else if (TravelDirection > 0.0f)
	{
		SetActorRotation(FRotator(0, 0, 0));
	}
}
