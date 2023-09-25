// Fill out your copyright notice in the Description page of Project Settings.


#include "Platforms/HightJumpPlatform.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


AHightJumpPlatform::AHightJumpPlatform()
{
	StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	StaticMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
}

void AHightJumpPlatform::BeginPlay()
{
	Super::BeginPlay();
	StaticMesh->OnComponentHit.AddDynamic(this, &AHightJumpPlatform::OnHit);
}

void AHightJumpPlatform::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
                               UPrimitiveComponent* OtherComponent,
                               FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Hited"));

	const auto Character = Cast<ACharacter>(OtherActor);
	auto const CharacterMovement = Character->GetComponentByClass<UCharacterMovementComponent>();

	if (!GetWorld() || !Character || !CharacterMovement) return;
	FVector JumpVector = FVector::UpVector*JumpForce;
	CharacterMovement->Velocity.Z = 0;
	CharacterMovement->AddImpulse(JumpVector);
}
