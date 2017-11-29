// Copyright C 2017 Tomasz Figas

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class ACameraSplinePath;
class APlayerSplinePath;

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

	// Sets character location 
	FVector SetLocalCharacterLocation(FVector CharacterLocation);

	// Set character current rotation
	FRotator SetCurrentCharacterRotation(FRotator CurrentRotation);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline Movement")
	ACameraActor* CameraReference = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline Movement")
	ACameraSplinePath* CameraSplinePath = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spline Movement")
	APlayerSplinePath* PlayerSplinePath = nullptr;

protected:
	/** Called for side to side input */
	void MoveRight(float Value);


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	UPROPERTY(EditDefaultsOnly, Category = "Spline Movement")
	float AmountToMove = 0.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Spline Movement")
	float DistanceToMoveAlongSpline = 0.f;

	UPROPERTY(EditDefaultsOnly, Category = "Spline Movement")
	FRotator CurrentRotation = FRotator(0.0f, 0.0f, 0.0f);

	UPROPERTY(EditDefaultsOnly, Category = "Spline Movement")
	FVector CharacterLocation = FVector(0.0f, 0.0f, 0.0f);


	
	
};
