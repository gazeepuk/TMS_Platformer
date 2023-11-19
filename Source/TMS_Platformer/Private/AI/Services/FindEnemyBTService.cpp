// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/Services/FindEnemyBTService.h"

#include "AIController.h"
#include "AI/TMSAIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

class UAIPerceptionComponent;

UFindEnemyBTService::UFindEnemyBTService()
{
	NodeName = "FindEnemy";
}

void UFindEnemyBTService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	const auto Blackboard = OwnerComp.GetBlackboardComponent();
	if (Blackboard)
	{
		const auto Controller = OwnerComp.GetAIOwner();
		const auto PerceptionComponent = Controller->FindComponentByClass<UTMSAIPerceptionComponent>();
		if(PerceptionComponent)
		{
			Blackboard->SetValueAsObject(EnemyActorKey.SelectedKeyName, PerceptionComponent->GetClosestEnemy());
		}
	}
	Super::TickNode(OwnerComp,NodeMemory,DeltaSeconds);
}
