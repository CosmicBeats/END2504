// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseRifle.h"

// Sets default values
ABaseRifle::ABaseRifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("SK_Rifle");


	ParentActor = GetOwner();
	
}

void ABaseRifle::Attack()
{
	FActorSpawnParameters Parameters;

	AimRotation = Pawn->GetBaseAimRotation();
	SocketLocation = SkeletalMeshComponent->GetSocketLocation(InSocketName);

	PawnController = Pawn->GetController();

	Transform = FTransform(AimRotation, SocketLocation);

	Parameters.Instigator = Pawn;
	Parameters.Owner = PawnController;
	GetWorld()->SpawnActor<AActor>(ProjectileClass, Transform, Parameters);
}

// Called when the game starts or when spawned
void ABaseRifle::BeginPlay()
{
	Super::BeginPlay();
	Pawn = Cast<APawn>(ParentActor);
}

// Called every frame
void ABaseRifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

