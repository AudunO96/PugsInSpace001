// Coded by Audun Olsen and Henrik Engenes 2016/17

#include "PugsInSpace001.h"
#include "PugCharacter.h"
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




void AEscapePodWin::WinCondition(bool BoolVal)
{
	CanWin = BoolVal;
}

