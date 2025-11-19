#include "Characters/ABaseCharacter.h"
#include "Characters/AttributesComponent.h"
#include "Characters/AWeapon.h"

AABaseCharacter::AABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	Attributes = CreateDefaultSubobject<UAttributesComponent>(TEXT("Attributes"));
	CurrentState = EPawnState::Idle;
}

void AABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AABaseCharacter::SetState(EPawnState NewState)
{
	CurrentState = NewState;
}

void AABaseCharacter::SetWeaponCollision(bool bEnable)
{
	if (CurrentWeapon)
	{
		if (bEnable) CurrentWeapon->EnableCollision();
		else CurrentWeapon->DisableCollision();
	}
}