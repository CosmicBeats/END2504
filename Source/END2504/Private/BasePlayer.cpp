// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayer.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "CharacterAnimation.h"
#include "BaseRifle.h"


ABasePlayer::ABasePlayer()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->SetRelativeLocation(FVector(0.f, 0.f, 90.f));
	

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	
}

void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("TurnRight", this, &ABasePlayer::AddControllerYawInput);

	PlayerInputComponent->BindAxis("LookUp", this, &ABasePlayer::AddControllerPitchInput);


	PlayerInputComponent->BindAxis("MoveForward", this, &ABasePlayer::InputAxisMoveForward);
	PlayerInputComponent->BindAxis("Strafe", this, &ABasePlayer::InputAxisStrafe);


	PlayerInputComponent->BindAction("Attack", EInputEvent::IE_Pressed, this, &ABasePlayer::HandleAttack);
}

void ABasePlayer::InputAxisMoveForward(float AxisValue)
{
	FRotator ReturnValue = GetControlRotation();
	float Yaw = ReturnValue.Yaw;
	FRotator MakeRotator(0.0f, Yaw, 0.0f);
	FVector WorldDirection = MakeRotator.Vector();
	AddMovementInput(WorldDirection, AxisValue);
}

void ABasePlayer::InputAxisStrafe(float AxisValue)
{
	FVector StrafeDirection = GetActorRightVector();
	AddMovementInput(StrafeDirection, AxisValue);
}

void ABasePlayer::HandleAttack()
{
	BaseRifle->Attack();
	CharacterAnimation->FireAnimation();
}