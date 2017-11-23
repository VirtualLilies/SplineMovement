// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class SPLINEMOVEMENT_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SetAmountToMove();

	UPROPERTY(BlueprintReadWrite, Category = "Spline Movement")
		float AmountToMove = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Spline Movement")
		float DistanceToMoveAlongSpline = 0.0f;

	UPROPERTY(BlueprintReadWrite, Category = "Spline Movement")
		FRotator CurrentRotation = FRotator(0.0f, 0.0f, 0.0f);

	UPROPERTY(BlueprintReadWrite, Category = "Spline Movement")
		FVector CharacterLocation = FVector(0.0f, 0.0f, 0.0f);

	
	
};
