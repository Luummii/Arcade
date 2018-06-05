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

private:
	void OnPressed(ETouchIndex::Type Index, FVector Location);
	void OnMove(ETouchIndex::Type Index, FVector Location);

protected:
	APlayerController *PlayerController;

private:
	float TouchMoveSensivity = 1.0f;
	FVector2D MoveLimit = FVector2D(500.0f, 600.0f);
	FVector2D TouchLocation;

	UBoxComponent *Collision = nullptr;
	UStaticMeshComponent *Mesh = nullptr;
	UCameraComponent *Camera = nullptr;
	UShootComponent_CPP *ShootComponent = nullptr;
};
