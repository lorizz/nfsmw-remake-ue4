// Fill out your copyright notice in the Description page of Project Settings.


#include "VehicleActor.h"

// Sets default values
AVehicleActor::AVehicleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	VehicleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VehicleMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> VehicleMeshAsset(TEXT("/Game/Assets/Vehicles/RX7/SM_RX7"));
	if (VehicleMeshAsset.Object)
	{
		VehicleMesh->SetStaticMesh(VehicleMeshAsset.Object);
	}
	WheelFL = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WheelFL"));
	WheelFR = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WheelFR"));
	WheelRL = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WheelRL"));
	WheelRR = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WheelRR"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> WheelAsset(TEXT("/Game/Assets/Vehicles/RX7/SM_RX7_Wheel"));
	if (WheelAsset.Object)
	{
		WheelFL->SetStaticMesh(WheelAsset.Object);
		WheelFR->SetStaticMesh(WheelAsset.Object);
		WheelRL->SetStaticMesh(WheelAsset.Object);
		WheelRR->SetStaticMesh(WheelAsset.Object);
	}
	WheelFL->AttachTo(VehicleMesh, FName("WheelFL"));
	WheelFR->AttachTo(VehicleMesh, FName("WheelFR"));
	WheelRL->AttachTo(VehicleMesh, FName("WheelRL"));
	WheelRR->AttachTo(VehicleMesh, FName("WheelRR"));
}

void AVehicleActor::BeginPlay()
{
	Super::BeginPlay();
	VehicleMesh->SetSimulatePhysics(true);
}

void AVehicleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}