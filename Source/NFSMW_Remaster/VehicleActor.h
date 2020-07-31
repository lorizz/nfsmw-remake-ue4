// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VehicleActor.generated.h"

UCLASS()
class NFSMW_REMASTER_API AVehicleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVehicleActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void MoveForward(float Value);

private:
	UStaticMeshComponent* VehicleMesh;

	float Speed;

	bool bIsPlayerVehicle;

public:
	UStaticMeshComponent* GetVehicleMesh() { return VehicleMesh; }
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* WheelFL;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* WheelFR;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* WheelRL;
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* WheelRR;

	float GetSpeed() { return Speed; }
	void SetSpeed(float speed) { Speed = speed; }

	bool IsPlayerVehicle() { return bIsPlayerVehicle; }
	void SetIsPlayerVehicle(bool isPlayerVehicle) { bIsPlayerVehicle = isPlayerVehicle; }
};
