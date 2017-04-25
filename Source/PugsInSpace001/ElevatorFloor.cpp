// Coded by Audun Olsen and Henrik Engenes 2016/17

#include "PugsInSpace001.h"
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
			if (position.Z == maxZ)
			{
				goDown = true;
				isMoving = true;

			}
			else if (position.Z == minZ)
			{
				goDown = false;
				isMoving = true;
			}
		}
	}

	if (isMoving == true)
	{
		if (position.Z >= maxZ || position.Z <= minZ)
		{
			isMoving = false;
		}

		else
		{
			if (goDown == true)
			{
				position.Z = position.Z - speed;
				SetActorLocation(position);
			}
			else if (goDown == false)
			{
				position.Z = position.Z + speed;
				SetActorLocation(position);
			}
		}
	}

}

void AElevatorFloor::MoveElevator(bool getToggle)
{
	toggleSwitch = getToggle;
}