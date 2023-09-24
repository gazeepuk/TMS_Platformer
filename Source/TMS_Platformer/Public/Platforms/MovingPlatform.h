// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Platforms/BasePlatform.h"
#include "MovingPlatform.generated.h"


class UInterpToMovementComponent;

UCLASS()
class TMS_PLATFORMER_API AMovingPlatform : public ABasePlatform
{
	GENERATED_BODY()

public:
	AMovingPlatform();

protected:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Movement")
	UInterpToMovementComponent* InterpToMovementComponent;
};