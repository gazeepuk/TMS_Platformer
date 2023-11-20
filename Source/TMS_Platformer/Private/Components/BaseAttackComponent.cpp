// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/BaseAttackComponent.h"

#include "Character/BaseCharacter.h"
#include "Components/HealthComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UBaseAttackComponent::UBaseAttackComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UBaseAttackComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UBaseAttackComponent::Attack()
{
	if(!bCanAttack)
	{
		return;
	}
	const auto Owner = Cast<ABaseCharacter>(GetOwner());
	Owner->PlayAnimMontage(AttackAnimMontage);
	TArray<FHitResult> HitArray;
	const bool bHitted = UKismetSystemLibrary::SphereTraceMulti(GetWorld(), Owner->GetActorLocation(),
	                                       GetOwner()->GetActorLocation() + Owner->GetActorForwardVector() * 10.0f,
	                                       Radius, UEngineTypes::ConvertToTraceType(ECC_Pawn), false, {},
	                                       EDrawDebugTrace::None, HitArray, true, FLinearColor::Green,
	                                       FLinearColor::Red, 0.0f);
	if(bHitted)
	{
		for (auto Hit : HitArray)
		{
			if(const auto HitHealthComponent = Hit.GetActor()->GetComponentByClass<UHealthComponent>())
			{

				HitHealthComponent->OnTakeAnyDamage(HitHealthComponent->GetOwner(),DamageValue,nullptr,Owner->Controller,Owner);
		 	}
		}
	}

	bCanAttack = false;
	
	if(GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UBaseAttackComponent::StartCoolDown, CoolDown, false);
	}
}

void UBaseAttackComponent::StartCoolDown()
{
	bCanAttack = true;
}
