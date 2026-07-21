// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPlayerController.h"
#include "TestActor.h"
#include "Engine/World.h"
ATestPlayerController::ATestPlayerController()
{
	bShowMouseCursor = true;
}

void ATestPlayerController::BeginPlay()
{
	Super::BeginPlay();
	TestActor = GetWorld()->SpawnActor<ATestActor>();

}

void ATestPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindKey(
		EKeys::LeftMouseButton,

		IE_Pressed,

		this,

		&ATestPlayerController::MouseClick
	);
	InputComponent->BindKey(
		EKeys::Enter,

		IE_Pressed,

		this,

		&ATestPlayerController::CreateMesh
	);


}

void ATestPlayerController::MouseClick()
{

	FVector WorldPosition;
	if (TestActor && GetMouseWorldPosition(WorldPosition)) {
		TestActor->AddPoints(WorldPosition);
	}
}

void ATestPlayerController::CreateMesh()
{

	if (TestActor) {
		TestActor->GenerateMesh();
	}
}

bool ATestPlayerController::GetMouseWorldPosition(FVector& OutPosition)
{
	FHitResult Hit;
	bool bHit =
		GetHitResultUnderCursor(

			ECC_Visibility,

			false,

			Hit

		);



	if (bHit)
	{

		OutPosition =
			Hit.Location;


		return true;

	}
	return false;
}


