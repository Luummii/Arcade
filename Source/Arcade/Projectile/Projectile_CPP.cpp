#include "Projectile_CPP.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ConstructorHelpers.h"
#include "GameFramework/DamageType.h"
#include "Kismet/GameplayStatics.h"

AProjectile_CPP::AProjectile_CPP()
{
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("ProjectileCollision"));
	RootComponent = Collision;
	//Collision->SetCollisionProfileName("Pawn");

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/Assets/Models/Projectile/Sphere.Sphere'"));
	UStaticMesh *Asset = MeshAsset.Object;
	Mesh->SetStaticMesh(Asset);
	Mesh->SetupAttachment(Collision, NAME_None);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AProjectile_CPP::BeginPlay()
{
	Super::BeginPlay();
	SetActorScale3D(FVector(0.1f, 0.1f, 0.1f));

	if (GetOwner())
	{
		UE_LOG(LogTemp, Warning, TEXT("GetOwner 1"));
		// UBoxComponent *OwnerCollision = GetOwner()->FindComponentByClass<UBoxComponent>();
		// Collision->IgnoreComponentWhenMoving(OwnerCollision, true);
		// OwnerCollision->IgnoreComponentWhenMoving(Collision, true);
		// Collision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}

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

	if (!GetOwner())
		return;
	APawn *PawnOwner = Cast<APawn>(GetOwner());

	if (!PawnOwner)
		return;
	AController *Instigator = PawnOwner->GetController();

	UGameplayStatics::ApplyDamage(OtherActor, Damage, Instigator, this, UDamageType::StaticClass());

	Destroy();
}
