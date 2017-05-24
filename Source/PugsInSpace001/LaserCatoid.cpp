// Coded by Audun Olsen and Henrik Engenes 2016/17

#include "PugsInSpace001.h"
#include "PugCharacter.h"
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

	
	if (tracking == true)
	{
		recharge--;
		if (recharge == 0)
		{

			UWorld* World = GetWorld();
		
			if (World)
			{
				FVector Location = GetActorLocation();
				Location.Z -= 20.0f;
				FRotator Rotation = GetActorRotation();
				World->SpawnActor<ALaser>(Laser_BP, Location, Rotation);
				recharge = 100;
			}
		}
	}

}

// Called to bind functionality to input
void ALaserCatoid::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ALaserCatoid::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(APugCharacter::StaticClass()))
	{
		APugCharacter* Puglet = Cast<APugCharacter>(OtherActor);
		pointLaser = ALaserCatoid::GetActorLocation() + Puglet->GetActorLocation();
		tracking = true;
		UE_LOG(LogTemp, Warning, TEXT("Pointing"));
	}
}

void ALaserCatoid::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(APugCharacter::StaticClass()))
	{
		pointLaser = FVector(0.0f, 0.0f, 0.0f);
		tracking = false;
	}
}