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

private:
	void InputAxisMoveForward(float AxisValue);
	void InputAxisStrafe(float AxisValue);

	void HandleAttack();

protected:
	ABasePlayer();

	UPROPERTY(EditDefaultsOnly)
	class USpringArmComponent* SpringArm;
	UPROPERTY(EditDefaultsOnly)
	class UCameraComponent* Camera;

	
	

public:

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



};
