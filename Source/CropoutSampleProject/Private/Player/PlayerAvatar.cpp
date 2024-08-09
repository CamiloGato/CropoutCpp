﻿// Fill out your copyright notice in the Description page of Project Settings.

#include "CropoutSampleProject/Public/Player/PlayerAvatar.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APlayerAvatar::APlayerAvatar()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	UCharacterMovementComponent* characterMovement = GetCharacterMovement();
	characterMovement->bOrientRotationToMovement = true;
}

// Called when the game starts or when spawned
void APlayerAvatar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int APlayerAvatar::GetHealthPoints()
{
	return _HealthPoints;
}

bool APlayerAvatar::IsKilled()
{
	return _HealthPoints <= 0.0f;
}

bool APlayerAvatar::CanAttack()
{
	return _AttackCountingDown <= 0.0f;
}

// Called to bind functionality to input
void APlayerAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

