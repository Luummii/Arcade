#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemySpawnComponent_CPP.generated.h"

USTRUCT()
struct FEnemySpawnInfo
{
	GENERATED_BODY()

public:
	FEnemySpawnInfo(FVector __Location, FRotator __Rotation, int __NumOfEnemies, float __SpawnDelay) : Location(__Location), Rotation(__Rotation), NumOfEnemies(__NumOfEnemies), SpawnDelay(__SpawnDelay) {}
	FEnemySpawnInfo() {}

public:
	FVector Location;
	FRotator Rotation;
	int NumOfEnemies;
	float SpawnDelay;
};

UCLASS()
class ARCADE_API UEnemySpawnComponent_CPP : public UActorComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

protected:
	void StartSpawnStage();
	void SpawnEnemy();

private:
	TArray<FEnemySpawnInfo> EnemySpawnInfos;
	float StageMinDelay = 5.0f;
	float StageMaxDelay = 10.0f;

protected:
	FEnemySpawnInfo SpawnStage;
	FTimerHandle ChangeStageTimer;
	FTimerHandle EnemySpawnTimer;
	FRandomStream Random;
	int EnemiesSpawned;
};
