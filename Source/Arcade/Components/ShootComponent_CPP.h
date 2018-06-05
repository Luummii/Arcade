#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShootComponent_CPP.generated.h"

class AProjectile_CPP;

UCLASS()
class ARCADE_API UShootComponent_CPP : public UActorComponent
{
	GENERATED_BODY()

public:
	UShootComponent_CPP();

protected:
	virtual void BeginPlay() override;

public:
	void StartShooting();
	void StopShooting();

private:
	void Shoot();

public:
	float ShootPeriod;

private:
	FTimerHandle ShootingTimer;
};