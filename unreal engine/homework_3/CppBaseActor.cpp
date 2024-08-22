// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"

ACppBaseActor::ACppBaseActor()
{
	PrimaryActorTick.bCanEverTick = true;
	
}

void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	ShowActorInformation();
	
}

void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACppBaseActor::ShowActorInformation()
{
	
	UE_LOG(LogTemp, Display, TEXT("Instance name: %s"), *PlayerName);
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
}