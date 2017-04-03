// Fill out your copyright notice in the Description page of Project Settings.

#include "PugsInSpace001.h"
#include "LevelDoor.h"
#include "MySaveGame.h"
#include "PugCharacter.h"


// Sets default values
ALevelDoor::ALevelDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelDoor::BeginPlay()
{
	Super::BeginPlay();

	CollisionBox = this->FindComponentByClass<UBoxComponent>(); //Kollisjon
	if (CollisionBox)
	{
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ALevelDoor::OnOverlap);
		CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ALevelDoor::OnOverlapEnd);
	}
	
}

// Called every frame
void ALevelDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelDoor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(APugCharacter::StaticClass()))
	{
		APugCharacter* Puglet = Cast<APugCharacter>(OtherActor);
		Puglet->Door = this;

	}
}


void ALevelDoor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(APugCharacter::StaticClass()))
	{
		APugCharacter* Puglet = Cast<APugCharacter>(OtherActor);
		Puglet->Door = nullptr;

	}
}

//Laster level som den får fra instansen til døra
void ALevelDoor::OpenDoor()
{
	UWorld* MyWorld = GetWorld();

	//lagrer hvilken playerstart som ble brukt sist
	UMySaveGame* SavedGame = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	SavedGame->PlayStartTag = this->DoorTag;

	UE_LOG(LogTemp, Warning, TEXT("Dette er playerstarten (fra døra): %s"), *SavedGame->PlayStartTag);

	//åpner levelen som døra leder til
	UGameplayStatics::OpenLevel(GetWorld(), LoadMapName);
}