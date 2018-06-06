#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoveComponent_CPP.generated.h"

UCLASS()
class ARCADE_API UMoveComponent_CPP : public UActorComponent
{
	GENERATED_BODY()

public:
	UMoveComponent_CPP();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

public:
	void OnLeftMove();
	void OnRightMove();
	void OnForwardMove();
	void OnBackMove();

private:
	float SpeedMove = 5.0f;
	bool LeftMove = false;
	bool RightMove = false;
	bool ForwardMove = false;
	bool BackMove = false;
};
