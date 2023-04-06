// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBase.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
// Sets default values
APlayerBase::APlayerBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	life = 100.0f;
	initialLife = life;
	respawns = 3;
	velocity = 500.0;
	rotationVelocity = 180.0;
	keys = 0;
}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
	initialPosition = GetActorLocation();
	initialRotation = GetActorRotation();
}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (life <= 0) {
		if (respawns > 0) {
			SetActorLocation(initialPosition);
			SetActorRotation(initialRotation);
			life = initialLife;
			respawns--;
			UE_LOG(LogTemp, Warning, TEXT("Player Respawn!"));
		}
		else {
			Destroy();
			UE_LOG(LogTemp, Warning, TEXT("Player death!"))
		}
	}
	
}

// Called to bind functionality to input
void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Forward", this, &APlayerBase::ForwardAxis);
	PlayerInputComponent->BindAxis("Side", this, &APlayerBase::SideAxis);
}

void APlayerBase::ForwardAxis(float axis) {

	FVector movement(0, 0, 0);
	float deltaSeconds = GetWorld()->GetDeltaSeconds();
	movement.X = axis * velocity * deltaSeconds;

	AddActorLocalOffset(movement, true);
}

void APlayerBase::SideAxis(float axis) {

	FRotator rotary(0, 0, 0);
	float deltaSeconds = GetWorld()->GetDeltaSeconds();
	rotary.Yaw = axis * rotationVelocity * deltaSeconds;

	AddActorLocalRotation(rotary);
}

