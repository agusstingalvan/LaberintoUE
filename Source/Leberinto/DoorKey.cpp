// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorKey.h"
#include "PlayerBase.h"

// Sets default values
ADoorKey::ADoorKey()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoorKey::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ADoorKey::OnOverlap);
}

// Called every frame
void ADoorKey::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoorKey::OnOverlap(AActor* me, AActor* other)
{
	APlayerBase* player = Cast<APlayerBase>(other);
	if (player != nullptr) {
		player->keys += 1;
		Destroy();
	}
}

