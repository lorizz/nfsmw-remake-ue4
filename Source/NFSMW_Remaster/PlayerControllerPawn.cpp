#include "PlayerControllerPawn.h"

APlayerControllerPawn::APlayerControllerPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	VehicleMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("VehicleMovement"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	VehicleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VehicleMesh"));
	VehicleWheelFL = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VehicleWheelFL"));
	VehicleWheelFR = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VehicleWheelFR"));
	VehicleWheelRL = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VehicleWheelRL"));
	VehicleWheelRR = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VehicleWheelRR"));
	VehicleHandling = CreateDefaultSubobject<UVehicleHandling>(TEXT("VehicleHandling"));

	VehicleMesh->SetupAttachment(RootComponent);


	Camera->SetupAttachment(VehicleMesh);
	Camera->SetRelativeLocationAndRotation(FVector(0.0f, -420.0f, 135.0f), FRotator(-10.0f, 90.0f, 0.0f));

	VehicleWheelFL->SetupAttachment(VehicleMesh);
	VehicleWheelFL->AttachTo(VehicleMesh, FName("WheelFL"));

	VehicleWheelFR->SetupAttachment(VehicleMesh);
	VehicleWheelFR->AttachTo(VehicleMesh, FName("WheelFR"));

	VehicleWheelRL->SetupAttachment(VehicleMesh);
	VehicleWheelRL->AttachTo(VehicleMesh, FName("WheelRL"));

	VehicleWheelRR->SetupAttachment(VehicleMesh);
	VehicleWheelRR->AttachTo(VehicleMesh, FName("WheelRR"));

	VehicleMesh->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	VehicleMesh->SetSimulatePhysics(true);
	VehicleMesh->SetMassOverrideInKg(NAME_None, 1000.0f);
	VehicleMesh->SetEnableGravity(true);
	VehicleMesh->SetLinearDamping(0.0f);
	VehicleMesh->bApplyImpulseOnDamage = false;
	VehicleMesh->bReplicatePhysicsToAutonomousProxy = false;
}

void APlayerControllerPawn::BeginPlay()
{
	Super::BeginPlay();
	AddActorLocalOffset(VehicleMesh->GetRelativeLocation());
}

void APlayerControllerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerControllerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	InputComponent->BindAxis("MoveForward", this, &APlayerControllerPawn::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &APlayerControllerPawn::MoveRight);
}

void APlayerControllerPawn::MoveForward(float Value)
{
	VehicleHandling->Throttle = FMath::Clamp(Value, -1.0f, 1.0f);
}

void APlayerControllerPawn::MoveRight(float Value)
{
	VehicleHandling->Steering = FMath::Clamp(Value, -1.0f, 1.0f);
}
