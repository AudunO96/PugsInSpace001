// Coded by Audun Olsen and Henrik Engenes 2016/17

#include "PugsInSpace001.h"
#include "PugCharacter.h"
#include "Laser.h"


// Sets default values
ALaser::ALaser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALaser::BeginPlay()
{
	Super::BeginPlay();

	//laserPoint = Catze->pointLaser;

	//velocity = 100.0f * laserPoint;

	lifeSpan = 40;
}

// Called every frame
void ALaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	lifeSpan--;


	//FVector NewLocation = GetActorLocation() + (velocity * DeltaTime);
	//SetActorLocation(NewLocation);


	CollisionBox = this->FindComponentByClass<UBoxComponent>(); //Kollisjon
	if (CollisionBox)
	{
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ALaser::OnOverlap);
	}
	if (lifeSpan == 0)
	{
		Destroy();
	}

}

void ALaser::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(APugCharacter::StaticClass()))
	{
		APugCharacter* Puglet = Cast<APugCharacter>(OtherActor); 
		Puglet->Damage(0.2f);
		Destroy();
	}


}