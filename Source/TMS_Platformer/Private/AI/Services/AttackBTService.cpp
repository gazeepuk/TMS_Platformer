// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Services/AttackBTService.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/BaseAttackComponent.h"

UAttackBTService::UAttackBTService()
{
	NodeName = "Attack Service";
}

void UAttackBTService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	const auto Controller = OwnerComp.GetAIOwner();
	const auto Blackboard = OwnerComp.GetBlackboardComponent();

	const bool bHasName = Blackboard && Blackboard->GetValueAsObject(EnemyActorKey.SelectedKeyName);

	if (Controller)
	{
		const auto AttackComponent = Controller->GetPawn()->GetComponentByClass<UBaseAttackComponent>();
		if (AttackComponent && bHasName)
		{
			AttackComponent->Attack();
		}
	}
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
