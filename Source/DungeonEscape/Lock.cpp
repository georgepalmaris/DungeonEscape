// Fill out your copyright notice in the Description page of Project Settings.


#include "Lock.h"
#include "Components/SceneComponent.h"

// Sets default values
ALock::ALock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(SceneRoot);

	KeyItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("KeyItemMesh"));
	KeyItemMesh->SetupAttachment(SceneRoot);

	TriggerComponent = CreateDefaultSubobject<UTriggerComponent>(TEXT("TriggerComponent"));
	TriggerComponent->SetupAttachment(SceneRoot);

	Tags.Add("Lock");
}

// Called when the game starts or when spawned
void ALock::BeginPlay()
{
	Super::BeginPlay();
	
	SetIsKeyPlaced(false);
}

// Called every frame
void ALock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALock::SetIsKeyPlaced(bool NewIsKeyPlaced)
{
	IsKeyPlaced = NewIsKeyPlaced;

	TriggerComponent->Trigger(NewIsKeyPlaced);
	KeyItemMesh->SetVisibility(NewIsKeyPlaced);
}

bool ALock::GetIsKeyPlaced() const
{
	return IsKeyPlaced;
}

