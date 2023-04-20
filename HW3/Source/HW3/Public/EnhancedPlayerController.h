// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "EnhancedPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class HW3_API AEnhancedPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly)
	class UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly)
	class UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly)
	UInputAction* RotateAction;

	void MovePawn(const FInputActionValue& ActionValue);
	void RotatePawn(const FInputActionValue& ActionValue);
};
