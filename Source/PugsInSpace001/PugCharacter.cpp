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

	if (InvincibilityFrame)
	{
		InvulTimer += DeltaTime;
		if (InvulTimer >= InvulTime)
		{
			InvincibilityFrame = false;
		}
	}

}

// Called to bind functionality to input
void APugCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &APugCharacter::MoveForward);
	InputComponent->BindAxis("MoveSides", this, &APugCharacter::MoveSides);

	InputComponent->BindAction("Jump", IE_Pressed, this, &APugCharacter::StartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &APugCharacter::StopJump);

	InputComponent->BindAction("Interact", IE_Pressed, this, &APugCharacter::Interact);

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

//Controls
void APugCharacter::StartJump()
{
	bPressedJump = true;
}

void APugCharacter::StopJump()
{
	bPressedJump = false;
}

void APugCharacter::Interact()
{
	if (Door)
	{
		Door->OpenDoor();
	}
}

void APugCharacter::OnDeath()
{
	UWorld* MyWorld = GetWorld();
	FString CurrentMapName = MyWorld->GetMapName();
	FName CurrentMap = FName(*CurrentMapName);

	UGameplayStatics::OpenLevel(GetWorld(), CurrentMap);
}

void APugCharacter::Damage(int DamageAmount)
{
	if (!InvincibilityFrame)
	{
		Health -= DamageAmount;
		if (Health <= 0)
		{
			OnDeath();
		}
		InvincibilityFrame = true;
		InvulTimer = 0;
	}
}

void APugCharacter::SaveGame()
{
	UMySaveGame* SavedGame = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));

	SavedGame->Item1 = this->Item1;
	SavedGame->Item2 = this->Item2;
	SavedGame->Item3 = this->Item3;

	UGameplayStatics::SaveGameToSlot(SavedGame, TEXT("LevelChange"), 0);

}
