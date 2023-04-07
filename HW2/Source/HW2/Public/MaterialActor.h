// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MaterialActor.generated.h"

UCLASS()
class HW2_API AMaterialActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMaterialActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float ColorInterval;
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	float MetallicInterval;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* ColorStaticMesh;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* MetallicStaticMesh;

	UPROPERTY()
	UMaterialInstanceDynamic* ColorDynamicMaterial;
	UPROPERTY()
	UMaterialInstanceDynamic* MetallicDynamicMaterial;

	UPROPERTY(EditDefaultsOnly)
	UMaterialInterface* ColorMaterialBase;
	UPROPERTY(EditDefaultsOnly)
	UMaterialInterface* MetallicMaterialBase;

	FTimerHandle ColorTimerHandle;
	FTimerHandle MetallicTimerHandle;

	FLinearColor NewColor;
	FLinearColor OldColor;

	float NewMetallic;
	float OldMetallic;

	int ColorRepeatingCalls;
	int MetallicRepeatingCalls;

	void ChangeColor();
	void ChangeMetallic();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
