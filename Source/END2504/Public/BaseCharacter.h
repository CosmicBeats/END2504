// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Abstract)
class END2504_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	UChildActorComponent* ChildActorComponent;


	UPROPERTY(EditDefaultsOnly)
	class USkeletalMeshComponent* SkeletalMeshComponent;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> WeaponClass;

	class ABaseRifle* WeaponObject;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UAnimInstance> CharacterAnimationClass;

	class UCharacterAnimation* CharacterAnimation;

	//class ABaseRifle Rifle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
