// Fill out your copyright notice in the Description page of Project Settings.

#include "PugsInSpace001.h"
#include "MySaveGame.h"
#include "PugGameInstance.h"
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

	if (GetWorld())
	{
		//Spawns the player at the last saved position if going through a door and coming back
		//auto MyCharacter = World->SpawnActor(APugCharacter::StaticClass());
		
		if (Controller)
		{
			auto CurrentGameMode = Cast<AGameModeBase>(GetWorld()->GetAuthGameMode());
			UPugGameInstance* GameInstance = Cast<UPugGameInstance>(GetGameInstance());
 
			if (GameInstance)
			{
				this->PlayerStart = GameInstance->SpawnLocation;
				SetActorLocation(PlayerStart);
				//Controller->ClientSetRotation(NewPawn->GetActorRotation());
			}
			else
			{
				PlayerStart = FVector(100.0f, 0.0f, 20.0f);
				SetActorLocation(PlayerStart);
			}
		}
	}
	LoadGame();	
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
		SaveGame();
	}
	else if (Item)
	{
		Item->ObtainItem();
		SaveGame();
	}

	UE_LOG(LogTemp, Warning, TEXT("Objekt 1: %s"), (this->Pickups[0] ? TEXT("True") : TEXT("False")));
	UE_LOG(LogTemp, Warning, TEXT("Objekt 2: %s"), (this->Pickups[1] ? TEXT("True") : TEXT("False")));
	UE_LOG(LogTemp, Warning, TEXT("Objekt 3: %s"), (this->Pickups[2] ? TEXT("True") : TEXT("False")));
}

void APugCharacter::OnDeath()
{
	UWorld* MyWorld = GetWorld();
	FString CurrentMapName = MyWorld->GetMapName();
	FName CurrentMap = FName(*CurrentMapName);

	//endre den neste linja til å referere til en meny
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

	SavedGame->Item1 = this->Pickups[0];
	SavedGame->Item2 = this->Pickups[1];
	SavedGame->Item3 = this->Pickups[2];

	UGameplayStatics::SaveGameToSlot(SavedGame, SavedGame->SaveSlot, SavedGame->PlayerIndex);
}

void APugCharacter::LoadGame()
{
	UMySaveGame* SavedGame = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));

	SavedGame = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(SavedGame->SaveSlot, SavedGame->PlayerIndex));

	if (SavedGame)
	{
		this->Pickups[0] = SavedGame->Item1;
		this->Pickups[1] = SavedGame->Item2;
		this->Pickups[2] = SavedGame->Item3;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Load failed."));
	}
}

void APugCharacter::GetPickup(int32 PickupID)
{
	if (PickupID >= 0 && PickupID < Pickups.Num())
	{
		Pickups[PickupID] = true;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Pickup insane in the membrane!"));
	}
}