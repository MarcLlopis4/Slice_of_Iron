// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "arbolprueba.generated.h"



UCLASS()


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
	void mejoraStamina(float PorcentajeStamina);
	void mejoraEspadona1(float PorcentajeEspadona);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
