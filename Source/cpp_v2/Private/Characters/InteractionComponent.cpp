#include "Characters/InteractionComponent.h"
#include "Characters/InteractionInterface.h"
#include "DrawDebugHelpers.h"

UInteractionComponent::UInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UInteractionComponent::TryInteract(AActor* Interactor)
{
	if (!Interactor) return;

	FVector Start = Interactor->GetActorLocation();
	FVector Forward = Interactor->GetActorForwardVector();
	FVector End = Start + Forward * 200.f;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(Interactor);

	FHitResult Hit;
	float SphereRadius = 150.f;

	if (GetWorld()->SweepSingleByChannel(Hit, Start, End, FQuat::Identity, ECC_Visibility, FCollisionShape::MakeSphere(SphereRadius), Params))
	{
		AActor* HitActor = Hit.GetActor();
		if (HitActor && HitActor->GetClass()->ImplementsInterface(UInteractionInterface::StaticClass()))
		{
			IInteractionInterface* Interaction = Cast<IInteractionInterface>(HitActor);
			if (Interaction)
			{
				Interaction->Interact(Interactor);
			}
		}
	}
}