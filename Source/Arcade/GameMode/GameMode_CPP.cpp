#include "GameMode_CPP.h"
#include "../Ships/PlayerShip_CPP.h"
#include "../Components/EnemySpawnComponent_CPP.h"
#include "ConstructorHelpers.h"

AGameMode_CPP::AGameMode_CPP()
{
  DefaultPawnClass = APlayerShip_CPP::StaticClass();
  EnemySpawnComponent = CreateDefaultSubobject<UEnemySpawnComponent_CPP>(TEXT("EnemySpawnComponent"));
  // static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/PlayerShip/PlayerShip_BP"));
  // DefaultPawnClass = PlayerPawnClassFinder.Class;
}
