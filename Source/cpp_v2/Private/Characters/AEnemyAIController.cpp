#include "Characters/AEnemyAIController.h"
#include "Characters/ABaseEnemyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Characters/AttributesComponent.h" 

AAEnemyAIController::AAEnemyAIController()
{
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));

	if (SightConfig)
	{
		SightConfig->SightRadius = 1000.0f;
		SightConfig->LoseSightRadius = 1200.0f;
		SightConfig->PeripheralVisionAngleDegrees = 60.0f;
		SightConfig->DetectionByAffiliation.bDetectEnemies = true;
		SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
		SightConfig->DetectionByAffiliation.bDetectFriendlies = true;

		PerceptionComponent->ConfigureSense(*SightConfig);
		PerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());
	}
}

void AAEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	if (PerceptionComponent)
	{
		PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AAEnemyAIController::OnTargetDetected);
	}
}

void AAEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AABaseEnemyCharacter* Enemy = Cast<AABaseEnemyCharacter>(InPawn);
	if (Enemy && Enemy->BehaviorTree)
	{
		RunBehaviorTree(Enemy->BehaviorTree);
	}
}

void AAEnemyAIController::OnTargetDetected(AActor* Actor, FAIStimulus Stimulus)
{
	if (!Actor->ActorHasTag("Player")) return;

	UBlackboardComponent* BB = GetBlackboardComponent();
	if (!BB) return;

	if (Stimulus.WasSuccessfullySensed())
	{
		BB->SetValueAsObject(TargetActorKey, Actor);
		 
		BB->ClearValue(LastKnownLocationKey);
	}
	else
	{
		BB->SetValueAsVector(LastKnownLocationKey, Actor->GetActorLocation());

		BB->ClearValue(TargetActorKey);
	}
}

void AAEnemyAIController::PerformAttack_Implementation()
{
	AABaseEnemyCharacter* Enemy = Cast<AABaseEnemyCharacter>(GetPawn());
	if (Enemy)
	{
		Enemy->TryAttack();
	}
}

bool AAEnemyAIController::CanAIAtack_Implementation()
{
	AABaseEnemyCharacter* Enemy = Cast<AABaseEnemyCharacter>(GetPawn());
	if (Enemy && Enemy->Attributes)
	{
		bool bCanPay = Enemy->Attributes->CanPayStamina(Enemy->Attributes->StaminaCosts.AttackCost);
		bool bNotHit = Enemy->CurrentState != EPawnState::Hit;
		bool bNotDead = Enemy->CurrentState != EPawnState::Dead;

		return bCanPay && bNotHit && bNotDead;
	}
	return false;
}