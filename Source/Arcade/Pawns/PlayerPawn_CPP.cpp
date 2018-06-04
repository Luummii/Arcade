#include "PlayerPawn_CPP.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/InputComponent.h"
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

	InputComponent->BindTouch(IE_Pressed, this, &APlayerPawn_CPP::OnPressed);
	InputComponent->BindTouch(IE_Released, this, &APlayerPawn_CPP::OnReleased);
}

void APlayerPawn_CPP::OnPressed(ETouchIndex::Type Index, FVector TouchLocation)
{
	UE_LOG(LogTemp, Warning, TEXT("OnPressed"));
}

void APlayerPawn_CPP::OnReleased(ETouchIndex::Type Index, FVector TouchLocation)
{
	UE_LOG(LogTemp, Warning, TEXT("OnReleased"));
}
