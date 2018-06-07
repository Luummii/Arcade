// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyPawn_CPP.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class APlayerController;
class UShootComponent_CPP;
class UMoveComponent_CPP;

UCLASS()
class ARCADE_API AEnemyPawn_CPP : public APawn
{
	GENERATED_BODY()

public:
	AEnemyPawn_CPP();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

protected:
	APlayerController *PlayerController;

private:
	UBoxComponent *Collision = nullptr;
	UCameraComponent *Camera = nullptr;
	UShootComponent_CPP *ShootComponent = nullptr;
	UMoveComponent_CPP *MoveComponent = nullptr;

	UStaticMeshComponent *ShipBody = nullptr;
	UStaticMeshComponent *Ship_windshield_usemtl_1 = nullptr;
	UStaticMeshComponent *Ship_windshield_usemtl_2 = nullptr;
	UStaticMeshComponent *Ship_red_mesh01_1 = nullptr;
	UStaticMeshComponent *ship_propulsion_usemtl_1 = nullptr;
	UStaticMeshComponent *ship_lights_2_mesh01_1 = nullptr;
	UStaticMeshComponent *ship_green__1 = nullptr;
	UStaticMeshComponent *ship_door_usemtl_2 = nullptr;
	UStaticMeshComponent *ship_door_usemtl_1 = nullptr;
	UStaticMeshComponent *ship_dash_usemtl_4 = nullptr;
	UStaticMeshComponent *ship_dash_usemtl_3 = nullptr;
	UStaticMeshComponent *ship_dash_usemtl_2 = nullptr;
	UStaticMeshComponent *ship_dash_usemtl_1 = nullptr;
	UStaticMeshComponent *ship_cushion_usemtl_1 = nullptr;
	UStaticMeshComponent *ship_couplers__1 = nullptr;
	UStaticMeshComponent *ship_cockpit2_usemtl_4 = nullptr;
	UStaticMeshComponent *ship_cockpit2_usemtl_3 = nullptr;
	UStaticMeshComponent *ship_cockpit2_usemtl_2 = nullptr;
	UStaticMeshComponent *ship_cockpit2_usemtl_1 = nullptr;
};
