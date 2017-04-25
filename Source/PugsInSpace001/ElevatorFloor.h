// Coded by Audun Olsen and Henrik Engenes 2016/17

#pragma once

#include "GameFramework/Actor.h"
#include "ElevatorFloor.generated.h"

UCLASS()
class PUGSINSPACE001_API AElevatorFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AElevatorFloor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool toggleSwitch = false;

	bool isMoving = false;
	bool goDown = false;

	float maxZ = 25.0;
	float minZ = -575.5;

	UPROPERTY(EditAnywhere)
		float speed = 0.0;

	UFUNCTION()
		void MoveElevator(bool toggle);

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
			UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


	UShapeComponent* CollisionBox = nullptr;
	
};
