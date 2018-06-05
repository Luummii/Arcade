#include "GameMode_CPP.h"
#include "../Player/PlayerShip_CPP.h"

AGameMode_CPP::AGameMode_CPP()
{
  DefaultPawnClass = APlayerShip_CPP::StaticClass();
}
