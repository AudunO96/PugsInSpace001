// Coded by Audun Olsen and Henrik Engenes 2016/17

#include "PugsInSpace001.h"
#include "HammerCat.h"


// Sets default values
AHammerCat::AHammerCat()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHammerCat::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHammerCat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHammerCat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
