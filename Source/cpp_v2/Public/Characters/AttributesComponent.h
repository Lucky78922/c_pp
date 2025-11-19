#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributesComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAttributeChangedSignature, float, CurrentValue, float, MaxValue);

USTRUCT(BlueprintType)
struct FStaminaCost
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttackCost = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float JumpCost = 15.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RegenRate = 5.f;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CPP_V2_API UAttributesComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAttributesComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float MaxHealth = 100.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float MaxStamina = 100.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Attributes")
	float CurrentStamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FStaminaCost StaminaCosts;

	UPROPERTY(BlueprintAssignable)
	FAttributeChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable)
	FAttributeChangedSignature OnStaminaChanged;

	bool CanPayStamina(float Cost) const;
	void PayStamina(float Cost);
	void ReceiveDamage(float Damage);

protected:
	virtual void BeginPlay() override;
	void RegenerateStamina(float DeltaTime);
};