#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Characters/ABaseCharacter.h" // Potrzebne dla EPawnState
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

	// Nowa funkcja do wyświetlania stanu
	UFUNCTION(BlueprintImplementableEvent, Category = "HUD")
	void UpdatePlayerState(EPawnState NewState);
};