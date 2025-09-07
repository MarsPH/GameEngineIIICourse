// Fill out your copyright notice in the Description page of Project Settings.


#include "Ship.h"

#include "MovieSceneTracksComponentTypes.h"
#include "Components/BoxComponent.h"


// Sets default values
AShip::AShip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	
	SetRootComponent(Capsule);// sets the capsule as root
	
	DebugMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	DebugMesh->SetupAttachment(GetRootComponent());// attaches debug mesh to root

	Billboard = CreateDefaultSubobject<UBillboardComponent>(TEXT("Billboard"));
	
	//UStaticMesh *MeshRef = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Engine/StaticMesh'/Engine/BasicShapes/Cone.Cone")).Object;
	// Hard codded reference example:
	//DebugMesh->SetStaticMesh(MeshRef);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));// with create a
	SpringArm->SetupAttachment(DebugMesh);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

}

// Called when the game starts or when spawned
void AShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

