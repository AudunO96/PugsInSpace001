// Coded by Audun Olsen and Henrik Engenes 2016/17

#pragma once

#include "BehaviorTree/BTService.h"
#include "BTService_CheckForPlayer.generated.h"

/**
 * 
 */
UCLASS()
class PUGSINSPACE001_API UBTService_CheckForPlayer : public UBTService
{
	GENERATED_BODY()

public: 


	UBTService_CheckForPlayer();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
	
};
