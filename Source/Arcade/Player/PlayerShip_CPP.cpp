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

	ShipBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipBody"));
	ShipBody->SetupAttachment(Collision, NAME_None);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetShipBody(TEXT("StaticMesh'/Game/Assets/Models/PlayerShip/Mesh/ship_body.ship_body'"));
	UStaticMesh *AssetShipBody = MeshAssetShipBody.Object;
	ShipBody->SetStaticMesh(AssetShipBody);

	Ship_windshield_usemtl_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ship_windshield_usemtl_1"));
	Ship_windshield_usemtl_1->SetupAttachment(Collision, NAME_None);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetShip_windshield_usemtl_1(TEXT("StaticMesh'/Game/Assets/Models/PlayerShip/Mesh/ship_windshield_usemtl_1.ship_windshield_usemtl_1'"));
	UStaticMesh *AssetShip_windshield_usemtl_1 = MeshAssetShip_windshield_usemtl_1.Object;
	Ship_windshield_usemtl_1->SetStaticMesh(AssetShip_windshield_usemtl_1);

	Ship_windshield_usemtl_2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ship_windshield_usemtl_2"));
	Ship_windshield_usemtl_2->SetupAttachment(Collision, NAME_None);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetShip_windshield_usemtl_2(TEXT("StaticMesh'/Game/Assets/Models/PlayerShip/Mesh/ship_windshield_usemtl_2.ship_windshield_usemtl_2'"));
	UStaticMesh *AssetShip_windshield_usemtl_2 = MeshAssetShip_windshield_usemtl_2.Object;
	Ship_windshield_usemtl_2->SetStaticMesh(AssetShip_windshield_usemtl_2);

	Ship_red_mesh01_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ship_red_mesh01_1"));
	Ship_red_mesh01_1->SetupAttachment(Collision, NAME_None);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetShip_red_mesh01_1(TEXT("StaticMesh'/Game/Assets/Models/PlayerShip/Mesh/ship_red_mesh01_1.ship_red_mesh01_1'"));
	UStaticMesh *AssetShip_red_mesh01_1 = MeshAssetShip_red_mesh01_1.Object;
	Ship_red_mesh01_1->SetStaticMesh(AssetShip_red_mesh01_1);

	ship_propulsion_usemtl_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ship_propulsion_usemtl_1"));
	ship_propulsion_usemtl_1->SetupAttachment(Collision, NAME_None);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetship_propulsion_usemtl_1(TEXT("StaticMesh'/Game/Assets/Models/PlayerShip/Mesh/ship_propulsion_usemtl_1.ship_propulsion_usemtl_1'"));
	UStaticMesh *Assetship_propulsion_usemtl_1 = MeshAssetship_propulsion_usemtl_1.Object;
	ship_propulsion_usemtl_1->SetStaticMesh(Assetship_propulsion_usemtl_1);

	ship_lights_2_mesh01_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ship_lights_2_mesh01_1"));
	ship_lights_2_mesh01_1->SetupAttachment(Collision, NAME_None);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetship_lights_2_mesh01_1(TEXT("StaticMesh'/Game/Assets/Models/PlayerShip/Mesh/ship_lights_2_mesh01_1.ship_lights_2_mesh01_1'"));
	UStaticMesh *Assetship_lights_2_mesh01_1 = MeshAssetship_lights_2_mesh01_1.Object;
	ship_lights_2_mesh01_1->SetStaticMesh(Assetship_lights_2_mesh01_1);

	ship_green__1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ship_green__1"));
	ship_green__1->SetupAttachment(Collision, NAME_None);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetship_green__1(TEXT("StaticMesh'/Game/Assets/Models/PlayerShip/Mesh/ship_green__1.ship_green__1'"));
	UStaticMesh *Assetship_green__1 = MeshAssetship_green__1.Object;
	ship_green__1->SetStaticMesh(Assetship_green__1);

	ship_door_usemtl_2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ship_door_usemtl_2"));
	ship_door_usemtl_2->SetupAttachment(Collision, NAME_None);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetship_door_usemtl_2(TEXT("StaticMesh'/Game/Assets/Models/PlayerShip/Mesh/ship_door_usemtl_2.ship_door_usemtl_2'"));
	UStaticMesh *Assetship_door_usemtl_2 = MeshAssetship_door_usemtl_2.Object;
	ship_door_usemtl_2->SetStaticMesh(Assetship_door_usemtl_2);

	ship_door_usemtl_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ship_door_usemtl_1"));
	ship_door_usemtl_1->SetupAttachment(Collision, NAME_None);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetship_door_usemtl_1(TEXT("StaticMesh'/Game/Assets/Models/PlayerShip/Mesh/ship_door_usemtl_1.ship_door_usemtl_1'"));
	UStaticMesh *Assetship_door_usemtl_1 = MeshAssetship_door_usemtl_1.Object;
	ship_door_usemtl_1->SetStaticMesh(Assetship_door_usemtl_1);

	ship_dash_usemtl_4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ship_dash_usemtl_4"));
	ship_dash_usemtl_4->SetupAttachment(Collision, NAME_None);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetship_dash_usemtl_4(TEXT("StaticMesh'/Game/Assets/Models/PlayerShip/Mesh/ship_dash_usemtl_4.ship_dash_usemtl_4'"));
	UStaticMesh *Assetship_dash_usemtl_4 = MeshAssetship_dash_usemtl_4.Object;
	ship_dash_usemtl_4->SetStaticMesh(Assetship_dash_usemtl_4);

	ship_dash_usemtl_3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ship_dash_usemtl_3"));
	ship_dash_usemtl_3->SetupAttachment(Collision, NAME_None);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetship_dash_usemtl_3(TEXT("StaticMesh'/Game/Assets/Models/PlayerShip/Mesh/ship_dash_usemtl_3.ship_dash_usemtl_3'"));
	UStaticMesh *Assetship_dash_usemtl_3 = MeshAssetship_dash_usemtl_3.Object;
	ship_dash_usemtl_3->SetStaticMesh(Assetship_dash_usemtl_3);

	ship_dash_usemtl_2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ship_dash_usemtl_2"));
	ship_dash_usemtl_2->SetupAttachment(Collision, NAME_None);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetship_dash_usemtl_2(TEXT("StaticMesh'/Game/Assets/Models/PlayerShip/Mesh/ship_dash_usemtl_2.ship_dash_usemtl_2'"));
	UStaticMesh *Assetship_dash_usemtl_2 = MeshAssetship_dash_usemtl_2.Object;
	ship_dash_usemtl_2->SetStaticMesh(Assetship_dash_usemtl_2);

	ship_dash_usemtl_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ship_dash_usemtl_1"));
	ship_dash_usemtl_1->SetupAttachment(Collision, NAME_None);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetship_dash_usemtl_1(TEXT("StaticMesh'/Game/Assets/Models/PlayerShip/Mesh/ship_dash_usemtl_1.ship_dash_usemtl_1'"));
	UStaticMesh *Assetship_dash_usemtl_1 = MeshAssetship_dash_usemtl_1.Object;
	ship_dash_usemtl_1->SetStaticMesh(Assetship_dash_usemtl_1);

	ship_cushion_usemtl_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ship_cushion_usemtl_1"));
	ship_cushion_usemtl_1->SetupAttachment(Collision, NAME_None);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetship_cushion_usemtl_1(TEXT("StaticMesh'/Game/Assets/Models/PlayerShip/Mesh/ship_cushion_usemtl_1.ship_cushion_usemtl_1'"));
	UStaticMesh *Assetship_cushion_usemtl_1 = MeshAssetship_cushion_usemtl_1.Object;
	ship_cushion_usemtl_1->SetStaticMesh(Assetship_cushion_usemtl_1);

	ship_couplers__1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ship_couplers__1"));
	ship_couplers__1->SetupAttachment(Collision, NAME_None);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetship_couplers__1(TEXT("StaticMesh'/Game/Assets/Models/PlayerShip/Mesh/ship_couplers__1.ship_couplers__1'"));
	UStaticMesh *Assetship_couplers__1 = MeshAssetship_couplers__1.Object;
	ship_couplers__1->SetStaticMesh(Assetship_couplers__1);

	ship_cockpit2_usemtl_4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ship_cockpit2_usemtl_4"));
	ship_cockpit2_usemtl_4->SetupAttachment(Collision, NAME_None);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetship_cockpit2_usemtl_4(TEXT("StaticMesh'/Game/Assets/Models/PlayerShip/Mesh/ship_cockpit2_usemtl_4.ship_cockpit2_usemtl_4'"));
	UStaticMesh *Assetship_cockpit2_usemtl_4 = MeshAssetship_cockpit2_usemtl_4.Object;
	ship_cockpit2_usemtl_4->SetStaticMesh(Assetship_cockpit2_usemtl_4);

	ship_cockpit2_usemtl_3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ship_cockpit2_usemtl_3"));
	ship_cockpit2_usemtl_3->SetupAttachment(Collision, NAME_None);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetship_cockpit2_usemtl_3(TEXT("StaticMesh'/Game/Assets/Models/PlayerShip/Mesh/ship_cockpit2_usemtl_3.ship_cockpit2_usemtl_3'"));
	UStaticMesh *Assetship_cockpit2_usemtl_3 = MeshAssetship_cockpit2_usemtl_3.Object;
	ship_cockpit2_usemtl_3->SetStaticMesh(Assetship_cockpit2_usemtl_3);

	ship_cockpit2_usemtl_2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ship_cockpit2_usemtl_2"));
	ship_cockpit2_usemtl_2->SetupAttachment(Collision, NAME_None);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetship_cockpit2_usemtl_2(TEXT("StaticMesh'/Game/Assets/Models/PlayerShip/Mesh/ship_cockpit2_usemtl_2.ship_cockpit2_usemtl_2'"));
	UStaticMesh *Assetship_cockpit2_usemtl_2 = MeshAssetship_cockpit2_usemtl_2.Object;
	ship_cockpit2_usemtl_2->SetStaticMesh(Assetship_cockpit2_usemtl_2);

	ship_cockpit2_usemtl_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ship_cockpit2_usemtl_1"));
	ship_cockpit2_usemtl_1->SetupAttachment(Collision, NAME_None);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAssetship_cockpit2_usemtl_1(TEXT("StaticMesh'/Game/Assets/Models/PlayerShip/Mesh/ship_cockpit2_usemtl_1.ship_cockpit2_usemtl_1'"));
	UStaticMesh *Assetship_cockpit2_usemtl_1 = MeshAssetship_cockpit2_usemtl_1.Object;
	ship_cockpit2_usemtl_1->SetStaticMesh(Assetship_cockpit2_usemtl_1);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->AddLocalTransform(FTransform(FVector(-300.0f, 0.0f, 600.0f)));
	Camera->AddLocalRotation(FRotator(-70.0f, 0.0f, 0.0f));

	ShootComponent = CreateDefaultSubobject<UShootComponent_CPP>(TEXT("ShootComponent"));
	MoveComponent = CreateDefaultSubobject<UMoveComponent_CPP>(TEXT("MoveComponent"));
}

void APlayerShip_CPP::BeginPlay()
{
	Super::BeginPlay();

	FRotator Rotation = GetActorRotation();
	Rotation.Add(0.0f, -90.0f, 0.0f);
	SetActorRotation(Rotation);
	SetActorScale3D(FVector(0.1f, 0.1f, 0.1f));
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