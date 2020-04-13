// Fill out your copyright notice in the Description page of Project Settings.

#include "Checkpoint.h"

#include "Components/CapsuleComponent.h"
#include "DieTogether/utility/RespawnActor.h"

// Sets default values
ACheckpoint::ACheckpoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->SetCapsuleSize(40, 96);
	RootComponent = CapsuleComponent;
	CapsuleComponent->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void ACheckpoint::BeginPlay()
{
	Super::BeginPlay();
	CapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &ACheckpoint::OnOverlapBegin);
}

// Called every frame
void ACheckpoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACheckpoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                                 UPrimitiveComponent* OtherComp,
                                 int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag(FName(*PlayerTag)))
	{
		UE_LOG(LogTemp, Warning, TEXT("Checkpoint reached"));

		RespawnActor->SpawnLocationActor = this;
	}
}
