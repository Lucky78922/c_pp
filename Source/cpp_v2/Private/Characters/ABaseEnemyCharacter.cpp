#include "Characters/ABaseEnemyCharacter.h"
#include "Characters/AttributesComponent.h"
#include "Characters/AEnemyAIController.h" 
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/CapsuleComponent.h"

AABaseEnemyCharacter::AABaseEnemyCharacter()
{
}

void AABaseEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AABaseEnemyCharacter::GetHit_Implementation(AActor* InstigatorActor, float Damage)
{
	if (CurrentState == EPawnState::Dead) return;

	if (Attributes)
	{
		Attributes->ReceiveDamage(Damage);
		
		if (Attributes->GetHealth() <= 0)
		{
			Die();
			return;
		}
	}

	SetState(EPawnState::Hit);

	if (HitMontage)
	{
		PlayAnimMontage(HitMontage);
	}

	if (InstigatorActor)
	{
		FVector Direction = InstigatorActor->GetActorLocation() - GetActorLocation();
		Direction.Z = 0;
		SetActorRotation(Direction.Rotation());
	}
}

void AABaseEnemyCharacter::TryAttack()
{
	if (CurrentState == EPawnState::Dead || CurrentState == EPawnState::Hit) return;

	if (AttackMontage && Attributes)
	{
		if (Attributes->CanPayStamina(Attributes->StaminaCosts.AttackCost))
		{
			Attributes->PayStamina(Attributes->StaminaCosts.AttackCost);
			PlayAnimMontage(AttackMontage);
			SetState(EPawnState::Combat);
		}
	}
}

void AABaseEnemyCharacter::Die()
{
	SetState(EPawnState::Dead);
	if (DeathMontage) PlayAnimMontage(DeathMontage);
	
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	AAIController* AIC = Cast<AAIController>(GetController());
	if (AIC && AIC->GetBlackboardComponent())
	{
		AIC->GetBlackboardComponent()->SetValueAsBool("IsDead", true);
	}

	SetLifeSpan(5.0f);
}
