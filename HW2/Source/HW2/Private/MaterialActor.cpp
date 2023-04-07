// Fill out your copyright notice in the Description page of Project Settings.


#include "MaterialActor.h"

// Sets default values
AMaterialActor::AMaterialActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ColorRepeatingCalls = 5;
	MetallicRepeatingCalls = 5;
	NewColor = FLinearColor::Blue;
	OldColor = FLinearColor::Red;
	NewMetallic = 1.0f;
	OldMetallic = 0.0f;
	ColorStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("ColorStaticMesh");
	MetallicStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("MetallicStaticMesh");
}

// Called when the game starts or when spawned
void AMaterialActor::BeginPlay()
{
	Super::BeginPlay();
	ColorDynamicMaterial = ColorStaticMesh->CreateDynamicMaterialInstance(0, ColorMaterialBase);
	MetallicDynamicMaterial = MetallicStaticMesh->CreateDynamicMaterialInstance(0, MetallicMaterialBase);
	GetWorldTimerManager().SetTimer(MetallicTimerHandle, this, &AMaterialActor::ChangeMetallic, MetallicInterval, true, 1.0f);
	GetWorldTimerManager().SetTimer(ColorTimerHandle, this, &AMaterialActor::ChangeColor, ColorInterval, true);
}

// Called every frame
void AMaterialActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMaterialActor::ChangeColor()
{
	ColorDynamicMaterial->SetVectorParameterValue("Color", NewColor);
	FLinearColor tempColor = NewColor;
	NewColor = OldColor;
	OldColor = tempColor;
	ColorRepeatingCalls--;
	if(ColorRepeatingCalls <= 0)
	{
		GetWorldTimerManager().ClearTimer(ColorTimerHandle);
	}
}

void AMaterialActor::ChangeMetallic()
{
	MetallicDynamicMaterial->SetScalarParameterValue("Metallic", NewMetallic);
	float tempMetallic = OldMetallic;
	OldMetallic = NewMetallic;
	NewMetallic = tempMetallic;
	MetallicRepeatingCalls--;
	if(MetallicRepeatingCalls <= 0)
	{
		GetWorldTimerManager().ClearTimer(MetallicTimerHandle);
	}
}