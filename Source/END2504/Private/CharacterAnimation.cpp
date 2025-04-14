// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimation.h"
#include "KismetAnimationLibrary.h"

void UCharacterAnimation::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	APawn* Pawn = TryGetPawnOwner();
	if (Pawn)
	{
		// is valid
		Velocity = Pawn->GetVelocity().Length();
		FRotator ActorRotation = Pawn->GetActorRotation();
		CalculateDirection(FVector(Velocity), ActorRotation);

	}
	else
	{
		// not valid
	}
}
