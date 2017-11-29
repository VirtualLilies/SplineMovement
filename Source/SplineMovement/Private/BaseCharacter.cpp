// Copyright C 2017 Tomasz Figas


#include "BaseCharacter.h"
#include "Components/SplineComponent.h"
#include "Components/CapsuleComponent.h"
#include "PlayerSplinePath.h"
#include "CameraSplinePath.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"


// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{

	// Setup gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame

void ABaseCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// Set movement direction, hard coded.
		const FVector Direction = FVector(0.f, 1.f, 0.f);

		// Set values for spline movement mechanic
		float AmountToMove = GetMovementComponent()->Velocity.Size() * Value * FApp::GetDeltaTime();
		DistanceToMoveAlongSpline = DistanceToMoveAlongSpline + AmountToMove;

		// Add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

FVector ABaseCharacter::SetLocalCharacterLocation(FVector CharacterLocation)
{
	FVector LocationAtDistance = PlayerSplinePath->PlayerSpline->GetLocationAtDistanceAlongSpline(DistanceToMoveAlongSpline, ESplineCoordinateSpace::World);
	float LocationAtDistanceX = LocationAtDistance.X;
	float LocationAtDistanceY = LocationAtDistance.Y;
	FVector CapsuleLocation = GetCapsuleComponent()->USceneComponent::GetComponentLocation();
	float CapsuleLocationZ = CapsuleLocation.Z;
	return FVector(LocationAtDistanceX, LocationAtDistanceY, CapsuleLocationZ);
	ABaseCharacter::SetActorLocation(CharacterLocation);
}

FRotator ABaseCharacter::SetCurrentCharacterRotation(FRotator CurrentRotation)
{
	FRotator RotationAtDistance = CameraSplinePath->CameraSpline->GetRotationAtDistanceAlongSpline(DistanceToMoveAlongSpline, ESplineCoordinateSpace::World);
	return FRotator(CurrentRotation);
}

void ABaseCharacter::Tick(float DeltaTime)
{
	SetLocalCharacterLocation(CharacterLocation);
	UE_LOG(LogTemp, Warning, TEXT("Character Location at: %s"), *CharacterLocation.ToString());
}













