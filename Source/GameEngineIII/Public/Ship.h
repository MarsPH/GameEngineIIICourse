// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Components/BillboardComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "Ship.generated.h"


UCLASS()
class GAMEENGINEIII_API AShip : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UCapsuleComponent *Capsule;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent *DebugMesh;

	UPROPERTY(EditAnywhere)
	UBillboardComponent *Billboard;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USpringArmComponent> SpringArm;


public:	
	// Sets default values for this actor's properties
	AShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
