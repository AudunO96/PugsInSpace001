// Coded by Audun Olsen and Henrik Engenes 2016/17

#pragma once

#include "GameFramework/Actor.h"
#include "Laser.generated.h"

UCLASS()
class PUGSINSPACE001_API ALaser : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaser();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
