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
	 for (TFieldIterator<FProperty> Prop(partesdearma->GetClass()); Prop; ++Prop)
    {
        FProperty* LigerasProp = *Prop;

        if (FStructProperty* StructProp = CastField<FStructProperty>(LigerasProp))
        {
            void* LigerasData = StructProp->ContainerPtrToValuePtr<void>(partesdearma);

            // Buscamos dentro de Ligeras → Daga
            for (TFieldIterator<FProperty> SubProp(StructProp->Struct); SubProp; ++SubProp)
            {
                FProperty* DagaProp = *SubProp;

                if (FStructProperty* DagaStruct = CastField<FStructProperty>(DagaProp))
                {
                    void* DagaData = DagaStruct->ContainerPtrToValuePtr<void>(LigerasData);

                    // Dentro de Daga → buscamos Hoja y Empuñadura
                    for (TFieldIterator<FProperty> SubSubProp(DagaStruct->Struct); SubSubProp; ++SubSubProp)
                    {
                        FProperty* ParteProp = *SubSubProp;
                        

                        if (FStructProperty* ParteStruct = CastField<FStructProperty>(ParteProp))
                        {
                            void* ParteData = ParteStruct->ContainerPtrToValuePtr<void>(DagaData);

                            // Dentro de cada parte (Hoja de daga1,2,3 o Empuñadura)
                            for (TFieldIterator<FProperty> DamageProp(ParteStruct->Struct); DamageProp; ++DamageProp)
                            {
                                if (FFloatProperty* FloatProp = CastField<FFloatProperty>(*DamageProp))
                                {
                                    // Solo sube los que tengan "Damage" en el nombre
                                    if (FloatProp->GetName().Contains("Damage"))
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

}



