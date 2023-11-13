#pragma once

#include "Platforms/BasePlatform.h"
#include "FallingPlatform.generated.h"

UCLASS()
class TMS_PLATFORMER_API AFallingPlatform : public ABasePlatform
{
	GENERATED_BODY()

public:
	AFallingPlatform();

protected:
	void BeginPlay() override;
	
	FTimerHandle TimerHandle;

	UPROPERTY(EditInstanceOnly)
	float lifeSpan = 5.0f;

	UPROPERTY(EditInstanceOnly)
	float respawnSpan = 5.0f;
	
private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void StartLifeSpan();

	UFUNCTION()
	void StartRespawnSpan();
};