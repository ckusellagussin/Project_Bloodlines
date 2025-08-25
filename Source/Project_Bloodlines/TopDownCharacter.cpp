// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDownCharacter.h"
#include "AssetTypeCategories.h"
#include "SWarningOrErrorBox.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Misc/App.h"

// Sets default values
ATopDownCharacter::ATopDownCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATopDownCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATopDownCharacter::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	CalculateMovementDistance();
	MaxPlayerMoveDistance();

}


// Called to bind functionality to input
void ATopDownCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


float ATopDownCharacter::CalculateMovementDistance()
{
	//Convert Velocity from character into speed
	FVector Velocity = GetVelocity();
	float Speed = Velocity.Size();

	//Divide by 100 to get distance by cm but is standard Distance = Speed * Time
	float CharacterDistance =  Speed * GetWorld()->GetDeltaSeconds() / 100;

	//Add distance travelled to a sum and display
	totalDistance = totalDistance += CharacterDistance;
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Cyan, 
			FString::Printf(TEXT("Frame: %.2f | Total: %.2f"), CharacterDistance, totalDistance));
	}

	return totalDistance;
}

void ATopDownCharacter::MaxPlayerMoveDistance()
{
	
	totalDistance = CalculateMovementDistance();
	movementLeft = MaxMovementDistance - totalDistance;

	if (totalDistance >= MaxMovementDistance)
	{

		GetCharacterMovement()->MaxWalkSpeed = 0.0f;
		
	}
	
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(2, 0.0f, FColor::Red, 
			FString::Printf(TEXT("Total Distance Left: %.2f"), movementLeft));
	}
	
}


