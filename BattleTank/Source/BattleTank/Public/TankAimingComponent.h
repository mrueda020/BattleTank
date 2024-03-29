// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"

//Enum for aiming state

UENUM()
enum class EFiringState : uint8 {
	Reloading,
	Aiming,
	Locked,
	OutOfAmmo
};
//Forward Declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;
//Holds barrel�s properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet);

	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction);


	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	EFiringState GetFiringState() const;

	UFUNCTION(BlueprintCallable, Category = "Firing")
	int32 GetRoundsLeft() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

private:

	
	UTankAimingComponent();
	virtual void BeginPlay() override;

	void MoveBarrelTowards(FVector AimDirection);

	bool IsBarrelMoving();

	UTankBarrel * Barrel = nullptr;
	UTankTurret * Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000; 

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	int32 RoundsLeft = 20;
	
	FVector AimDirection;

	double LastFireTime = 0;

	

};


