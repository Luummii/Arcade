#include "GameMode_CPP.h"
#include "../Player/PlayerShip_CPP.h"
#include "ConstructorHelpers.h"

AGameMode_CPP::AGameMode_CPP()
{
  DefaultPawnClass = APlayerShip_CPP::StaticClass();
  // static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/PlayerShip/PlayerShip_BP"));
  // DefaultPawnClass = PlayerPawnClassFinder.Class;
}
