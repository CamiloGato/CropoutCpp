// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DefenseTower.generated.h"

class UBoxComponent;

UCLASS(Blueprintable)
class CROPOUTSAMPLEPROJECT_API ADefenseTower : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADefenseTower();
	
	UPROPERTY(EditAnywhere, Category="Tower Params")
	int HealthPoints = 500;
	UPROPERTY(EditAnywhere, Category="Tower Params")
	int ShellDefence = 3;
	UPROPERTY(EditAnywhere, Category="Tower Params")
	float AttackRange = 6.0f;
	UPROPERTY(EditAnywhere, Category="Tower Params")
	float ReloadInterval = 1.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int _HealthPoints; //the tower's current health points
	float _ReloadCountingDown;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category = "Pangaea|Defense Tower", meta=(DisplayName="GetHP"))
	int GetHealthPoints() const;

	UFUNCTION(BlueprintPure, Category = "Pangaea|Defense Tower")
	bool IsDestroyed() const;

	UFUNCTION(BlueprintPure, Category = "Pangaea|Defense Tower")
	bool CanFire() const;
	
	void Fire();
	void Hit(int damage);

protected:
	void DestroyProcess();


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tower Component", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* _BoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tower Component", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* _MeshComponent;

public:

	FORCEINLINE UBoxComponent* GetBoxComponent() const
	{
		return _BoxComponent;
	}

	FORCEINLINE UStaticMeshComponent* GetMeshComponent() const
	{
		return _MeshComponent;
	}
};
