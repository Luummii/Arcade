#include "PlayerPawn_CPP.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

APlayerPawn_CPP::APlayerPawn_CPP()
{
	PrimaryActorTick.bCanEverTick = true;

	// Он же коллайдер
	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	SetRootComponent(Collision);

	// Моделька корабля
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());

	// Рука камеры
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	// Камера
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	UE_LOG(LogTemp, Warning, TEXT("TEST"));
}

void APlayerPawn_CPP::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerPawn_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerPawn_CPP::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
