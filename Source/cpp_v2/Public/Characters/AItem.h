#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseInteractionActor.h"
#include "Characters/InteractionInterface.h"
#include "AItem.generated.h"

UCLASS()
class CPP_V2_API AItem : public ABaseInteractionActor, public IInteractionInterface
{
	GENERATED_BODY()

public:
	AItem() { PrimaryActorTick.bCanEverTick = false; }

	virtual void Interact(AActor* Interactor) override { PickUp(Interactor); }

protected:
	virtual void PickUp(AActor* Interactor) {}
};