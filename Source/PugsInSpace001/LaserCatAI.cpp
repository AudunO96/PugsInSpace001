// Coded by Audun Olsen and Henrik Engenes 2016/17

#include "PugsInSpace001.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "LaserCatoid.h"
#include "LaserCatAI.h"




ALaserCatAI::ALaserCatAI()
{
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));

}

void ALaserCatAI::Possess(APawn *InPawn)
{
	Super::Possess(InPawn);

	LaserChar = Cast<ALaserCatoid>(InPawn);

	if (LaserChar && LaserChar->BotBehavior)
	{
		BlackboardComp->InitializeBlackboard(*LaserChar->BotBehavior->BlackboardAsset);

		EnemyKeyID = BlackboardComp->GetKeyID("Target");

		BehaviorComp->StartTree(*LaserChar->BotBehavior);
	}
}

