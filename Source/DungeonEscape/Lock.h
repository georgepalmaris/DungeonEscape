// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TriggerComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Lock.generated.h"

UCLASS()
class DUNGEONESCAPE_API ALock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetIsKeyPlaced(bool NewIsKeyPlaced);
	bool GetIsKeyPlaced() const;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Lock")
	UStaticMeshComponent* KeyItemMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Lock")
	UTriggerComponent* TriggerComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Lock")
	FString KeyItemName;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Lock", meta = (AllowPrivateAccess = "true"))
	bool IsKeyPlaced = false;
};
