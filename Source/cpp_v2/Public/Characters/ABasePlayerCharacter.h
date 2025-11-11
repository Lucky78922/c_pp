#pragma once

#include "CoreMinimal.h"
#include "Characters/ABaseCharacter.h"
#include "InputActionValue.h"
#include "Characters/InteractionComponent.h"
#include "Characters/AWeapon.h"
#include "ABasePlayerCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class UAnimMontage;

UCLASS()
class CPP_V2_API AABasePlayerCharacter : public AABaseCharacter
{
	GENERATED_BODY()

public:
	AABasePlayerCharacter();

	// --- PUBLIC ---
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Attack)
	UAnimMontage* AttackMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputAction* EquipAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Input)
	UInputAction* AttackAction;

	// --- CURRENT WEAPON — PUBLIC! ---
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Weapon)
	AWeapon* CurrentWeapon;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Interaction)
	UInteractionComponent* InteractionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
	float BaseTurnRate = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
	float BaseLookUpRate = 1.f;

	// --- FUNCTIONS ---
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Interact();
	void Equip(AWeapon* Weapon);
	void Attack(const FInputActionValue& Value);
};