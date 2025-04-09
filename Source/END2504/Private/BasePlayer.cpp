// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayer.h"
#include "GameFramework/SpringArmComponent.h"

ABasePlayer::ABasePlayer()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetRelativeLocation(FVector(0.f, 80.f, 90.f));
	SpringArm->SetupAttachment(GetRootComponent());
}

