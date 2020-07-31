#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/MovementComponent.h"
#include "VehicleHandling.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NFSMW_REMASTER_API UVehicleHandling : public UActorComponent
{
	GENERATED_BODY()

public:	
	UVehicleHandling();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void ApplyThrottle(float DeltaTime);

	float Throttle = 0.0f;
	float Steering = 0.0f;

private:
	UStaticMeshComponent* VehicleMesh;
	UMovementComponent* VehicleMovement;

public:
	UPROPERTY(EditAnywhere, Category = "Chassis")
		float AeroDrag;
	UPROPERTY(EditAnywhere, Category = "Engine")
		float MaxRPM;

};
