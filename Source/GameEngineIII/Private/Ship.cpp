// Fill out your copyright notice in the Description page of Project Settings.


#include "Ship.h"

#include "MovieSceneTracksComponentTypes.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetSystemLibrary.h"



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

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));//creats the sub object of floating pawn movement and assign it to Movemement pointer

	ProjectileClass = nullptr;

}

void AShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) //automatically generated from IDE
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent *EIC = Cast <UEnhancedInputComponent>(PlayerInputComponent);
	
	EIC->BindAction(HonkAction, ETriggerEvent::Triggered, this, &AShip::Honk); // so everytime bind action is player. it plays honk function
	
	
	
}

void AShip::Honk(const FInputActionValue& InputActionValue)
{
	UKismetSystemLibrary::PrintString(this, TEXT ("HONK!!!!"));
}
void AShip::Shoot()
{
	UKismetSystemLibrary::PrintString(this, TEXT("SHOOT"));

	UWorld* World = GetWorld();

	FVector SpawnLocation = GetActorLocation();
	FRotator SpawnRotation = GetActorRotation();
	SpawnRotation.Pitch = 0.0;
	SpawnRotation.Roll = 0.0;

	
	FActorSpawnParameters SpawnParameters = FActorSpawnParameters();
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
	World->SpawnActor<AActor>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParameters);
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

