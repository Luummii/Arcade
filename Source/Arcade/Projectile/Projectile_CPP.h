#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile_CPP.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class ARCADE_API AProjectile_CPP : public AActor
{
	GENERATED_BODY()

public:
	AProjectile_CPP();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	USphereComponent *Collision = nullptr;
	UStaticMeshComponent *Mesh = nullptr;
	float ProjectileSpeed = 500.0f;
	float Damage = 0.0f;

protected:
	UFUNCTION()
	void OnProjectileOverlap(UPrimitiveComponent *OpelappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 BodyIndex, bool Sweep, const FHitResult &Hit);
};