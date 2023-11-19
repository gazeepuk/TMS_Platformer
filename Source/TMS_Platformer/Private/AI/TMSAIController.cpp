// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/TMSAIController.h"
#include "AI/AICharacter.h"
#include "AI/TMSAIPerceptionComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

ATMSAIController::ATMSAIController()
{
	TMSAIPerceptionComponent = CreateDefaultSubobject<UTMSAIPerceptionComponent>("AIPerceptionComponent");
	SetPerceptionComponent(*TMSAIPerceptionComponent);
}

void ATMSAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	const AAICharacter* TMSCharacter = Cast<AAICharacter>(InPawn);
	if(!TMSCharacter)
	{
		return;
	}
	RunBehaviorTree(TMSCharacter->BehaviorTreeAsset);
}

void ATMSAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	const auto AimActor = GetFocusOnActor();
	SetFocus(AimActor);
}

AActor* ATMSAIController::GetFocusOnActor()
{
	if(!GetBlackboardComponent())
	{
		return nullptr;
	}
	return Cast<AActor>(GetBlackboardComponent()->GetValueAsObject(FocusOnKeyName));
}
