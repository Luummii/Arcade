#include "PlayerPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	// Он же коллайдер
	PlayerPawnCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("PlayerPawnCollision"));
	SetRootComponent(PlayerPawnCollision);

	// Моделька корабля
	PlayerPawnMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerPawnMesh"));
	// Можно просто указать RootComponent и выше при установке тоже прим. RootComponent = PlayerPawnCollision
	PlayerPawnMesh->SetupAttachment(GetRootComponent());
}

void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerPawn::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
