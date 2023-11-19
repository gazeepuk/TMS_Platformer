// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AICharacter.h"

#include "BrainComponent.h"
#include "AI/TMSAIController.h"
#include "GameFramework/CharacterMovementComponent.h"

AAICharacter::AAICharacter(const FObjectInitializer& ObjInit)
: Super(ObjInit)
{
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	AIControllerClass = ATMSAIController::StaticClass();

	bUseControllerRotationYaw = false;
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
		GetCharacterMovement()->RotationRate = FRotator(0, 200, 0);
	}
}

void AAICharacter::OnDeath()
{
	Super::OnDeath();

	const auto TMSController =  Cast<AAIController>(Controller);
	if(TMSController && TMSController->BrainComponent)
	{
		TMSController->BrainComponent->Cleanup();
	}
}