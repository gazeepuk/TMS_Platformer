// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasePlatform.generated.h"

UCLASS()
class TMS_PLATFORMER_API ABasePlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ABasePlatform();

protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* StaticMesh;
};
