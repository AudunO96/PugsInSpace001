// Coded by Audun Olsen and Henrik Engenes 2016/17

#pragma once

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_MoveToPlayer.generated.h"

/**
 *   
 */
UCLASS()
class PUGSINSPACE001_API UBTTask_MoveToPlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	//EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
	
};
