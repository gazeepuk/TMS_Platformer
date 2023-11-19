// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Perception/AIPerceptionComponent.h"
#include "TMSAIPerceptionComponent.generated.h"

/**
 * 
 */
UCLASS()
class TMS_PLATFORMER_API UTMSAIPerceptionComponent : public UAIPerceptionComponent
{
	GENERATED_BODY()
public:
	AActor* GetClosestEnemy() const;
};
