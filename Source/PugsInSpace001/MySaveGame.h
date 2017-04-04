// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class PUGSINSPACE001_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()

public:
		UPROPERTY(VisibleAnywhere, Category = PickupBools)
		bool Item1 = false;

		UPROPERTY(VisibleAnywhere, Category = PickupBools)
		bool Item2 = false;

		UPROPERTY(VisibleAnywhere, Category = PickupBools)
		bool Item3 = false;

		UPROPERTY(EditAnywhere, Category = Loading)
		FVector PlayStartTag;

		UPROPERTY(EditAnywhere, Category = Loading)
		FString SaveSlot = "SaveGame";

		UPROPERTY(EditAnywhere, Category = Loading)
		int32 PlayerIndex = 0;
};