// Coded by Audun Olsen and Henrik Engenes 2016/17

#pragma once

#include "GameFramework/Character.h"
#include "PugCharacter.h"
#include "Laser.h"
#include "LaserCatoid.generated.h"

UCLASS()
class PUGSINSPACE001_API ALaserCatoid : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALaserCatoid();

	UPROPERTY(EditAnywhere, Category = "Behavior")
	class UBehaviorTree *BotBehavior;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
			UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult &SweepResult);

	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UShapeComponent* CollisionBox = nullptr;

	UPROPERTY(EditAnywhere, Category = "Shooting")
		TSubclassOf<class ALaser> Laser_BP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pointer")
	FVector pointLaser;

	FVector displacement;

	int recharge = 80;

	bool tracking = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
		bool isAttacking;
	
	
};
