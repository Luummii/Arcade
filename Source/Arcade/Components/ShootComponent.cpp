#include "ShootComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "../Actors/ShootProjectile.h"

UShootComponent::UShootComponent() : ShootPeriod(1.0f)
{
}

void UShootComponent::BeginPlay()
{
	Super::BeginPlay();
	StartShooting();
}

void UShootComponent::StartShooting()
{
	// Дескриптор, для ОП, чтбы понятно было какой таймер работает и над чем
	// Класс, где запускается
	// Метод, который нужно запусить
	// Интервал
	// Зедаржка перед первым запуском
	GetWorld()->GetTimerManager().SetTimer(ShootingTimer, this, &UShootComponent::Shoot, ShootPeriod, true, ShootPeriod);
}

void UShootComponent::StopShooting()
{
	GetWorld()->GetTimerManager().ClearTimer(ShootingTimer);
}

void UShootComponent::Shoot()
{
	UE_LOG(LogTemp, Warning, TEXT("Shoot"));

	// FTransform SpawnTransform;
	// SpawnTransform.SetLocation(GetOwner()->GetActorLocation());

	FVector Location = GetOwner()->GetActorLocation();
	FRotator Rotation = GetOwner()->GetActorRotation();
	//Rotation.Add(0.0f, 5.0f, 0.0f);
	FActorSpawnParameters SpawnParameters;

	GetWorld()->SpawnActor<AShootProjectile>(ProjectileClass, Location, Rotation, SpawnParameters);
}