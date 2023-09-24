// Fill out your copyright notice in the Description page of Project Settings.


#include "Platforms/BasePlatform.h"

ABasePlatform::ABasePlatform()
{
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	SetRootComponent(StaticMesh);
}

