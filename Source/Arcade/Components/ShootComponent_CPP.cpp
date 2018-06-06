#include "ShootComponent_CPP.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "../Projectile/Projectile_CPP.h"

UShootComponent_CPP::UShootComponent_CPP()
{
	GenerateStruct(FVector(0.0f, 10.0f, 0.0f), 90.0f);
	GenerateStruct(FVector(10.0f, 20.0f, 0.0f), 60.0f);
	GenerateStruct(FVector(-10.0f, 20.0f, 0.0f), 120.0f);
}

void UShootComponent_CPP::BeginPlay()
{
	Super::BeginPlay();
}

void UShootComponent_CPP::StartShooting()
{
	// Дескриптор, для ОП, чтбы понятно было какой таймер работает и над чем
	// Класс, на котором запускается
	// Метод, который нужно запусить
	// Интервал
	// Зедаржка перед первым запуском
	GetWorld()->GetTimerManager().SetTimer(ShootingTimer, this, &UShootComponent_CPP::Shoot, ShootPeriod, true, 0.0f);
}

void UShootComponent_CPP::StopShooting()
{
	GetWorld()->GetTimerManager().ClearTimer(ShootingTimer);
}

void UShootComponent_CPP::GenerateStruct(FVector Offset, float Angle)
{
	FShootInfo ShootInfo(Offset, Angle);
	ShootInfos.Add(ShootInfo);
}

void UShootComponent_CPP::Shoot()
{
	// FTransform SpawnTransform;
	// SpawnTransform.SetLocation(GetOwner()->GetActorLocation());

	for (FShootInfo ShootInfo : ShootInfos)
	{
		FRotator Rotation = GetOwner()->GetActorRotation();
		FVector Location = GetOwner()->GetActorLocation() + Rotation.RotateVector(ShootInfo.Offset);
		Rotation.Add(0.0f, ShootInfo.Angle, 0.0f);
		FActorSpawnParameters SpawnParameters;
		GetWorld()->SpawnActor<AProjectile_CPP>(Location, Rotation, SpawnParameters);
	}
}
