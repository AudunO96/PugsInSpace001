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

	if (toggleSwitch == false)
	{
		if (goDown == true)
		{

		}

		else if (goUp == true)
		{

		}
	}

}

