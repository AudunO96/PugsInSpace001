// Fill out your copyright notice in the Description page of Project Settings.

#include "PugsInSpace001.h"
#include "ItemPickups.h"
#include "PugCharacter.h"


// Sets default values
AItemPickups::AItemPickups()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItemPickups::BeginPlay()
{
	Super::BeginPlay();

	CollisionBox = this->FindComponentByClass<USphereComponent>(); //Kollisjon
	if (CollisionBox)
	{
		CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AItemPickups::OnOverlap);
		CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AItemPickups::OnOverlapEnd);
	}
	
}

// Called every frame
void AItemPickups::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemPickups::ObtainItem()
{
	TArray<AActor*> Pugs;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APugCharacter::StaticClass(), Pugs);

	APugCharacter* Puglet = Cast<APugCharacter>(Pugs[0]);

	Puglet->GetPickup(ItemID);
	Destroy();
}

void AItemPickups::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
	UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult &SweepResult)
{
	if (OtherActor->IsA(APugCharacter::StaticClass()))
	{
		APugCharacter* Puglet = Cast<APugCharacter>(OtherActor);
		Puglet->Item = this;

	}
}


void AItemPickups::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->IsA(APugCharacter::StaticClass()))
	{
		APugCharacter* Puglet = Cast<APugCharacter>(OtherActor);
		Puglet->Item = nullptr;

	}
}
