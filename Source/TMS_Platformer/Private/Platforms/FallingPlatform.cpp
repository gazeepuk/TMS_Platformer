// Fill out your copyright notice in the Description page of Project Settings.


#include "Platforms/FallingPlatform.h"
#include "GameFramework/Character.h"
#include "TimerManager.h"

AFallingPlatform::AFallingPlatform()
{
	StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	StaticMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
}

void AFallingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StaticMesh->OnComponentHit.AddDynamic(this, &AFallingPlatform::OnHit);
}

void AFallingPlatform::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
                             FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Hited"));

	if( !GetWorld() || !OtherActor || !Cast<ACharacter>(OtherActor)) return;

	GetWorldTimerManager().SetTimer(TimerHandle, this, &AFallingPlatform::StartLifeSpan,lifeSpan,false);
}

void AFallingPlatform::StartLifeSpan()
{
	Destroy();
}
