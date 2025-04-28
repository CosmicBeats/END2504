// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseRifle.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateType, AActor*, OtherActor);

UCLASS()
class END2504_API ABaseRifle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseRifle();
	void Attack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent* SkeletalMeshComponent;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> ProjectileClass;

	AActor* Actor;
	APawn* Pawn;
	AController* PawnController;
	FRotator AimRotation;
	FVector SocketLocation;

	FTimerHandle TimerHandler;
	FTimerDelegate TimerDelegate;

	bool ActionHappening;

	UPROPERTY(EditDefaultsOnly)
	FName InSocketName;

	bool CanShoot();
	UFUNCTION()
	void ActionStopped();

	float FireRate();

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FDelegateType OnDelegateInstance;

};
