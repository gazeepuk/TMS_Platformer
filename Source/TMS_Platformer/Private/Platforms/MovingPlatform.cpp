// Fill out your copyright notice in the Description page of Project Settings.


#include "Platforms/MovingPlatform.h"
#include "Components/InterpToMovementComponent.h"

AMovingPlatform::AMovingPlatform()
{
	
	InterpToMovementComponent = CreateDefaultSubobject<UInterpToMovementComponent>("InterpToMovementComponent");
	InterpToMovementComponent->BehaviourType = EInterpToBehaviourType::PingPong;
}
