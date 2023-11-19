// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/TMSAIPerceptionComponent.h"

#include "AIController.h"
#include "Components/HealthComponent.h"
#include "Perception/AISense_Sight.h"

AActor* UTMSAIPerceptionComponent::GetClosestEnemy() const
{
	TArray<AActor*> PercieveActors;
	GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), PercieveActors);
	if(PercieveActors.Num() == 0)
	{
		return nullptr;
	}

	const auto Controller = Cast<AAIController>(GetOwner());
	if(!Controller)
	{
		return nullptr;
	}

	const auto Pawn = Controller->GetPawn();
	if(!Pawn)
	{
		return nullptr;
	}

	float ShortestDistance = MAX_FLT;
	AActor* NearestPawn = nullptr;
	for(const auto PercieveActor : PercieveActors)
	{
		if(const auto HealthComponent = PercieveActor->FindComponentByClass<UHealthComponent>();
			HealthComponent && !HealthComponent->IsDead())
		{
			const auto CurrentDistance = (PercieveActor->GetActorLocation() - Pawn->GetActorLocation()).Size();
			if(CurrentDistance < ShortestDistance)
			{
				ShortestDistance = CurrentDistance;
				NearestPawn = PercieveActor;
			}
		}
	}
	return NearestPawn;
}
