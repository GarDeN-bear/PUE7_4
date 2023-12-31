#include "CppBaseActor.h"

// Sets default values
ACppBaseActor::ACppBaseActor() : Amplitude(70), Frequency(4), InitialLocation(0, 0, 0)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = GetActorLocation();
}

FVector ACppBaseActor::SinMovement(const float& Time)
{
	InitialLocation.Z = Amplitude * sin(Frequency * Time) + InitialLocation.Z;
	return InitialLocation;
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
