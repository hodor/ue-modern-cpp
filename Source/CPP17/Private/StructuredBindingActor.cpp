// Copyright 2024 Rogerio Gasi
#include "StructuredBindingActor.h"

// Sets default values
AStructuredBindingActor::AStructuredBindingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FStructuredBindReadOnlyAPI ReadOnlyBind = FStructuredBindReadOnlyAPI(nullptr, 20, TEXT("Testing the readonly bind"));
	const auto& [mesh, number, name] = ReadOnlyBind;

	UE_LOG(LogTemp, Log, TEXT("FStructuredBindReadOnlyAPI Name: %s"), *name.ToString());
	UE_LOG(LogTemp, Log, TEXT("FStructuredBindReadOnlyAPI Number: %d"), number);

}

// Called when the game starts or when spawned
void AStructuredBindingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStructuredBindingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}