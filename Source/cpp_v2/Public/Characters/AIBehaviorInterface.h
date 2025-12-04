#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AIBehaviorInterface.generated.h"

UINTERFACE(MinimalAPI)
class UAIBehaviorInterface : public UInterface
{
	GENERATED_BODY()
};

class CPP_V2_API IAIBehaviorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AI")
	void PerformAttack();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AI")
	bool CanAIAtack();
};