#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShootComponent_CPP.generated.h"

USTRUCT()
struct FShootInfo
{
	GENERATED_USTRUCT_BODY()

public:
	FShootInfo(FVector __Offset, float __Angle, float __Damage) : Offset(__Offset), Angle(__Angle), Damage(__Damage) {}
	FShootInfo() {}

public:
	FVector Offset;
	float Angle;
	float Damage;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
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
	float ShootPeriod = .1f;

private:
	FTimerHandle ShootingTimer;
	TArray<FShootInfo> ShootInfos;
	float Damage = 0.0f;
};