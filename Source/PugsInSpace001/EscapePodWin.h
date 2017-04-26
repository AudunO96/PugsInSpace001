// Coded by Audun Olsen and Henrik Engenes 2016/17

#pragma once

#include "GameFramework/Actor.h"
#include "PugGameInstance.h"
#include "EscapePodWin.generated.h"

UCLASS()
class PUGSINSPACE001_API AEscapePodWin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEscapePodWin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UShapeComponent* CollisionBox = nullptr;

	UFUNCTION()
		void WinCondition(bool BoolVal);

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
			UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	bool CanWin = false;

};