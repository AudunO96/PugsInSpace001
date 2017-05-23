// Coded by Audun Olsen and Henrik Engenes 2016/17

#include "PugsInSpace001.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BlackBoard/BlackboardKeyAllTypes.h"
#include "HammerCat.h"
#include "HammerAI.h"


AHammerAI::AHammerAI()
{
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComp"));

	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
}

void AHammerAI::Possess(APawn *InPawn)
{
	Super::Possess(InPawn);

	Char = Cast<AHammerCat>(InPawn);

	if (Char && Char->BotBehavior)
	{
		BlackboardComp->InitializeBlackboard(*Char->BotBehavior->BlackboardAsset);

		EnemyKeyID = BlackboardComp->GetKeyID("Target");  

		BehaviorComp->StartTree(*Char->BotBehavior);
	}
}