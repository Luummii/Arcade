#include "EnemySpawnComponent_CPP.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "../Ships/EnemyShip_CPP.h"

void UEnemySpawnComponent_CPP::BeginPlay()
{
	Super::BeginPlay();
	Random.GenerateNewSeed();

	EnemySpawnInfos.Add(FEnemySpawnInfo(FVector(500.0f, -300.0f, 0.0f), FRotator(0.0f, 90.0f, 0.0f), 3, 1.5f));
	//EnemySpawnInfos.Add(FEnemySpawnInfo(FVector(530.0f, 300.0f, 0.0f), FRotator(0.0f, 90.0f, 0.0f), 2, 1.5f));
	//EnemySpawnInfos.Add(FEnemySpawnInfo(FVector(630.0f, 300.0f, 0.0f), FRotator(0.0f, 90.0f, 0.0f), 3, 1.5f));
	//EnemySpawnInfos.Add(FEnemySpawnInfo(FVector(640.0f, -300.0f, 0.0f), FRotator(0.0f, 90.0f, 0.0f), 4, 1.0f));
	StartSpawnStage();
}

void UEnemySpawnComponent_CPP::StartSpawnStage()
{
	SpawnStage = EnemySpawnInfos[Random.RandRange(0, EnemySpawnInfos.Num() - 1)];
	EnemiesSpawned = 0;
	float ChangeStageTime = Random.RandRange(StageMinDelay, StageMaxDelay);
	GetWorld()->GetTimerManager().SetTimer(ChangeStageTimer, this, &UEnemySpawnComponent_CPP::StartSpawnStage, ChangeStageTime, false);
	SpawnEnemy();
}

void UEnemySpawnComponent_CPP::SpawnEnemy()
{
	FActorSpawnParameters SpawnParameters;
	GetWorld()->SpawnActor<AEnemyShip_CPP>(SpawnStage.Location, SpawnStage.Rotation, SpawnParameters);

	EnemiesSpawned++;

	if (EnemiesSpawned < SpawnStage.NumOfEnemies)
	{
		GetWorld()->GetTimerManager().SetTimer(EnemySpawnTimer, this, &UEnemySpawnComponent_CPP::SpawnEnemy, SpawnStage.SpawnDelay, false);
	}
}
