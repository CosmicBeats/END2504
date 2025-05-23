// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "BaseAgent.generated.h"

/**
 * 
 */
UCLASS()
class END2504_API ABaseAgent : public ABaseCharacter
{
	GENERATED_BODY()

public:
	ABaseAgent();
	virtual void PostLoad() override;

private:
	USkeletalMeshComponent* SkeletalMeshComponent;

	UMaterialInstanceDynamic* DynamicMaterial;
	

	virtual void Tick(float DeltaTime) override;
	
};
