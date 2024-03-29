// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BattleTank.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
protected:

	//How close can the AI get 
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 8000;

private :
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
};
