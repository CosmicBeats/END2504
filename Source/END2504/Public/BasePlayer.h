// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "BasePlayer.generated.h"

/**
 * 
 */
UCLASS()
class END2504_API ABasePlayer : public ABaseCharacter
{
	GENERATED_BODY()


protected:
	ABasePlayer();
	class USpringArmComponent* SpringArm;
	class UCameraComponent* Camera;



public:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



};
