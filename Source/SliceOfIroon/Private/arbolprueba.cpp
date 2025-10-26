// Fill out your copyright notice in the Description page of Project Settings.


#include "arbolprueba.h"
#include "UObject/UnrealType.h"

// Sets default values
Aarbolprueba::Aarbolprueba()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Aarbolprueba::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Aarbolprueba::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Aarbolprueba::mejoraDaga1(float Porcentaje)
{
    float Factor = 1.0f + (Porcentaje / 100.0f);
   
    if (FStructProperty* LigerasProp = FindFProperty<FStructProperty>(partesdearma->GetClass(), TEXT("Ligeras")))
    {
        void* LigerasData = LigerasProp->ContainerPtrToValuePtr<void>(partesdearma);

        if (FStructProperty* DagaProp = FindFProperty<FStructProperty>(LigerasProp->Struct, TEXT("Daga")))
        {
            void* DagaData = DagaProp->ContainerPtrToValuePtr<void>(LigerasData);
            
            for (TFieldIterator<FProperty> ParteProp(DagaProp->Struct); ParteProp; ++ParteProp)
            {
                if (FStructProperty* ParteStruct = CastField<FStructProperty>(*ParteProp))
                {
                    FString ParteName = ParteStruct->GetName();
                    if (ParteName == TEXT("Hoja") || ParteName == TEXT("Empuñadura"))
                    {
                        void* ParteData = ParteStruct->ContainerPtrToValuePtr<void>(DagaData);
                        
                        for (TFieldIterator<FProperty> DamageProp(ParteStruct->Struct); DamageProp; ++DamageProp)
                        {
                            if (FFloatProperty* FloatProp = CastField<FFloatProperty>(*DamageProp))
                            {
                                if (FloatProp->GetName().Contains(TEXT("Damage")))
                                {
                                    float ValorActual = FloatProp->GetPropertyValue_InContainer(ParteData);
                                    float NuevoValor = ValorActual * Factor;
                                    FloatProp->SetPropertyValue_InContainer(ParteData, NuevoValor);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}