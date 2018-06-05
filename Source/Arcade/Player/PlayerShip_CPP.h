#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerShip_CPP.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class APlayerController;
class UShootComponent_CPP;
class UMoveComponent_CPP;

UCLASS()
class ARCADE_API APlayerShip_CPP : public APawn
{
	GENERATED_BODY()

public:
	APlayerShip_CPP();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;
	// Как только пешка получает контроллер, то его можно тут передать в внутрь класса
	virtual void PossessedBy(AController *NewController) override;

protected:
	APlayerController *PlayerController;

private:
	UBoxComponent *Collision = nullptr;
	UStaticMeshComponent *Mesh = nullptr;
	UCameraComponent *Camera = nullptr;
	UShootComponent_CPP *ShootComponent = nullptr;
	UMoveComponent_CPP *MoveComponent = nullptr;
};
