#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionInterface.generated.h"

UINTERFACE(MinimalAPI)
class UInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

class CPP_V2_API IInteractionInterface
{
	GENERATED_BODY()

public:
	virtual void Interact(AActor* Interactor) = 0;
};
