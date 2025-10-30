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
void Aarbolprueba::mejoraEspada1(float PorcentajeEspada)
{
    float Factor = 1.0f + (PorcentajeEspada / 100.0f);
    if (FStructProperty*MedianasProp= FindFProperty<FStructProperty>(partesdearma->GetClass(), TEXT("medianas")))
    {
        void* MedianaData = MedianasProp->ContainerPtrToValuePtr<void>(partesdearma);

        if (FStructProperty* EspadaProp = FindFProperty<FStructProperty>(MedianasProp->Struct, TEXT("Espadas")))
        {
            void* EspadaData = EspadaProp->ContainerPtrToValuePtr<void>(MedianaData);
            
            for (TFieldIterator<FProperty> ParteProp(EspadaProp->Struct); ParteProp; ++ParteProp)
            {
                if (FStructProperty* ParteStruct = CastField<FStructProperty>(*ParteProp))
                {
                    FString ParteName = ParteStruct->GetName();
                    if (ParteName == TEXT("Espadas_Hojas_General") || ParteName == TEXT("Espadas_empuñaduas_General"))
                    {
                        void* ParteData = ParteStruct->ContainerPtrToValuePtr<void>(EspadaData);
                        
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

void Aarbolprueba::mejoraEspadona1(float PorcentajeEspadona)
{
    float Factor = 1.0f + (PorcentajeEspadona / 100.0f);
    if (FStructProperty*PesadaProp= FindFProperty<FStructProperty>(partesdearma->GetClass(), TEXT("pesadas")))
    {
        void* PesadaData = PesadaProp->ContainerPtrToValuePtr<void>(partesdearma);

        if (FStructProperty* DagaProp = FindFProperty<FStructProperty>(PesadaProp->Struct, TEXT("espadon")))
        {
            void* EspadaData = DagaProp->ContainerPtrToValuePtr<void>(PesadaData);
            
            for (TFieldIterator<FProperty> ParteProp(DagaProp->Struct); ParteProp; ++ParteProp)
            {
                if (FStructProperty* ParteStruct = CastField<FStructProperty>(*ParteProp))
                {
                    FString ParteName = ParteStruct->GetName();
                    if (ParteName == TEXT("Hoja_General_espadon") || ParteName == TEXT("Empuñadura_General_espadon1"))
                    {
                        void* ParteData = ParteStruct->ContainerPtrToValuePtr<void>(EspadaData);
                        
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
                    if (ParteName == TEXT("hojasdedaga") || ParteName == TEXT("EmpuñaduraDagas"))
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