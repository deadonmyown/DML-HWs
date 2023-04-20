// Fill out your copyright notice in the Description page of Project Settings.


#include "EnhancedPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AEnhancedPlayerController::BeginPlay()
{
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if(Subsystem)
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void AEnhancedPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	auto EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if(EnhancedInputComponent)
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AEnhancedPlayerController::MovePawn);
		EnhancedInputComponent->BindAction(RotateAction, ETriggerEvent::Triggered, this, &AEnhancedPlayerController::RotatePawn);
	}
}

void AEnhancedPlayerController::MovePawn(const FInputActionValue& ActionValue)
{
	if(!GetPawn()) return;
	auto DirectionX = ActionValue[0];
	auto DirectionY = ActionValue[1];

	if(DirectionX != 0.0f)
	{
		GetPawn()->AddMovementInput(GetPawn()->GetActorRightVector(), DirectionX);
	}
	if(DirectionY != 0.0f)
	{
		GetPawn()->AddMovementInput(GetPawn()->GetActorForwardVector(), DirectionY);
	}
}

void AEnhancedPlayerController::RotatePawn(const FInputActionValue& ActionValue)
{
	if(!GetPawn()) return;
	auto DirectionX = ActionValue[0];
	auto DirectionY = ActionValue[1];

	if(DirectionX != 0.0f)
	{
		GetPawn()->AddControllerYawInput(DirectionX);
	}
	if(DirectionY != 0.0f)
	{
		GetPawn()->AddControllerPitchInput(DirectionY);
	}
}




