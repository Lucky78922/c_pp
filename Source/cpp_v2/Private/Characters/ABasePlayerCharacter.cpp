#include "Characters/ABasePlayerCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Characters/InteractionComponent.h"
#include "Characters/AWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Characters/AttributesComponent.h"

AABasePlayerCharacter::AABasePlayerCharacter()
{
	InteractionComponent = CreateDefaultSubobject<UInteractionComponent>(TEXT("InteractionComponent"));

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	bUseControllerRotationYaw = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;
}

void AABasePlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocallyControlled() && MainHUDClass)
	{
		APlayerController* PC = Cast<APlayerController>(GetController());
		if (PC)
		{
			HUDInstance = CreateWidget<UMainHUD>(PC, MainHUDClass);
			if (HUDInstance)
			{
				HUDInstance->AddToViewport();
				HUDInstance->UpdateHealth(Attributes->CurrentHealth, Attributes->MaxHealth);
				HUDInstance->UpdateStamina(Attributes->CurrentStamina, Attributes->MaxStamina);
			}
		}
	}

	if (Attributes)
	{
		Attributes->OnHealthChanged.AddDynamic(this, &AABasePlayerCharacter::OnHealthUpdated);
		Attributes->OnStaminaChanged.AddDynamic(this, &AABasePlayerCharacter::OnStaminaUpdated);
	}
}

void AABasePlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (MoveAction)   EIC->BindAction(MoveAction,   ETriggerEvent::Triggered, this, &AABasePlayerCharacter::Move);
		if (LookAction)   EIC->BindAction(LookAction,   ETriggerEvent::Triggered, this, &AABasePlayerCharacter::Look);
		if (JumpAction)   EIC->BindAction(JumpAction,   ETriggerEvent::Triggered, this, &AABasePlayerCharacter::Jump);
		if (EquipAction)  EIC->BindAction(EquipAction,  ETriggerEvent::Triggered, this, &AABasePlayerCharacter::Interact);
		if (AttackAction) EIC->BindAction(AttackAction, ETriggerEvent::Triggered, this, &AABasePlayerCharacter::Attack);
	}

	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (ULocalPlayer* LP = PC->GetLocalPlayer())
		{
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LP->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				if (MappingContext) Subsystem->AddMappingContext(MappingContext, 0);
			}
		}
	}
}

void AABasePlayerCharacter::Move(const FInputActionValue& Value)
{
	if (CurrentState == EPawnState::Dead || CurrentState == EPawnState::Hit) return;

	FVector2D V = Value.Get<FVector2D>();
	if (Controller && !V.IsNearlyZero())
	{
		const FRotator Yaw(0.f, Controller->GetControlRotation().Yaw, 0.f);
		AddMovementInput(FRotationMatrix(Yaw).GetUnitAxis(EAxis::X), V.Y);
		AddMovementInput(FRotationMatrix(Yaw).GetUnitAxis(EAxis::Y), V.X);
	}
}

void AABasePlayerCharacter::Look(const FInputActionValue& Value)
{
	if (CurrentState == EPawnState::Dead) return;

	FVector2D V = Value.Get<FVector2D>();
	if (Controller)
	{
		AddControllerYawInput(V.X * BaseTurnRate);
		AddControllerPitchInput(V.Y * BaseLookUpRate);
	}
}

void AABasePlayerCharacter::Jump()
{
	if (CurrentState == EPawnState::Dead || CurrentState == EPawnState::Hit) return;

	if (Attributes && Attributes->CanPayStamina(Attributes->StaminaCosts.JumpCost))
	{
		Attributes->PayStamina(Attributes->StaminaCosts.JumpCost);
		Super::Jump();
	}
}

void AABasePlayerCharacter::Interact()
{
	if (CurrentState == EPawnState::Dead) return;
	if (InteractionComponent) InteractionComponent->TryInteract(this);
}

void AABasePlayerCharacter::Equip(AWeapon* Weapon)
{
	if (!Weapon) return;
	CurrentWeapon = Weapon;
	CurrentWeapon->SetOwner(this);
	SetState(EPawnState::Combat);

	const FName Socket = TEXT("WeaponSocket");
	USceneComponent* Grip = Weapon->GetGripPoint();
	if (Grip) Grip->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, Socket);
	else      Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, Socket);

	if (UPrimitiveComponent* Prim = Cast<UPrimitiveComponent>(Weapon->GetRootComponent()))
	{
		Prim->SetSimulatePhysics(false);
		Prim->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void AABasePlayerCharacter::Attack(const FInputActionValue& Value)
{
	if (CurrentState == EPawnState::Dead || CurrentState == EPawnState::Hit) return;

	if (CurrentWeapon && AttackMontage)
	{
		if (Attributes && Attributes->CanPayStamina(Attributes->StaminaCosts.AttackCost))
		{
			Attributes->PayStamina(Attributes->StaminaCosts.AttackCost);
			PlayAnimMontage(AttackMontage);
			CurrentWeapon->StartAttack();
		}
	}
}

void AABasePlayerCharacter::OnHealthUpdated(float Current, float Max)
{
	if (HUDInstance) HUDInstance->UpdateHealth(Current, Max);
	if (Current <= 0) SetState(EPawnState::Dead);
}

void AABasePlayerCharacter::OnStaminaUpdated(float Current, float Max)
{
	if (HUDInstance) HUDInstance->UpdateStamina(Current, Max);
}