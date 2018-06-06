#include "Projectile_CPP.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"

AProjectile_CPP::AProjectile_CPP()
{
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("ProjectileCollision"));
	RootComponent = Collision;
	//Collision->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	Mesh->SetupAttachment(Collision, NAME_None);
	Mesh->SetCollisionProfileName("NoCollision");

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/Assets/Models/Projectile/Sphere.Sphere'"));
	UStaticMesh *Asset = MeshAsset.Object;
	Mesh->SetStaticMesh(Asset);
}

void AProjectile_CPP::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(0.1f, 0.1f, 0.1f));
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AProjectile_CPP::OnProjectileOverlap);
}

void AProjectile_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(FVector(ProjectileSpeed * DeltaTime, 0.0f, 0.0f));
}

void AProjectile_CPP::OnProjectileOverlap(UPrimitiveComponent *OpelappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 BodyIndex, bool Sweep, const FHitResult &Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("OnProjectileOverlap"));
}
