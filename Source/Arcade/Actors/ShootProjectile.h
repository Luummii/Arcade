#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShootProjectile.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class ARCADE_API AShootProjectile : public AActor
{
	GENERATED_BODY()

public:
	AShootProjectile();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ShootProjectile")
	USphereComponent *Collision = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ShootProjectile")
	UStaticMeshComponent *Mesh = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ShootProjectile")
	float ProjectileSpeed;
};
