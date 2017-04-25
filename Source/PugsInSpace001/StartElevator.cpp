// Coded by Audun Olsen and Henrik Engenes 2016/17
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Green,text)

#include "PugsInSpace001.h"
#include "StartElevator.h"
#include "PugCharacter.h"


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
	
	CollisionBox = this->FindComponentByClass<UBoxComponent>(); //Kollisjon
	if (CollisionBox)
	{
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AStartElevator::OnOverlap);
		CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AStartElevator::OnOverlapEnd);
	}

}

void AStartElevator::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(APugCharacter::StaticClass()))
	{
		APugCharacter* Puglet = Cast<APugCharacter>(OtherActor);
		Puglet->Switch = this;
	}
}


void AStartElevator::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(APugCharacter::StaticClass()))
	{
		APugCharacter* Puglet = Cast<APugCharacter>(OtherActor);
		Puglet->Switch = nullptr;
	}
}