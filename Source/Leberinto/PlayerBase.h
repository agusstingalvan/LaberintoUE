// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerBase.generated.h"

UCLASS()
class LEBERINTO_API APlayerBase : public APawn
{
	GENERATED_BODY()

public:
	int respawns;

	UPROPERTY(VisibleAnywhere)
	class ACheckPoint* currentCheckpoint;
	UPROPERTY(VisibleAnywhere)
	int keys;
	UPROPERTY(VisibleAnywhere)
	FVector initialPosition;
	UPROPERTY(VisibleAnywhere)
	FRotator initialRotation;

	UPROPERTY(VisibleAnywhere)
	float initialLife;

	UPROPERTY(EditAnywhere)
	float life;
	UPROPERTY(EditAnywhere)
	float velocity;

	UPROPERTY(EditAnywhere)
	float rotationVelocity;

	// Sets default values for this pawn's properties
	APlayerBase();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void ForwardAxis(float axis);
	void SideAxis(float axis);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
