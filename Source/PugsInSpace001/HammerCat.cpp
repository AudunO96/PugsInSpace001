// Coded by Audun Olsen and Henrik Engenes 2016/17

#include "PugsInSpace001.h"
#include "HammerCat.h"
#include "PugCharacter.h"


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

	CollisionBox = this->FindComponentByClass<USphereComponent>(); //Kollisjon
	if (CollisionBox)
	{
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AHammerCat::OnOverlap);
		CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AHammerCat::OnOverlapEnd);
	}
}

// Called to bind functionality to input
void AHammerCat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AHammerCat::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(APugCharacter::StaticClass()))
	{
		//skader karakteren, deretter setter i animasjonsBPen at den angriper
		APugCharacter* Puglet = Cast<APugCharacter>(OtherActor);
		isAttacking = true;
		Puglet->Damage(0.5f);

		//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, "You are being hit!");
	}
}

void AHammerCat::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(APugCharacter::StaticClass()))
	{
		isAttacking = false;
	}
}
