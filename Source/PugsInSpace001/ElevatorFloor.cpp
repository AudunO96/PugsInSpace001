// Coded by Audun Olsen and Henrik Engenes 2016/17
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Green,text)

#include "PugsInSpace001.h"
#include "PugCharacter.h"
#include "ElevatorFloor.h"


// Sets default values
AElevatorFloor::AElevatorFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AElevatorFloor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AElevatorFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector position = GetActorLocation();

	if (toggleSwitch == true)
	{
		if (isMoving == false)
		{
			if (goDown == false)
			{
				goDown = true;
				isMoving = true;

			}
			else if (goDown == true)
			{
				goDown = false;
				isMoving = true;
			}
		}
	}

	toggleSwitch = false;

	if (isMoving == true)
	{
		if (position.Z >= maxZ)
		{
			if (goDown == true)
			{
				speed = -2.0f;
			}
			else if (goDown == false)
			{
				isMoving = false;
			}
		}
		else if (position.Z <= minZ)
		{
			if (goDown == false)
			{
				speed = 2.0f;
			}
			else if (goDown == true)
			{
				isMoving = false;
			}
		}
		position.Z = position.Z + speed;
		SetActorLocation(position);
	}

	CollisionBox = this->FindComponentByClass<UBoxComponent>(); //Kollisjon
	if (CollisionBox)
	{
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AElevatorFloor::OnOverlap);
		CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AElevatorFloor::OnOverlapEnd);
	}

}


void AElevatorFloor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(APugCharacter::StaticClass()))
	{
		APugCharacter* Puglet = Cast<APugCharacter>(OtherActor);
		Puglet->Lift = this;
	}
}
void AElevatorFloor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(APugCharacter::StaticClass()))
	{
		APugCharacter* Puglet = Cast<APugCharacter>(OtherActor);
		Puglet->Lift = nullptr;
	}
}

void AElevatorFloor::MoveElevator(bool toggle)
{
	toggleSwitch = toggle;
}