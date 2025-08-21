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
	MovementDistance();


}


// Called to bind functionality to input
void ATopDownCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ATopDownCharacter::MovementDistance()
{
	FVector Velocity = GetVelocity();
	float Speed = Velocity.Size();
	float CharacterDistance =  Speed * GetWorld()->GetDeltaSeconds() / 100;
	
	TotalDistance = TotalDistance += CharacterDistance;
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Cyan, 
			FString::Printf(TEXT("Frame: %.2f | Total: %.2f"), CharacterDistance, TotalDistance));
	}	
}

