// Coded by Audun Olsen and Henrik Engenes 2016/17

#pragma once

#include "GameFramework/Character.h"
#include "HammerCat.generated.h"

UCLASS()
class PUGSINSPACE001_API AHammerCat : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHammerCat();

	UPROPERTY(EditAnywhere, Category = Behavior)
		class UBehaviorTree *BotBehavior; 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void OnOverlapSense(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
		UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult &SweepResult);

	void OnOverlapEndSense(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	void OnOverlapMelee(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
		UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult &SweepResult);

	void OnOverlapEndMelee(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
