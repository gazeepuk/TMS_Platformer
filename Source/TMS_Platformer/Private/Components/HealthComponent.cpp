// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealthComponent.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

bool UHealthComponent::TryHeal(float HealAmount)
{
	if(IsDead() || IsHealthFull()) return false;
	SetHealth(HealAmount+CurrentHealth);
	return true;
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	check(MaxHealth > 0);
	
	SetHealth(MaxHealth);
	AActor* ComponentOwner = GetOwner();
	if (ComponentOwner)
	{
		ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::OnTakeAnyDamage);
	}
}

void UHealthComponent::OnTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
										 AController* InstigatedBy, AActor* DamageCauser)
{
	GetWorld()->GetTimerManager().ClearTimer(HealTimerHandle);

	if (Damage <= 0 || IsDead() || !GetWorld()) return;

	SetHealth(CurrentHealth-Damage);

	if (IsDead())
	{
		OnDeath.Broadcast();
	}
	else if (bAutoHeal)
	{
		GetWorld()->GetTimerManager().SetTimer(HealTimerHandle, this, &UHealthComponent::OnHealed,
											   HealthUpdateTime, true, HealthDelay);
	}
}

void UHealthComponent::SetHealth(float NewHealth)
{
	CurrentHealth = FMath::Clamp(NewHealth,0.0f,MaxHealth);
	OnHealthChanged.Broadcast(CurrentHealth);
}

void UHealthComponent::OnHealed()
{
	SetHealth(CurrentHealth+HealthModifier);
	if(CurrentHealth == MaxHealth && GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(HealTimerHandle);
	}
	
}