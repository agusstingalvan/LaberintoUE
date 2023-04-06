// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "PlayerBase.h"
// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ADoor::OnOverlap);
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoor::OnOverlap(AActor* me, AActor *other)
{
	APlayerBase* player = Cast<APlayerBase>(other);
	if (player != nullptr && player->keys > 0) {
		player->keys--;
		Destroy();
	}
}

