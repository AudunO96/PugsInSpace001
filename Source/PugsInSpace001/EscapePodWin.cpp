// Coded by Audun Olsen and Henrik Engenes 2016/17

#include "PugsInSpace001.h"
#include "EscapePodWin.h"
#include "PugCharacter.h"


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

	CollisionBox = this->FindComponentByClass<UBoxComponent>(); //Kollisjon
	if (CollisionBox)
	{
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AEscapePodWin::OnOverlap);
		CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AEscapePodWin::OnOverlapEnd);
	}
	
}

// Called every frame
void AEscapePodWin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEscapePodWin::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(APugCharacter::StaticClass()))
	{
		APugCharacter* Puglet = Cast<APugCharacter>(OtherActor);
		Puglet->WinBox = this;

	}
}


void AEscapePodWin::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(APugCharacter::StaticClass()))
	{
		APugCharacter* Puglet = Cast<APugCharacter>(OtherActor);
		Puglet->WinBox = nullptr;
	}
}




void AEscapePodWin::WinCondition(bool BoolVal)
{
	if (BoolVal)
	{
		
	}
}

