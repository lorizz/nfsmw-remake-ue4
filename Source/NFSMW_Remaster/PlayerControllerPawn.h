#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "VehicleActor.h"
#include "VehicleHandling.h"
#include "EngineUtils.h"
#include "Camera/CameraComponent.h"
#include "PlayerControllerPawn.generated.h"

UCLASS()
class NFSMW_REMASTER_API APlayerControllerPawn : public APawn
{
	GENERATED_BODY()

public:
	APlayerControllerPawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere)
		UFloatingPawnMovement* VehicleMovement;
	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* VehicleMesh;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* VehicleWheelFL;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* VehicleWheelFR;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* VehicleWheelRL;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* VehicleWheelRR;
	UPROPERTY(EditAnywhere)
		UVehicleHandling* VehicleHandling;

protected:
	void MoveForward(float Value);
	void MoveRight(float Value);

	FVector CurrentVelocity;
};
