// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAgent.h"
#include "BaseRifle.h"

ABaseAgent::ABaseAgent()
{
	PrimaryActorTick.bCanEverTick = true;
	

}

void ABaseAgent::PostLoad()
{
	Super::PostLoad();

	SkeletalMeshComponent = GetMesh();

	DynamicMaterial = SkeletalMeshComponent->CreateAndSetMaterialInstanceDynamic(0);

	DynamicMaterial->SetVectorParameterValue(FName("Tint"), FLinearColor::Yellow);
}

void ABaseAgent::Tick(float DeltaTime)
{
	WeaponObject->Attack();
}
