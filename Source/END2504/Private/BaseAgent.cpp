// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAgent.h"
#include "BaseRifle.h"

ABaseAgent::ABaseAgent()
{
	PrimaryActorTick.bCanEverTick = true;
	

}

void ABaseAgent::Tick(float DeltaTime)
{
	WeaponObject->Attack();
}
