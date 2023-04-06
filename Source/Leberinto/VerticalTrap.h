// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VerticalTrap.generated.h"

UCLASS()
class LEBERINTO_API AVerticalTrap : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere)
	float damage;
	UPROPERTY(EditAnywhere)
	float velocity;
	UPROPERTY(EditAnywhere)
	float changeTime;
	FTimerHandle timerHandle;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void ChangeDirection();
public:	
	// Sets default values for this actor's properties
	AVerticalTrap();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlap(AActor* me, AActor* other);
};
