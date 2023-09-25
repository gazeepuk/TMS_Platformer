// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Platforms/BasePlatform.h"
#include "HightJumpPlatform.generated.h"

/**
 * 
 */
UCLASS()
class TMS_PLATFORMER_API AHightJumpPlatform : public ABasePlatform
{
	GENERATED_BODY()

public:
	AHightJumpPlatform();

protected:
virtual void BeginPlay() override;
	
	UPROPERTY(EditInstanceOnly)
	double JumpForce;

private:
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
			   FVector NormalImpulse, const FHitResult& Hit);
};
