// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimation.h"
#include "KismetAnimationLibrary.h"
#include "TimerManager.h"
#include "Engine/World.h"

UCharacterAnimation::UCharacterAnimation()
{
	
}

void UCharacterAnimation::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	APawn* Pawn = TryGetPawnOwner();
	if (Pawn)
	{
		// is valid
		Velocity = Pawn->GetVelocity().Size();
		Direction = CalculateDirection(Pawn->GetVelocity(), Pawn->GetControlRotation());

	}
	else
	{
		PreviewWindowUpdate();
	}
}

void UCharacterAnimation::PreviewWindowUpdate()
{
	if (DebugFire == true)
	{
		FireAnimation();
		DebugFire = false;
	}
	else
	{

	}
}

void UCharacterAnimation::FireAnimation()
{
	
	PlaySlotAnimationAsDynamicMontage(FireAnimationAsset, FName("ActionSlotName"));
	
}

