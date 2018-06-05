#include "MoveComponent_CPP.h"

UMoveComponent_CPP::UMoveComponent_CPP()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMoveComponent_CPP::BeginPlay()
{
	Super::BeginPlay();
}

void UMoveComponent_CPP::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (LeftMove)
	{
		FVector ActorLocation = GetOwner()->GetActorLocation();
		ActorLocation.Y = ActorLocation.Y - SpeedMove;
		GetOwner()->SetActorLocation(ActorLocation);
	}
	if (RightMove)
	{
		FVector ActorLocation = GetOwner()->GetActorLocation();
		ActorLocation.Y = ActorLocation.Y + SpeedMove;
		GetOwner()->SetActorLocation(ActorLocation);
	}
	if (ForwardMove)
	{
		FVector ActorLocation = GetOwner()->GetActorLocation();
		ActorLocation.X = ActorLocation.X + SpeedMove;
		GetOwner()->SetActorLocation(ActorLocation);
	}
	if (BackMove)
	{
		FVector ActorLocation = GetOwner()->GetActorLocation();
		ActorLocation.X = ActorLocation.X - SpeedMove;
		GetOwner()->SetActorLocation(ActorLocation);
	}
}

void UMoveComponent_CPP::OnLeftMove()
{
	LeftMove = !LeftMove;
}

void UMoveComponent_CPP::OnRightMove()
{
	RightMove = !RightMove;
}

void UMoveComponent_CPP::OnForwardMove()
{
	ForwardMove = !ForwardMove;
}

void UMoveComponent_CPP::OnBackMove()
{
	BackMove = !BackMove;
}
