// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

class UDynamicMeshComponent;

UCLASS()
class TEST_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor();
	void AddPoints(FVector Point);
	void GenerateMesh();

	UPROPERTY()
	UDynamicMeshComponent* DynamicMeshComponent;

	TArray<FVector> Points;

	float Height = 300.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
