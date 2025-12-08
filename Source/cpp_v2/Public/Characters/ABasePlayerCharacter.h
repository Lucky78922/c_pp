#pragma once

#include "CoreMinimal.h"
#include "Characters/ABaseCharacter.h"
#include "InputActionValue.h"
#include "UI/MainHUD.h"
#include "ABasePlayerCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;
class UAnimMontage;
class UInteractionComponent;

UCLASS()
class CPP_V2_API AABasePlayerCharacter : public AABaseCharacter
{
	GENERATED_BODY()

public:
	AABasePlayerCharacter();

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UMainHUD> MainHUDClass;

	UPROPERTY()
	UMainHUD* HUDInstance;

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
	FTimerHandle AttackCooldownTimer;
	bool bCanAttack = true;

	void ResetAttack();
    virtual void SetState(EPawnState NewState) override;

	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	virtual void Jump() override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Interact();
	void Equip(AWeapon* Weapon);
	void Attack(const FInputActionValue& Value);

	UFUNCTION()
	void OnHealthUpdated(float Current, float Max);

	UFUNCTION()
	void OnStaminaUpdated(float Current, float Max);
};