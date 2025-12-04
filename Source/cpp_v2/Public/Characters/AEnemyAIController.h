#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "Characters/AIBehaviorInterface.h"
#include "AEnemyAIController.generated.h"

class UAISenseConfig_Sight;

UCLASS()
class CPP_V2_API AAEnemyAIController : public AAIController, public IAIBehaviorInterface
{
	GENERATED_BODY()

public:
	AAEnemyAIController();

protected:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
	UAISenseConfig_Sight* SightConfig;

	UFUNCTION()
	void OnTargetDetected(AActor* Actor, FAIStimulus Stimulus);

public:
	virtual void PerformAttack_Implementation() override;
	virtual bool CanAIAtack_Implementation() override;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName TargetActorKey = "TargetActor";

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName LastKnownLocationKey = "LastKnownPlayerLocation";

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	FName IsDeadKey = "IsDead";
};