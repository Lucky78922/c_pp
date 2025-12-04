#include "Characters/BaseInteractionActor.h"
ABaseInteractionActor::ABaseInteractionActor()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ABaseInteractionActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseInteractionActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

