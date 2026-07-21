// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TestPlayerController.generated.h"

class ATestActor;

/**
 * 
 */
UCLASS()
class TEST_API ATestPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATestPlayerController();
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
private:
	ATestActor* TestActor;

	void MouseClick();
	void CreateMesh();
	bool GetMouseWorldPosition(
		FVector& OutPosition
	);
};
