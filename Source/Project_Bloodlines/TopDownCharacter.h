// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TopDownCharacter.generated.h"

UCLASS()
class PROJECT_BLOODLINES_API ATopDownCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATopDownCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Character Movement")
	float MaxMovementDistance = 20.0;

	UPROPERTY(EditAnywhere, Category="Character Movement")
	float movementLeft {0.0f};
	
	UPROPERTY(BlueprintReadOnly)
	float totalDistance{0.0f};
	
	UFUNCTION()
	float CalculateMovementDistance();

	UFUNCTION()
	void MaxPlayerMoveDistance();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
