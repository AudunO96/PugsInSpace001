// Fill out your copyright notice in the Description page of Project Settings.
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Green,text)

#include "PugsInSpace001.h"
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
				PlayerStart = FVector(-422.224365f, -168.297699f, 157.928680f);
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

	if (isDying)
	{
		DeathTimer += DeltaTime;
		if (DeathTimer >= DeathTime)
		{
			DeathComplete();
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
	if ((Controller != NULL) && (Value != 0.0f) && !isDying)
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
	if ((Controller != NULL) && (Value != 0.0f) && !isDying)
	{
		// finner retningen karakteren st�r i
		FRotator Rotation = Controller->GetControlRotation();

		// legger til bevegelse i retningen
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

//Controls
void APugCharacter::StartJump()
{
	if(!isDying)
	bPressedJump = true;
}

void APugCharacter::StopJump()
{
	if(!isDying)
	bPressedJump = false;
}

void APugCharacter::Interact()
{   //sjekker hvilket object pugen interakterer med
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
	else if (Switch)
	{
		if(Lift)
		{
			Lift->MoveElevator(true);
		}
	}
	else if (WinBox)
	{
		if (Pickups[0] == true && Pickups[1] == true && Pickups[2] == true)
		{
			WinBox->WinCondition(true);
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, "The escape pod is broken! Find the three necessary objects to fix it!");
		}
	}

}

void APugCharacter::OnDeath()
{
	isDying = true;
}

void APugCharacter::DeathComplete()
{
	UWorld* MyWorld = GetWorld();
	FString CurrentMapName = MyWorld->GetMapName();
	FName CurrentMap = FName(*CurrentMapName);

	//loader level
	UGameplayStatics::OpenLevel(GetWorld(), "Barracks");

	UPugGameInstance* GameInstance = Cast<UPugGameInstance>(GetGameInstance());
	
	GameInstance->instanceHealth = 1.0f;
	GameInstance->SpawnLocation = FVector(-422.224365f, -168.297699f, 157.928680f);
}

void APugCharacter::Damage(float DamageAmount)
{
	if (!InvincibilityFrame)
	{
		Health -= DamageAmount;
		if (Health <= 0.001f)
		{
			OnDeath();
		}
		InvincibilityFrame = true;
		InvulTimer = 0;
	}
}

//lagrer variabler mellom instances
void APugCharacter::SaveGame()
{
	UPugGameInstance* GameInstance = Cast<UPugGameInstance>(GetGameInstance());

	GameInstance->instanceHealth = this->Health;
	GameInstance->item1 = this->Pickups[0];
	GameInstance->item2 = this->Pickups[1];
	GameInstance->item3 = this->Pickups[2];
}
//laster variabler mellom instances
void APugCharacter::LoadGame()
{
	UPugGameInstance* GameInstance = Cast<UPugGameInstance>(GetGameInstance());

	if (GameInstance)
	{
		this->Health = GameInstance->instanceHealth;
		this->Pickups[0] = GameInstance->item1;
		this->Pickups[1] = GameInstance->item2;
		this->Pickups[2] = GameInstance->item3;
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
		UE_LOG(LogTemp, Warning, TEXT("Pickup.... eksisterer ikke?"));
	}
}