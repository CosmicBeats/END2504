// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "CharacterAnimation.h"
#include "Components/ChildActorComponent.h"
#include "BaseRifle.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -90.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));


	SkeletalMeshComponent = GetMesh();

	ChildActorComponent = CreateDefaultSubobject<UChildActorComponent>("ChildActorComponent");
	ChildActorComponent->SetupAttachment(SkeletalMeshComponent, FName("PlaceWeaponHere"));
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	ChildActorComponent->SetChildActorClass(WeaponClass);

	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	CharacterAnimation = Cast<UCharacterAnimation>(AnimInstance);

	WeaponObject = Cast<ABaseRifle>(ChildActorComponent->GetChildActor());

	WeaponObject->OnDelegateInstance.AddDynamic(CharacterAnimation, &UCharacterAnimation::FireAnimation);
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

