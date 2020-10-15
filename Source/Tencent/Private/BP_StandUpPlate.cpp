// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_StandUpPlate.h"

// Sets default values
ABP_StandUpPlate::ABP_StandUpPlate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	Plate = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plate"));
	Plate->SetupAttachment(RootComponent);

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(Plate);
	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly); //不阻挡
	TriggerBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	TriggerBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore); //忽略所有通道
	TriggerBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap); //只开启人物碰撞通道
}

// Called when the game starts or when spawned
void ABP_StandUpPlate::BeginPlay()
{
	Super::BeginPlay();

	InitialPlateLocation = Plate->GetComponentLocation();
}

// Called every frame
void ABP_StandUpPlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABP_StandUpPlate::NotifyActorBeginOverlap(AActor* otherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("Start")));
	RaisePlate();
}

void ABP_StandUpPlate::NotifyActorEndOverlap(AActor* otherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::Printf(TEXT("End")));
	LayPlate();
}

void ABP_StandUpPlate::UpdatePlateLocation(float delta)
{
	FVector NewLocation = InitialPlateLocation;
	NewLocation.Z += delta;
	Plate->SetWorldLocation(NewLocation);
}


