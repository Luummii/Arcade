#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class ARCADE_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	APlayerPawn();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerPawn")
	UBoxComponent *PlayerPawnCollision = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerPawn")
	UStaticMeshComponent *PlayerPawnMesh = nullptr;
};
