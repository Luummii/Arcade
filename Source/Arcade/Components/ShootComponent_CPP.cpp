#include "ShootComponent_CPP.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "../Projectile/Projectile_CPP.h"

UShootComponent_CPP::UShootComponent_CPP() : ShootPeriod(1.0f)
{
}

void UShootComponent_CPP::BeginPlay()
{
	Super::BeginPlay();
	StartShooting();
}

void UShootComponent_CPP::StartShooting()
{
	// Дескриптор, для ОП, чтбы понятно было какой таймер работает и над чем
	// Класс, где запускается
	// Метод, который нужно запусить
	// Интервал
	// Зедаржка перед первым запуском
	GetWorld()->GetTimerManager().SetTimer(ShootingTimer, this, &UShootComponent_CPP::Shoot, ShootPeriod, true, ShootPeriod);
}

void UShootComponent_CPP::StopShooting()
{
	GetWorld()->GetTimerManager().ClearTimer(ShootingTimer);
}

void UShootComponent_CPP::Shoot()
{
	UE_LOG(LogTemp, Warning, TEXT("Shoot"));

	// FTransform SpawnTransform;
	// SpawnTransform.SetLocation(GetOwner()->GetActorLocation());

	FVector Location = GetOwner()->GetActorLocation();
	FRotator Rotation = GetOwner()->GetActorRotation();
	//Rotation.Add(0.0f, 5.0f, 0.0f);
	FActorSpawnParameters SpawnParameters;

	GetWorld()->SpawnActor<AProjectile_CPP>(Location, Rotation, SpawnParameters);
}
