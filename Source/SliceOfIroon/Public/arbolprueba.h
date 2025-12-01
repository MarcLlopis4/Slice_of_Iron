

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/ActorComponent.h"
#include "arbolprueba.generated.h"


UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))


class SLICEOFIROON_API Aarbolprueba : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aarbolprueba();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Armas")
	UObject* partesdearma;

	

	UFUNCTION(BlueprintCallable,Category="Habilidades")
	void mejoraDaga1(float Porcentaje);
	UFUNCTION(BlueprintCallable,Category="Habilidades")
	void mejoraEspada1(float PorcentajeEspada);
	UFUNCTION(BlueprintCallable, Category="Habilidades")
	void mejoraEspadona1(float PorcentajeEspadona);


	virtual void Tick(float DeltaTime) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	

};
UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SLICEOFIROON_API UStatusComponent : public UActorComponent

{
	GENERATED_BODY()

public:
	UStatusComponent();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float MaxStamina = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float CurrentStamina = 0;
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void mejoraStamina1(float StaminaMejorada1);
};
