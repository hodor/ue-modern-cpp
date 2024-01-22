// Copyright 2024 Rogerio Gasi
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <utility>
#include "StructuredBindingActor.generated.h"

UCLASS()
class CPP17_API AStructuredBindingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStructuredBindingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};


// Let's do it in a struct
USTRUCT()
struct CPP17_API FStructuredBindReadOnlyAPI
{
	GENERATED_BODY()

	FStructuredBindReadOnlyAPI(const TObjectPtr<UStaticMesh> InStaticMesh, const int InSomeNumber, const FName InSomeFName)
		:StaticMesh(InStaticMesh), SomeNumber(InSomeNumber), SomeName(InSomeFName)
	{}

	FStructuredBindReadOnlyAPI()
		:StaticMesh(nullptr), SomeNumber(0), SomeName(FName(TEXT("")))
	{}
	~FStructuredBindReadOnlyAPI(){}

	TObjectPtr<UStaticMesh> GetStaticMesh() const
	{
		return StaticMesh;
	}
	int GetSomeNumber() const
	{
		return SomeNumber;
	}

	FName GetSomeName() const
	{
		return SomeName;
	}


private:
	UPROPERTY()
	TObjectPtr<UStaticMesh> StaticMesh;

	UPROPERTY()
	int SomeNumber;

	UPROPERTY()
	FName SomeName;

};

// Template code for FStructuredBindReadOnlyAPI
template<>
struct std::tuple_size<FStructuredBindReadOnlyAPI>
{
	static constexpr int value = 3;
};

template<>
struct std::tuple_element<0, FStructuredBindReadOnlyAPI>
{
	using type = TObjectPtr<UStaticMesh>;
};

template<>
struct std::tuple_element<2, FStructuredBindReadOnlyAPI>
{
	using type = FName;
};

template<std::size_t Idx>
struct std::tuple_element<Idx, FStructuredBindReadOnlyAPI>
{
	using type = int;
};

template<std::size_t> auto get(const FStructuredBindReadOnlyAPI& Temp);
template<> auto get<0>(const FStructuredBindReadOnlyAPI& Temp) { return Temp.GetStaticMesh(); }
template<> auto get<1>(const FStructuredBindReadOnlyAPI& Temp) { return Temp.GetSomeNumber(); }
template<> auto get<2>(const FStructuredBindReadOnlyAPI& Temp) { return Temp.GetSomeName(); }