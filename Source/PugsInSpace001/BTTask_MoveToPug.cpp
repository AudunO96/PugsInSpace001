// Coded by Audun Olsen and Henrik Engenes 2016/17

#include "PugsInSpace001.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackBoard/BlackboardKeyAllTypes.h"
#include "PugCharacter.h"
#include "LaserCatAI.h"
#include "LaserCatoid.h"
#include "BTTask_MoveToPug.h"

EBTNodeResult::Type UBTTask_MoveToPug::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ALaserCatAI *CharPC = Cast<ALaserCatAI>(OwnerComp.GetAIOwner());
	APugCharacter *Enemy = Cast<APugCharacter>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(CharPC->EnemyKeyID));

	tracking = CharPC->LaserChar->tracking;

	if (Enemy && tracking)
	{
		CharPC->MoveToActor(Enemy, 5.0f, true, true, false, 0, true);
		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Failed;
	}
}


