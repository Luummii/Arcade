#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "GameMode_CPP.generated.h"

class UEnemySpawnComponent_CPP;

UCLASS()
class ARCADE_API AGameMode_CPP : public AGameMode
{
	GENERATED_BODY()

public:
	AGameMode_CPP();

private:
	UEnemySpawnComponent_CPP *EnemySpawnComponent = nullptr;
};
