// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "LevelDoor.h"
#include "ItemPickups.h"
#include "EscapePodWin.h"
#include "DamageVolume.h"
#include "ElevatorFloor.h"
#include "StartElevator.h"
#include "HammerCat.h"
#include "PugCharacter.generated.h"

UCLASS()
class PUGSINSPACE001_API APugCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APugCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//frem og tilbake (w, s)
	UFUNCTION()
		void MoveForward(float Val);
	UFUNCTION()
		void MoveSides(float Val);

	UFUNCTION()
		void Interact();

	UFUNCTION()
		void StartJump();

	UFUNCTION()
		void StopJump();

	UFUNCTION()
		void OnDeath();

	UFUNCTION()
		void Damage(float DamageAmount);

	UFUNCTION()
		void DeathComplete();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
		float Health = 1;

	UPROPERTY(EditAnywhere)
		float InvulTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Death")
		float DeathTime = 4.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
		TArray<bool> Pickups;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
		TArray<bool> EmptyPickups = {false, false, false};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Death")
		bool isDying = false;

	float InvulTimer;

	float DeathTimer;

	bool InvincibilityFrame;

	ALevelDoor* Door;

	AStartElevator* Switch;

	AElevatorFloor* Lift;

	AItemPickups* Item;

	AEscapePodWin* WinBox;

	ADamageVolume* DeathObj;

	AHammerCat* CatHam;

	void GetPickup(int32 PickupID);

	void SaveGame();
	void LoadGame();

	UPROPERTY(EditAnywhere, Category = "PlayerStart")
		FVector PlayerStart;
	 
};
