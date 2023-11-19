// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UTextRenderComponent;
class UHealthComponent;

UCLASS()
class TMS_PLATFORMER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABaseCharacter(const FObjectInitializer& ObjInit);

protected:
	virtual void BeginPlay() override;
	virtual void OnDeath();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UHealthComponent* HealthComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UTextRenderComponent* HealthTextComponent;
	UAnimMontage* DeathAnimMontage;

private:
	void OnHealthChanged(float Health) const;
};
