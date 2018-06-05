#include "PlayerShip_CPP.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"
#include "ConstructorHelpers.h"
#include "../Components/ShootComponent_CPP.h"
#include "../Components/MoveComponent_CPP.h"

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
	MoveComponent = CreateDefaultSubobject<UMoveComponent_CPP>(TEXT("MoveComponent"));
}

void APlayerShip_CPP::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerShip_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerShip_CPP::PossessedBy(AController *NewController)
{
	//PlayerController = Cast<APlayerController>(NewController); см. подсказку в определении
}

void APlayerShip_CPP::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction(TEXT("LeftMove"), IE_Pressed, MoveComponent, &UMoveComponent_CPP::OnLeftMove);
	InputComponent->BindAction(TEXT("LeftMove"), IE_Released, MoveComponent, &UMoveComponent_CPP::OnLeftMove);

	InputComponent->BindAction(TEXT("RightMove"), IE_Pressed, MoveComponent, &UMoveComponent_CPP::OnRightMove);
	InputComponent->BindAction(TEXT("RightMove"), IE_Released, MoveComponent, &UMoveComponent_CPP::OnRightMove);

	InputComponent->BindAction(TEXT("ForwardMove"), IE_Pressed, MoveComponent, &UMoveComponent_CPP::OnForwardMove);
	InputComponent->BindAction(TEXT("ForwardMove"), IE_Released, MoveComponent, &UMoveComponent_CPP::OnForwardMove);

	InputComponent->BindAction(TEXT("BackMove"), IE_Pressed, MoveComponent, &UMoveComponent_CPP::OnBackMove);
	InputComponent->BindAction(TEXT("BackMove"), IE_Released, MoveComponent, &UMoveComponent_CPP::OnBackMove);

	InputComponent->BindAction(TEXT("Fire"), IE_Pressed, ShootComponent, &UShootComponent_CPP::StartShooting);
	InputComponent->BindAction(TEXT("Fire"), IE_Released, ShootComponent, &UShootComponent_CPP::StopShooting);
}