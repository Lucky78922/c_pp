#include "Characters/ABaseEnemyCharacter.h"
#include "Characters/AttributesComponent.h"
#include "Components/CapsuleComponent.h"

AABaseEnemyCharacter::AABaseEnemyCharacter()
{
}

void AABaseEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Changed to _Implementation
void AABaseEnemyCharacter::GetHit_Implementation(AActor* InstigatorActor, float Damage)
{
	if (CurrentState == EPawnState::Dead) return;

	if (Attributes)
	{
		Attributes->ReceiveDamage(Damage);
		
		// --- ZMIANA TUTAJ ---
		// BYŁO: if (Attributes->CurrentHealth <= 0)
		if (Attributes->GetHealth() <= 0)
		// --------------------
		{
			Die();
			return;
		}
	}

	// ... reszta funkcji bez zmian ...
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

void AABaseEnemyCharacter::Die()
{
	SetState(EPawnState::Dead);
	if (DeathMontage)
	{
		PlayAnimMontage(DeathMontage);
	}
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SetLifeSpan(5.0f);
}