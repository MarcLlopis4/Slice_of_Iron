// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "partesArmas.generated.h"

USTRUCT(BlueprintType)

struct FDAGA
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float damagebase;

	UPROPERTY(editanywhere, BlueprintReadWrite)
	FString Name;

	void mejoraDAGA(float porcentaje)
	{
		damagebase *=(1+porcentaje);
	}
};


