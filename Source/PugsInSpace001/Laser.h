// Coded by Audun Olsen and Henrik Engenes 2016/17

#pragma once

#include "GameFramework/Actor.h"
#include "LaserCatoid.h"
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


	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
			UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult &SweepResult);

	UShapeComponent* CollisionBox = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pointer")
		FVector laserPoint;

	int lifeSpan;

	FVector velocity;

	
};
