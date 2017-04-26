// Coded by Audun Olsen and Henrik Engenes 2016/17

#include "PugsInSpace001.h"
#include "LaserCatoid.h"


// Sets default values
ALaserCatoid::ALaserCatoid()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALaserCatoid::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaserCatoid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CollisionBox = this->FindComponentByClass<USphereComponent>(); //Kollisjon
	if (CollisionBox)
	{
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ALaserCatoid::OnOverlap);
		CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ALaserCatoid::OnOverlapEnd);
	}

}

// Called to bind functionality to input
void ALaserCatoid::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

