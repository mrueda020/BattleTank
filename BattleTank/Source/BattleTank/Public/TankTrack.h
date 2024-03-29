// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
public:	
	// Sets a throttle between -1 and +1
	    UFUNCTION(BlueprintCallable, Category = "Input" )
		void SetThrottle(float Throttle);
		
   //Max force per track in newtons
		UPROPERTY(EditDefaultsOnly)
		//float TrackMaxDrivingForce = 400000000;
			float TrackMaxDrivingForce = 900000000;
private:
		UTankTrack();

		virtual void BeginPlay() override;


		void ApplySidewaysForce();


		void DriveTrack();

		UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

		float CurrentThrottle = 0;
};



