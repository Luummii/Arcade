#include "EnemySpawnComponent_CPP.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "../Enemy/EnemyPawn_CPP.h"

void UEnemySpawnComponent_CPP::BeginPlay()
{
	Super::BeginPlay();
	Random.GenerateNewSeed();

	EnemySpawnInfos.Add(FEnemySpawnInfo(FVector(500.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f), 10, 1.0f));
	EnemySpawnInfos.Add(FEnemySpawnInfo(FVector(230.0f, 10.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f), 20, 1.0f));
	EnemySpawnInfos.Add(FEnemySpawnInfo(FVector(-30.0f, 20.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f), 30, 1.0f));
	EnemySpawnInfos.Add(FEnemySpawnInfo(FVector(140.0f, 30.0f, 450.0f), FRotator(0.0f, 0.0f, 0.0f), 40, 1.0f));
	EnemySpawnInfos.Add(FEnemySpawnInfo(FVector(250.0f, 40.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f), 50, 1.0f));
	EnemySpawnInfos.Add(FEnemySpawnInfo(FVector(360.0f, 50.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f), 60, 1.0f));
	EnemySpawnInfos.Add(FEnemySpawnInfo(FVector(470.0f, 60.0f, 120.0f), FRotator(0.0f, 0.0f, 0.0f), 70, 1.0f));
	EnemySpawnInfos.Add(FEnemySpawnInfo(FVector(580.0f, 70.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f), 80, 1.0f));
	EnemySpawnInfos.Add(FEnemySpawnInfo(FVector(690.0f, 80.0f, 40.0f), FRotator(0.0f, 0.0f, 0.0f), 90, 1.0f));
	EnemySpawnInfos.Add(FEnemySpawnInfo(FVector(-100.0f, 90.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f), 100, 1.0f));

	StartSpawnStage();

	UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));
}

void UEnemySpawnComponent_CPP::StartSpawnStage()
{
	SpawnStage = EnemySpawnInfos[Random.RandRange(0, EnemySpawnInfos.Num() - 1)];
	EnemiesSpawned = 0;
	SpawnEnemy();
	float ChangeStageTime = Random.RandRange(StageMinDelay, StageMaxDelay);
	GetWorld()->GetTimerManager().SetTimer(EnemySpawnTimer, this, &UEnemySpawnComponent_CPP::StartSpawnStage, ChangeStageTime, false);
}

void UEnemySpawnComponent_CPP::SpawnEnemy()
{
	FActorSpawnParameters SpawnParameters;
	GetWorld()->SpawnActor<AEnemyPawn_CPP>(SpawnStage.Location, SpawnStage.Rotation, SpawnParameters);

	EnemiesSpawned++;

	if (EnemiesSpawned < SpawnStage.NumOfEnemies)
	{
		GetWorld()->GetTimerManager().SetTimer(EnemySpawnTimer, this, &UEnemySpawnComponent_CPP::SpawnEnemy, SpawnStage.SpawnDelay, false);
	}
}
