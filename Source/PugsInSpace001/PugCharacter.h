// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "LevelDoor.h"
#include "ItemPickups.h"
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
		void Damage(int DamageAmount);

	UPROPERTY(EditAnywhere)
		int32 Health = 5;

	UPROPERTY(EditAnywhere)
		float InvulTime;

	UPROPERTY(EditAnywhere, Category = "Items")
		TArray<bool> Pickups;

	float InvulTimer;

	bool InvincibilityFrame;

	ALevelDoor* Door;

	AItemPickups* Item;

	void GetPickup(int32 PickupID);

	void SaveGame();
	void LoadGame();
};
