// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimation.h"
#include "KismetAnimationLibrary.h"

UCharacterAnimation::UCharacterAnimation()
{
	ConstructorHelpers::FObjectFinder<UAnimSequenceBase> FireAsset(TEXT("AnimSequence'/Game/END_Starter/Mannequin/Animations/A_Fire_Ironsights.A_Fire_Ironsights'"));
	FireAnimationAsset = FireAsset.Object;
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
	PlaySlotAnimationAsDynamicMontage(FireAnimationAsset, TEXT("ActionSlotName"));
}