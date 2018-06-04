#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShootComponent.generated.h"

class AShootProjectile;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ARCADE_API UShootComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UShootComponent();

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
	TSubclassOf<AShootProjectile> ProjectileClass;

private:
	FTimerHandle ShootingTimer;
};
