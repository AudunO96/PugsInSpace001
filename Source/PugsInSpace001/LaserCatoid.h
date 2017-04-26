// Coded by Audun Olsen and Henrik Engenes 2016/17

#pragma once

#include "GameFramework/Character.h"
#include "LaserCatoid.generated.h"

UCLASS()
class PUGSINSPACE001_API ALaserCatoid : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALaserCatoid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UShapeComponent* CollisionBox = nullptr;

	
	
};
