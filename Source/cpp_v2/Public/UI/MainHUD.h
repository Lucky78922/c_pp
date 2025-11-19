#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainHUD.generated.h"

UCLASS()
class CPP_V2_API UMainHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent, Category = "HUD")
	void UpdateHealth(float Current, float Max);

	UFUNCTION(BlueprintImplementableEvent, Category = "HUD")
	void UpdateStamina(float Current, float Max);
};