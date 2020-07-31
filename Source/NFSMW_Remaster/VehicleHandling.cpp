#include "VehicleHandling.h"

UVehicleHandling::UVehicleHandling()
{
	PrimaryComponentTick.bCanEverTick = true;
	VehicleMesh = Cast<UStaticMeshComponent>(GetOwner()->GetDefaultSubobjectByName(TEXT("VehicleMesh")));
	VehicleMovement = Cast<UFloatingPawnMovement>(GetOwner()->GetDefaultSubobjectByName(TEXT("VehicleMovement")));
}

void UVehicleHandling::BeginPlay()
{
	Super::BeginPlay();
}


void UVehicleHandling::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UVehicleHandling::ApplyThrottle(DeltaTime);
}

void UVehicleHandling::ApplyThrottle(float DeltaTime)
{
	FVector CurrentVelocity = VehicleMovement->Velocity;

	float EngineForce = 252.0f;
	FVector Ftraction = FVector(Throttle * EngineForce, 0.0f, 0.0f);

	float Cdrag = 0.29f;
	FVector Fdrag = -Cdrag * CurrentVelocity * CurrentVelocity.Size();

	float Crr = 0.01f;
	FVector Frr = -Crr * CurrentVelocity;

	FVector Flong = Ftraction + Fdrag + Frr;
	VehicleMovement->Velocity = FVector(25.0f, 100.0f, 100.0f);
	VehicleMovement->UpdateComponentVelocity();
}
