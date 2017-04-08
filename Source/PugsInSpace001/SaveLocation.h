// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SaveLocation.generated.h"

UCLASS()
class PUGSINSPACE001_API ASaveLocation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASaveLocation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		FVector ReturnLocation(FVector Location);

	UPROPERTY(EditAnywhere, Category = "Tags")
		FString TagName;
	
	
};
