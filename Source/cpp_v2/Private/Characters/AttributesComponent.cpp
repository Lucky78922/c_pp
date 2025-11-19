#include "Characters/AttributesComponent.h"

UAttributesComponent::UAttributesComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentHealth = MaxHealth;
	CurrentStamina = MaxStamina;
}

void UAttributesComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
	CurrentStamina = MaxStamina;
}

void UAttributesComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	RegenerateStamina(DeltaTime);
}

bool UAttributesComponent::CanPayStamina(float Cost) const
{
	return CurrentStamina >= Cost;
}

void UAttributesComponent::PayStamina(float Cost)
{
	CurrentStamina = FMath::Clamp(CurrentStamina - Cost, 0.f, MaxStamina);
	OnStaminaChanged.Broadcast(CurrentStamina, MaxStamina);
}

void UAttributesComponent::ReceiveDamage(float Damage)
{
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.f, MaxHealth);
	OnHealthChanged.Broadcast(CurrentHealth, MaxHealth);
}

void UAttributesComponent::RegenerateStamina(float DeltaTime)
{
	if (CurrentStamina < MaxStamina)
	{
		CurrentStamina += StaminaCosts.RegenRate * DeltaTime;
		CurrentStamina = FMath::Clamp(CurrentStamina, 0.f, MaxStamina);
		OnStaminaChanged.Broadcast(CurrentStamina, MaxStamina);
	}
}