#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn_CPP.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class APlayerController;

UCLASS()
class ARCADE_API APlayerPawn_CPP : public APawn
{
	GENERATED_BODY()

public:
	APlayerPawn_CPP();

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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerPawn")
	UBoxComponent *Collision = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerPawn")
	UStaticMeshComponent *Mesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerPawn")
	USpringArmComponent *SpringArm = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerPawn")
	UCameraComponent *Camera = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "PlayerPawn")
	float TouchMoveSensivity;
};
