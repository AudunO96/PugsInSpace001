// Coded by Audun Olsen and Henrik Engenes 2016/17

#pragma once

#include "AIController.h"
#include "HammerAI.generated.h"


/**
 * 
 */
UCLASS()
class PUGSINSPACE001_API AHammerAI : public AAIController
{ 
	GENERATED_BODY()

	UPROPERTY(transient)
	class UBlackboardComponent *BlackboardComp;

	UPROPERTY(transient)
	class UBehaviorTreeComponent *BehaviorComp;

public: 
	 
	AHammerAI();

	class AHammerCat *Char;

	virtual void Possess(APawn *InPawn) override;

	uint8 EnemyKeyID;
	
};
