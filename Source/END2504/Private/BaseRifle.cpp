// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseRifle.h"
#include "TimerManager.h"
#include "Engine/World.h"

// Sets default values
ABaseRifle::ABaseRifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("SK_Rifle");


	
	
}

void ABaseRifle::Attack()
{
	if (CanShoot())
	{
		FActorSpawnParameters Parameters;

		PawnController = Pawn->GetController();


		Parameters.Owner = PawnController;
		Parameters.Instigator = Pawn;

		AimRotation = Pawn->GetBaseAimRotation();

		SocketLocation = SkeletalMeshComponent->GetSocketLocation(InSocketName);

		GetWorld()->SpawnActor<AActor>(ProjectileClass, SocketLocation, AimRotation, Parameters);

		ActionHappening = true;

		GetWorldTimerManager().SetTimer(TimerHandler, TimerDelegate, FireRate(), false);
	}

	
}

// Called when the game starts or when spawned
void ABaseRifle::BeginPlay()
{
	Super::BeginPlay();
	Actor = GetParentActor();
	Pawn = Cast<APawn>(Actor);

	TimerDelegate.BindUFunction(this, FName("ActionStopped"));

	if (Pawn == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Pawn is null"));
		Destroy();
	}
	else
	{

	}
}

bool ABaseRifle::CanShoot()
{
	return !ActionHappening;
}

void ABaseRifle::ActionStopped()
{
	ActionHappening = false;
}

float ABaseRifle::FireRate()
{
	return 2.0f;
}

// Called every frame
void ABaseRifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

