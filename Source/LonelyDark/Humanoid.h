// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Attack_Base.h"
#include "CoreMinimal.h"
#include "PaperFlipbook.h"
#include "Components/ActorComponent.h"

#include "Humanoid.generated.h"

USTRUCT(BlueprintType)
struct FStatusEffects
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		int RoundsLeft;
	UPROPERTY(BlueprintReadWrite)
		float Potency;
};

USTRUCT(BlueprintType)
struct FStatusCategory
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite)
		FString type;
	UPROPERTY(BlueprintReadWrite)
		FStatusEffects data;
};

UENUM(BlueprintType)
enum AttackOutcome
{
	ATTACK_HIT,
	ATTACK_CRIT,
	ATTACK_REFLECT,
	ATTACK_CRIT2
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LONELYDARK_API UHumanoid : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHumanoid();
	UPROPERTY(BlueprintReadWrite)
	int Health = 20;
	UPROPERTY(BlueprintReadWrite)
	int Dodge = 1;
	UPROPERTY(BlueprintReadWrite)
	int Crit = 5;
	UPROPERTY(BlueprintReadWrite)
	int Armor = 5;
	UPROPERTY(BlueprintReadWrite)
	int Attackpower = 7;
	UFUNCTION(BlueprintCallable, Category = "Character")
		void Harm(int32 damage);

	UFUNCTION(BlueprintCallable, Category = "Character")
		float GetHarm(int32 damage);

	UPROPERTY(EditAnywhere)
	TMap<FString, UPaperFlipbook*> Animations;
	UPROPERTY(BlueprintReadWrite)
	TMap<FString, FStatusCategory> Status;

	

	float getResistance();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


		
};
