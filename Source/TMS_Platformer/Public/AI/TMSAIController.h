// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TMSAIController.generated.h"

class UTMSAIPerceptionComponent;

UCLASS()
class TMS_PLATFORMER_API ATMSAIController : public AAIController
{
	GENERATED_BODY()
public:
	ATMSAIController();
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UTMSAIPerceptionComponent* TMSAIPerceptionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FName FocusOnKeyName = "EnemyActor";
	
	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float DeltaSeconds) override;

private:
	AActor* GetFocusOnActor();
};
