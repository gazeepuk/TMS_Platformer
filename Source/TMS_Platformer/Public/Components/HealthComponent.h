// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeath)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float)

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TMS_PLATFORMER_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHealthComponent();

	FOnDeath OnDeath;
	FOnHealthChanged OnHealthChanged;	
	
	float GetHealth() const { return CurrentHealth; }
	
	UFUNCTION(BlueprintCallable, Category="Health")
	float GetHealthPercent() const { return CurrentHealth/MaxHealth;}
	
	UFUNCTION(BlueprintCallable)
	bool IsDead() const {return  FMath::IsNearlyZero(CurrentHealth);}

	UFUNCTION(BlueprintCallable)
	void OnHealed();

	UFUNCTION(BlueprintCallable,BlueprintPure)
	bool IsHealthFull() const {return FMath::IsNearlyEqual(CurrentHealth, MaxHealth);}

	UFUNCTION(BlueprintCallable)
	bool TryHeal(float HealAmount);
protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (ClampMin="0.0", ClampMax="1000"), Category="Health")
	float MaxHealth = 100.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Health")
	bool bAutoHeal = true;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Health", meta=(EditCondition="bAutoHeal"))
	float HealthUpdateTime = 0.3;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Health", meta=(EditCondition="bAutoHeal"))
	float HealthDelay = 3.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category= "Health", meta=(EditCondition="bAutoHeal"))
	float HealthModifier = 1.0f;
	
	FTimerHandle HealTimerHandle;
public:	
	UFUNCTION()
	void OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
	AController* InstigatedBy, AActor* DamageCauser);
	float CurrentHealth = 0.0f;
	void SetHealth(float NewHealth);
};
