#include "ShootProjectile.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h" // TODO проверить будет ли работать без этого

AShootProjectile::AShootProjectile() : ProjectileSpeed(1000.0f)
{
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("ProjectileCollision"));
	RootComponent = Collision;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	Mesh->SetupAttachment(Collision, NAME_None);
	Mesh->SetCollisionProfileName("NoCollision");
}

void AShootProjectile::BeginPlay()
{
	Super::BeginPlay();
}

void AShootProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalOffset(FVector(ProjectileSpeed * DeltaTime, 0.0f, 0.0f));
}
