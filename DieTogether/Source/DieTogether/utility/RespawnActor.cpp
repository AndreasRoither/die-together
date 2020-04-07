// Fill out your copyright notice in the Description page of Project Settings.
// ReSharper disable CppMemberFunctionMayBeConst
#include "RespawnActor.h"

#include "DieTogether/world/DeathActorComponent.h"

// Sets default values
ARespawnActor::ARespawnActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ARespawnActor::BeginPlay()
{
	Super::BeginPlay();
}

void ARespawnActor::OnDeath(AActor* actor)
{
	actor->SetActorLocation(SpawnLocationActor->GetActorLocation(), false, nullptr, ETeleportType::ResetPhysics);

	// apparently resetting physics does not reset velocity
	UPawnMovementComponent* comp = dynamic_cast<UPawnMovementComponent*> (actor->GetComponentByClass(UPawnMovementComponent::StaticClass()));
	if (IsValid(comp))
	{
		comp->Velocity = FVector(0);
	}
}

// Called every frame
void ARespawnActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}