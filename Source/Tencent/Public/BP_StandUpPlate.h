// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Runtime/Engine/Classes/Components/BoxComponent.h>
#include "BP_StandUpPlate.generated.h"

UCLASS()
class TENCENT_API ABP_StandUpPlate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABP_StandUpPlate();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated)
	UBoxComponent* TriggerBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated)
	UStaticMeshComponent* Plate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//FVector InitialPlateLocation;

	virtual void NotifyActorBeginOverlap(AActor* otherActor) override;
	virtual void NotifyActorEndOverlap(AActor* otherActor) override;

	UPROPERTY(BlueprintReadWrite)
	FVector InitialPlateLocation;

	UFUNCTION(BlueprintImplementableEvent)
	void RaisePlate();

	UFUNCTION(BlueprintImplementableEvent)
	void LayPlate();

	UFUNCTION(BlueprintCallable)
	void UpdatePlateLocation(float delta);

};