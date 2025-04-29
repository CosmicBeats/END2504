// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimation.generated.h"

/**
 * 
 */
UCLASS()
class END2504_API UCharacterAnimation : public UAnimInstance
{
	GENERATED_BODY()
public:
	void NativeUpdateAnimation(float DeltaSeconds) override;

	UCharacterAnimation();

	UFUNCTION()
	void FireAnimation();

	

protected:

	UPROPERTY(EditAnywhere)
	UAnimSequenceBase* FireAnimationAsset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Velocity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Direction;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool DebugFire;

	void PreviewWindowUpdate();

private:

	FTimerHandle TimerHandler;
	FTimerDelegate TimerDelegate;
};
