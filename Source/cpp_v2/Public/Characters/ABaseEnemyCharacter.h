#pragma once

#include "CoreMinimal.h"
#include "Characters/ABaseCharacter.h"
#include "Characters/CombatInterface.h"
#include "ABaseEnemyCharacter.generated.h"

UCLASS()
class CPP_V2_API AABaseEnemyCharacter : public AABaseCharacter, public ICombatInterface
{
	GENERATED_BODY()

public:
	AABaseEnemyCharacter();

	// Important: Use _Implementation for BlueprintNativeEvents
	virtual void GetHit_Implementation(AActor* InstigatorActor, float Damage) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UAnimMontage* HitMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UAnimMontage* DeathMontage;

	void Die();
};