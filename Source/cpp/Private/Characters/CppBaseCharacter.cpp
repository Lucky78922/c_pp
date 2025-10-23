// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CppBaseCharacter.h"

// Sets default values
ACppBaseCharacter::ACppBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACppBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACppBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACppBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

