// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

UCLASS()
class CPPBASE_API ACppBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ACppBaseActor();
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere);
	FString PlayerName = GetName();
	
	UPROPERTY(EditInstanceOnly);
	int EnemyNum = 20;

	UPROPERTY(EditInstanceOnly);
	bool IsAlive = true;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	void ShowActorInformation();

};
