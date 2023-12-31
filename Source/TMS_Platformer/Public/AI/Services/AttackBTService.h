// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "AttackBTService.generated.h"

/**
 * 
 */
UCLASS()
class TMS_PLATFORMER_API UAttackBTService : public UBTService
{
	GENERATED_BODY()
public:
	UAttackBTService();
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FBlackboardKeySelector EnemyActorKey;
	
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
