#pragma once

#include "CoreMinimal.h"
#include "Characters/ABaseCharacter.h"
#include "Characters/CombatInterface.h"
#include "ABaseEnemyCharacter.generated.h"

class UBehaviorTree;

UCLASS()
class CPP_V2_API AABaseEnemyCharacter : public AABaseCharacter, public ICombatInterface
{
	GENERATED_BODY()

public:
	AABaseEnemyCharacter();

	UPROPERTY(EditAnywhere, Category = "AI")
	UBehaviorTree* BehaviorTree;
    
    UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UAnimMontage* AttackMontage;

	virtual void GetHit_Implementation(AActor* InstigatorActor, float Damage) override;

	void TryAttack();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UAnimMontage* HitMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	UAnimMontage* DeathMontage;

	void Die();
};