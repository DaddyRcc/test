// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"
#include "Components/DynamicMeshComponent.h"
#include "GeometryScript/MeshPrimitiveFunctions.h"
// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false; // 关闭 Actor Tick。

	DynamicMeshComponent = CreateDefaultSubobject<UDynamicMeshComponent>(TEXT("DynamicMesh"));
	RootComponent = DynamicMeshComponent;
}

void ATestActor::AddPoints(FVector Point)
{
	Points.Add(Point);
	UE_LOG(LogTemp, Warning,
		TEXT("Add Point:%s"),
		*Point.ToString()
	);
}

void ATestActor::GenerateMesh()
{
	if (Points.Num() < 3) {
		return;
	}
	UDynamicMesh* Mesh = DynamicMeshComponent->GetDynamicMesh();
	if (!Mesh) {
		return;
	}
	Mesh->Reset();
	TArray<FVector2D> Polygon;
	for (FVector Point:Points) {
		Polygon.Add(FVector2D(Point.X,Point.Y));
	}

	FGeometryScriptPrimitiveOptions Options;
	UGeometryScriptLibrary_MeshPrimitiveFunctions::AppendSimpleExtrudePolygon
	(

		Mesh,


		Options,


		FTransform::Identity,


		Polygon,


		Height,


		1,


		true,


		EGeometryScriptPrimitiveOriginMode::Base,


		nullptr

	);

	DynamicMeshComponent->NotifyMeshUpdated();
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

