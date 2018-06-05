#include "PlayerShip_CPP.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
#include "ConstructorHelpers.h"
#include "../Components/ShootComponent_CPP.h"

APlayerShip_CPP::APlayerShip_CPP()
{
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	RootComponent = Collision;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collision, NAME_None);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/Assets/Models/ship.ship'"));
	UStaticMesh *Asset = MeshAsset.Object;
	Mesh->SetStaticMesh(Asset);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->AddLocalTransform(FTransform(FVector(-300.0f, 0.0f, 600.0f)));
	Camera->AddLocalRotation(FRotator(-70.0f, 0.0f, 0.0f));

	ShootComponent = CreateDefaultSubobject<UShootComponent_CPP>(TEXT("ShootComponent"));
}

void APlayerShip_CPP::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerShip_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerShip_CPP::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindTouch(IE_Pressed, this, &APlayerShip_CPP::OnPressed);
	InputComponent->BindTouch(IE_Repeat, this, &APlayerShip_CPP::OnMove);
}

void APlayerShip_CPP::PossessedBy(AController *NewController)
{
	//PlayerController = Cast<APlayerController>(NewController); см. подсказку в определении
}

void APlayerShip_CPP::OnPressed(ETouchIndex::Type Index, FVector Location)
{
	TouchLocation = FVector2D(Location.X, Location.Y);
}

void APlayerShip_CPP::OnMove(ETouchIndex::Type Index, FVector Location)
{
	FVector2D TouchDeltaMove = FVector2D(TouchLocation.X - Location.X, TouchLocation.Y - Location.Y);

	TouchDeltaMove = TouchDeltaMove * TouchMoveSensivity;

	FVector NewLocation = GetActorLocation();
	NewLocation.X = FMath::Clamp(NewLocation.X + TouchDeltaMove.Y, -MoveLimit.Y, MoveLimit.Y);
	NewLocation.Y = FMath::Clamp(NewLocation.Y + TouchDeltaMove.X * -1.f, -MoveLimit.X, MoveLimit.X);

	SetActorLocation(NewLocation);
	TouchLocation = FVector2D(Location.X, Location.Y);
}
