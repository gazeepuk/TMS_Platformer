#pragma once

#include "Platforms/BasePlatform.h"
#include "HightJumpPlatform.generated.h"

UCLASS()
class TMS_PLATFORMER_API AHightJumpPlatform : public ABasePlatform
{
	GENERATED_BODY()

public:
	AHightJumpPlatform();

protected:
	void BeginPlay() override;
	
	UPROPERTY(EditInstanceOnly)
	double JumpForce;

private:
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
};