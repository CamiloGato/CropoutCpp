// Fill out your copyright notice in the Description page of Project Settings.


#include "CropoutSampleProject/Public/Tower/DefenseTower.h"
#include "Components/BoxComponent.h"


// Sets default values
ADefenseTower::ADefenseTower()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	SetRootComponent(_BoxComponent);

	_MeshComponent =CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh"));
	_MeshComponent->SetupAttachment(_BoxComponent);
}

// Called when the game starts or when spawned
void ADefenseTower::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADefenseTower::DestroyProcess()
{
	
}

// Called every frame
void ADefenseTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int ADefenseTower::GetHealthPoints() const
{
	return _HealthPoints;
}

bool ADefenseTower::IsDestroyed() const
{
	return _HealthPoints < 0.0f;
}

bool ADefenseTower::CanFire() const
{
	return _ReloadCountingDown <= 0.0f;
}

