// Coded by Audun Olsen and Henrik Engenes 2016/17

#pragma once

#include "Engine/GameInstance.h"
#include "PugGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PUGSINSPACE001_API UPugGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
		UPugGameInstance(const FObjectInitializer& ObjectInitializer);

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelSpawning)
			FVector SpawnLocation;
	
	
};