// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Decorators/HealthDecorator.h"
#include "Components/HealthComponent.h"	
#include "AIController.h"

UHealthDecorator::UHealthDecorator()
{
	NodeName ="Health Percent";
}

bool UHealthDecorator::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	auto const Controller = OwnerComp.GetAIOwner();
	if(!Controller) return false;

	const auto HealthComponent = Controller->GetPawn()->GetComponentByClass<UHealthComponent>();
	if(!HealthComponent || HealthComponent->IsDead()) return false;

	return HealthComponent->GetHealthPercent() <= HealthPercent;
}
