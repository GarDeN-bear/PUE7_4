// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Dynamic,
	Static
};

UCLASS()
class PUE7_4_API ACppBaseActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACppBaseActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	FVector SinMovement(const float& Time);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	float Amplitude;

	UPROPERTY(EditAnywhere)
	float Frequency;

	UPROPERTY(EditAnywhere)
	FVector InitialLocation;
};
