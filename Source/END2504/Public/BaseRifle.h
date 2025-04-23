// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseRifle.generated.h"

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

	UPROPERTY(EditDefaultsOnly)
	FName InSocketName;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
