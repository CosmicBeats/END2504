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

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Do Stuff Here")
	FName InSocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Do Stuff Here")
	class USkeletalMeshComponent* SkeletalMeshComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Do Stuff Here")
	TSubclassOf<AActor> ProjectileClass;

	AActor* ParentActor;
	APawn* Pawn;
	AController* PawnController;
	FRotator AimRotation;
	FVector SocketLocation;
	FTransform Transform;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
