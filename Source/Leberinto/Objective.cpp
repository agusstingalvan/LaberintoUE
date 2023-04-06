// Fill out your copyright notice in the Description page of Project Settings.


#include "Objective.h"
#include "PlayerBase.h"
#include "LeberintoGameModeBase.h"
#include "Engine/World.h"
// Sets default values
AObjective::AObjective()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AObjective::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AObjective::OnOverlap);
}

// Called every frame
void AObjective::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AObjective::OnOverlap(AActor* me, AActor* other)
{
	APlayerBase* player = Cast<APlayerBase>(other);
	if (player != nullptr) {
		AGameModeBase * gameModeBase = GetWorld()->GetAuthGameMode();
		ALeberintoGameModeBase* gameMode = Cast<ALeberintoGameModeBase>(gameModeBase);
		if (gameMode != nullptr) {
			gameMode->pickedObjectives++;
			Destroy();
		}
	}
}


