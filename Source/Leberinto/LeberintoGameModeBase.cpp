// Fill out your copyright notice in the Description page of Project Settings.


#include "LeberintoGameModeBase.h"
#include "Engine/World.h"
ALeberintoGameModeBase::ALeberintoGameModeBase() {
	PrimaryActorTick.bCanEverTick = true;
	pickedObjectives = 0;
	objectivesToPick = 1;
}

void ALeberintoGameModeBase::Tick(float DeltaTime)
{
	if (pickedObjectives >= objectivesToPick) {
		GetWorld()->ServerTravel("win");
	}
}
