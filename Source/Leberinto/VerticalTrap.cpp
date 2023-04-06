// Fill out your copyright notice in the Description page of Project Settings.


#include "VerticalTrap.h"
#include "TimerManager.h"
#include "PlayerBase.h"
#include <iostream>

// Sets default values
AVerticalTrap::AVerticalTrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	velocity = -30.0f;
	changeTime = 1.0f;
	damage = 50.0f;
}

// Called when the game starts or when spawned
void AVerticalTrap::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(timerHandle, this, &AVerticalTrap::ChangeDirection, changeTime, true);

	OnActorBeginOverlap.AddDynamic(this, &AVerticalTrap::OnOverlap);
}

// Called every frame
void AVerticalTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector movement(0, 0, 0);
	movement.Z = velocity * DeltaTime;
	AddActorLocalOffset(movement, true);
}

void AVerticalTrap::ChangeDirection()
{
	velocity = velocity * -1;
}

void AVerticalTrap::OnOverlap(AActor* me, AActor* other)
{
	APlayerBase* pb = Cast<APlayerBase>(other);

	if (pb != nullptr) {
		pb->life -= damage;
	}
}
