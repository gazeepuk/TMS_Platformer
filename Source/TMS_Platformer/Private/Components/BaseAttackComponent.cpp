// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/BaseAttackComponent.h"

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
	const auto Owner = GetOwner();
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
			if(const auto HealthComponent = Hit.GetActor()->GetComponentByClass<UHealthComponent>())
			{
				HealthComponent->SetHealth(HealthComponent->GetHealth()-DamageValue);
			}
		}
	}
}
