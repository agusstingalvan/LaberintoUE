// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckPoint.h"
#include "PlayerBase.h"
// Sets default values
ACheckPoint::ACheckPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACheckPoint::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ACheckPoint::OnOverlap);
}

// Called every frame
void ACheckPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACheckPoint::OnOverlap(AActor* me, AActor* other)
{
	APlayerBase* player = Cast<APlayerBase>(other);

	if (player != nullptr && player->currentCheckpoint != this) {

		player->initialPosition = GetActorLocation();
		player->initialRotation = GetActorRotation();

		if (player->currentCheckpoint != nullptr)
		{
			player->currentCheckpoint->AddActorLocalOffset(FVector(0, 0, 20));
		}

		player->currentCheckpoint = this;
		AddActorLocalOffset(FVector(0, 0, -20));
		UE_LOG(LogTemp, Warning, TEXT("CHECKPOINT!"));
	}
}

