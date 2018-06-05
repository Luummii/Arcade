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
	virtual void PossessedBy(AController *NewController) override;

	void OnPressed(ETouchIndex::Type Index, FVector Location);
	void OnMove(ETouchIndex::Type Index, FVector Location);

protected:
	APlayerController *PlayerController;
	FVector2D MoveLimit;

private:
	FVector2D TouchLocation;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerShip")
	UBoxComponent *Collision = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerShip")
	UStaticMeshComponent *Mesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerShip")
	UCameraComponent *Camera = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayerShip")
	float TouchMoveSensivity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerShip")
	UShootComponent_CPP *ShootComponent = nullptr;
};
