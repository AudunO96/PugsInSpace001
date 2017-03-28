// Fill out your copyright notice in the Description page of Project Settings.

#include "PugsInSpace001.h"
#include "PugCharacter.h"


// Sets default values
APugCharacter::APugCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APugCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APugCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APugCharacter::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveForward", this, &APugCharacter::MoveForward);
	InputComponent->BindAxis("MoveSides", this, &APugCharacter::MoveSides);

	InputComponent->BindAction("Jump", IE_Pressed, this, &APugCharacter::StartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &APugCharacter::StopJump);

}

void APugCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// finner ut hvilken vei som er frem
		FRotator Rotation = Controller->GetControlRotation();

		// legger til bevegelse i retningen
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void APugCharacter::MoveSides(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// finner retningen karakteren står i
		FRotator Rotation = Controller->GetControlRotation();

		// legger til bevegelse i retningen
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void APugCharacter::StartJump()
{
	bPressedJump = true;
}

void APugCharacter::StopJump()
{
	bPressedJump = false;
}

