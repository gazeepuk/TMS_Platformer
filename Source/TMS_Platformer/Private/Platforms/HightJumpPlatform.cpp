#include "Platforms/HightJumpPlatform.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

AHightJumpPlatform::AHightJumpPlatform()
{
	StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	StaticMesh->SetCollisionResponseToAllChannels(ECR_Block);
}

void AHightJumpPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (StaticMesh)
	{
		if (!StaticMesh->OnComponentHit.IsAlreadyBound(this, &AHightJumpPlatform::OnHit))
		{
			StaticMesh->OnComponentHit.AddDynamic(this, &AHightJumpPlatform::OnHit);
		}
	}
}

void AHightJumpPlatform::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	const auto Character = Cast<ACharacter>(OtherActor);
	auto const CharacterMovement = Character->GetComponentByClass<UCharacterMovementComponent>();

	if (!GetWorld() || !Character || !CharacterMovement)
	{
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Hited"));

	FVector JumpVector = FVector::UpVector*JumpForce;
	CharacterMovement->Velocity.Z = 0;
	CharacterMovement->AddImpulse(JumpVector);
}