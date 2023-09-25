// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Platforms/BasePlatform.h"
#include "FallingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class TMS_PLATFORMER_API AFallingPlatform : public ABasePlatform
{
public:
	GENERATED_BODY()
	AFallingPlatform();

protected:
virtual void BeginPlay() override;
	
	FTimerHandle TimerHandle;

	UPROPERTY(EditInstanceOnly)
	float lifeSpan = 5.0f;

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	           FVector NormalImpulse, const FHitResult& Hit);
	UFUNCTION()
	void StartLifeSpan();
};
