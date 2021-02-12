// Fill out your copyright notice in the Description page of Project Settings.


#include "Humanoid.h"

// Sets default values for this component's properties
UHumanoid::UHumanoid()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHumanoid::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

float UHumanoid::getResistance()
{
	return 1 - (Armor / 5);
}


float UHumanoid::GetHarm(int32 Damage)
{
	Damage *= getResistance();

	return Damage;

}

void UHumanoid::Harm(int32 Damage)
{
	Health -= Damage;
}

// Called every frame
void UHumanoid::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

