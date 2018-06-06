#include "EnemySpawnComponent_CPP.h"
#include "Engine/World.h"
#include "TimerManager.h"

void UEnemySpawnComponent_CPP::BeginPlay()
{
	Super::BeginPlay();

	SpawnStage = FEnemySpawnInfo(FVector(0.0f, 0.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f), 10, 1.0f);

	StartSpawnStage();

	UE_LOG(LogTemp, Warning, TEXT("SpawnEnemy"));
}

void UEnemySpawnComponent_CPP::StartSpawnStage()
{
	GetWorld()->GetTimerManager().SetTimer(EnemySpawnTimer, this, &UEnemySpawnComponent_CPP::SpawnEnemy, SpawnStage.SpawnDelay, true, SpawnStage.SpawnDelay);
}

void UEnemySpawnComponent_CPP::SpawnEnemy()
{
	UE_LOG(LogTemp, Warning, TEXT("SpawnEnemy"));

	FActorSpawnParameters SpawnParameters;
	GetWorld()->SpawnActor<APawn>(SpawnStage.Location, SpawnStage.Rotation, SpawnParameters);

	EnemiesSpawned++;

	if (EnemiesSpawned >= SpawnStage.NumOfEnemies)
	{
		GetWorld()->GetTimerManager().ClearTimer(EnemySpawnTimer);
	}
}
