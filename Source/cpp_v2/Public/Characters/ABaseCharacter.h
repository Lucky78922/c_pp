#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ABaseCharacter.generated.h"

class UAttributesComponent;
class AWeapon;

UENUM(BlueprintType)
enum class EPawnState : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	Combat UMETA(DisplayName = "Combat"),
	Hit UMETA(DisplayName = "Hit"),
	Dead UMETA(DisplayName = "Dead"),
	Exhausted UMETA(DisplayName = "Exhausted")
};

UCLASS()
class CPP_V2_API AABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AABaseCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAttributesComponent* Attributes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State")
	EPawnState CurrentState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Weapon)
	AWeapon* CurrentWeapon;

	UFUNCTION(BlueprintCallable)
	virtual void SetState(EPawnState NewState);

	UFUNCTION(BlueprintCallable)
	void SetWeaponCollision(bool bEnable);

protected:
	virtual void BeginPlay() override;
};