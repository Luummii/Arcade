#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShootComponent_CPP.generated.h"

class AProjectile_CPP;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ARCADE_API UShootComponent_CPP : public UActorComponent
{
	GENERATED_BODY()

public:
	UShootComponent_CPP();

protected:
	virtual void BeginPlay() override;
	void Shoot();

public:
	UFUNCTION(BlueprintCallable, Category = "ShootComponent")
	void StartShooting();

	UFUNCTION(BlueprintCallable, Category = "ShootComponent")
	void StopShooting();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ShootComponent")
	float ShootPeriod;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ShootComponent")
	TSubclassOf<AProjectile_CPP> Projectile_BP;

private:
	FTimerHandle ShootingTimer;
};