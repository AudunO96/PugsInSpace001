// Coded by Audun Olsen and Henrik Engenes 2016/17

#include "PugsInSpace001.h"
#include "EscapePodWin.h"


// Sets default values
AEscapePodWin::AEscapePodWin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEscapePodWin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscapePodWin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEscapePodWin::WinCondition(bool BoolVal)
{
	CanWin = BoolVal;
}

