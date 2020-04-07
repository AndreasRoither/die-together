// Fill out your copyright notice in the Description page of Project Settings.
// ReSharper disable CppMemberFunctionMayBeConst
#include "DeathActorComponent.h"
#include "PaperSpriteComponent.h"

// Sets default values for this component's properties
UDeathActorComponent::UDeathActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

// Called when the game starts
void UDeathActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// Get respawn actor as there is only a single one
	// and set delegate that will be called if multicast delegate broadcasts
	ARespawnActor* actor = dynamic_cast<ARespawnActor*>(UGameplayStatics::GetActorOfClass(GetWorld(), ARespawnActor::StaticClass()));

	if (IsValid(actor))
	{
		OnDeathDelegate.AddDynamic(actor, &ARespawnActor::OnDeath);
	}

	// Get owner of this component and search for sprite component
	// register both overlap and hit events, in case we want to use both
	AActor* owner = this->GetOwner();
	if (IsValid(owner))
	{
		FScriptDelegate CollisionBeginOverlap;
		CollisionBeginOverlap.BindUFunction(this, TEXT("OnParentActorOverlap"));

		UPaperSpriteComponent* paper = dynamic_cast<UPaperSpriteComponent*>(owner->GetComponentByClass(UPaperSpriteComponent::StaticClass()));

		//owner->OnActorBeginOverlap.Add(CollisionBeginOverlap);
		if (IsValid(paper))
		{
			paper->SetGenerateOverlapEvents(true);
			paper->OnComponentHit.AddDynamic(this, &UDeathActorComponent::OnComponentHit);
			paper->OnComponentBeginOverlap.AddDynamic(this, &UDeathActorComponent::OnOverlapBegin);
		}
	}
}

// Called every frame
void UDeathActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UDeathActorComponent::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Component Hit"));
	OnDeath(OtherActor);
}

void UDeathActorComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Component Overlap"));
	OnDeath(OtherActor);
}

void UDeathActorComponent::OnDeath(AActor* actor)
{
	if (actor->ActorHasTag(FName(*PlayerTag)))
	{
		UE_LOG(LogTemp, Warning, TEXT("OnDeath"));
		OnDeathDelegate.Broadcast(actor);
	}
}