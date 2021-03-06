// Coded by Audun Olsen and Henrik Engenes 2016/17

#include "PugsInSpace001.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackBoard/BlackboardKeyAllTypes.h"
#include "PugCharacter.h"
#include "HammerAI.h"
#include "HammerCat.h"
#include "BTTask_MoveToPlayer.h"


EBTNodeResult::Type UBTTask_MoveToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AHammerAI *CharPC = Cast<AHammerAI>(OwnerComp.GetAIOwner());
	APugCharacter *Enemy = Cast<APugCharacter>(OwnerComp.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(CharPC->EnemyKeyID));

	//isSensing = CharPC->Char->isSensing;

	if (Enemy)
	{
		//if (isSensing)
		//{
			CharPC->MoveToActor(Enemy, 5.f, true, true, true, 0, true);
			return EBTNodeResult::Succeeded;
		//}
	}
	else
	{
		return EBTNodeResult::Failed;
	}
}

