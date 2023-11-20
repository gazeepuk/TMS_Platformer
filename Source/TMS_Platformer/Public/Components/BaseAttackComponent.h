// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HealthComponent.h"
#include "Components/ActorComponent.h"
#include "BaseAttackComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TMS_PLATFORMER_API UBaseAttackComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UBaseAttackComponent();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Attack();
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Radius = 50.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DamageValue = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CoolDown = 3.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UAnimMontage* AttackAnimMontage;

private:
	bool bCanAttack = true;
	FTimerHandle TimerHandle;

	void StartCoolDown();
};
