// Coded by Audun Olsen and Henrik Engenes 2016/17

#include "PugsInSpace001.h"
#include "StartElevator.h"


// Sets default values
AStartElevator::AStartElevator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStartElevator::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AStartElevator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	CollisionBox = this->FindComponentByClass<UCapsuleComponent>(); //Kollisjon
	if (CollisionBox)
	{
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AStartElevator::OnOverlap);
		CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AStartElevator::OnOverlapEnd);
	}OtherBodyIndex);
	*/
}

