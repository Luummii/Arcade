#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShootComponent_CPP.generated.h"

class AProjectile_CPP;

USTRUCT()
struct FShootInfo
{
	GENERATED_USTRUCT_BODY()

public:
	FShootInfo(FVector __Offset, float __Angle) : Offset(__Offset), Angle(__Angle) {}
	FShootInfo() : Offset(FVector(0.0f, 0.0f, 0.0f)), Angle(0.0f) {}

public:
	FVector Offset;
	float Angle;
};

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
	void GenerateStruct(FVector Offset, float Angle);

public:
	float ShootPeriod;

private:
	FTimerHandle ShootingTimer;
	TArray<FShootInfo> ShootInfos;
};