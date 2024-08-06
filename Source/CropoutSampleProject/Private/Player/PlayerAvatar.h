// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerAvatar.generated.h"

UCLASS(Blueprintable)
class CROPOUTSAMPLEPROJECT_API APlayerAvatar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerAvatar();

	FORCEINLINE class USpringArmComponent* GetSpringArmComponent() const { return _sprintArmComponent; };
	FORCEINLINE class UCameraComponent* GetCameraComponent() const { return _cameraComponent; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Called every frame
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera",
		meta=(AllowPrivateAccess="true") )
	USpringArmComponent* _sprintArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Camera",
		meta=(AllowPrivateAccess="true"))
	UCameraComponent* _cameraComponent;
	
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
