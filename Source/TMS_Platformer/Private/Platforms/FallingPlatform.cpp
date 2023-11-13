#include "Platforms/FallingPlatform.h"
#include "GameFramework/Character.h"
#include "TimerManager.h"

AFallingPlatform::AFallingPlatform()
{
	StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	StaticMesh->SetCollisionResponseToAllChannels(ECR_Block);
}

void AFallingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (StaticMesh)
	{
		if (!StaticMesh->OnComponentHit.IsAlreadyBound(this, &AFallingPlatform::OnHit))
		{
			StaticMesh->OnComponentHit.AddDynamic(this, &AFallingPlatform::OnHit);
		}
	}
}

void AFallingPlatform::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if(!GetWorld() || !Cast<ACharacter>(OtherActor))
	{
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Hited"));

	GetWorldTimerManager().SetTimer(TimerHandle, this, &AFallingPlatform::StartLifeSpan, lifeSpan, false);
}

void AFallingPlatform::StartLifeSpan()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);

	GetWorldTimerManager().ClearTimer(TimerHandle);
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AFallingPlatform::StartRespawnSpan, respawnSpan, false);
}

void AFallingPlatform::StartRespawnSpan()
{
	GetWorldTimerManager().ClearTimer(TimerHandle);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
}