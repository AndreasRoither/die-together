// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "DieTogether/utility/RespawnActor.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "PaperFlipbookComponent.h"
#include "DeathActorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDeathDelegate, AActor*, actor);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class DIETOGETHER_API UDeathActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UDeathActorComponent();

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Goal")
		FDeathDelegate OnDeathDelegate;

	ARespawnActor* RespawnActor;

	UPROPERTY(EditAnywhere)
		FString PlayerTag;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
		void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnDeath(AActor* actor);
};