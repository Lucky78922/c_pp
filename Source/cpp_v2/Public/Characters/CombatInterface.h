#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CombatInterface.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UCombatInterface : public UInterface
{
	GENERATED_BODY()
};

class CPP_V2_API ICombatInterface
{
	GENERATED_BODY()

public:
	// Changed to BlueprintNativeEvent to allow Execute_GetHit calls
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combat")
	void GetHit(AActor* InstigatorActor, float Damage);
};