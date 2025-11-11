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

AABasePlayerCharacter::AABasePlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

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
}

void AABasePlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (MoveAction)   EIC->BindAction(MoveAction,   ETriggerEvent::Triggered, this, &AABasePlayerCharacter::Move);
		if (LookAction)   EIC->BindAction(LookAction,   ETriggerEvent::Triggered, this, &AABasePlayerCharacter::Look);
		if (JumpAction)   EIC->BindAction(JumpAction,   ETriggerEvent::Triggered, this, &ACharacter::Jump);
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
	FVector2D V = Value.Get<FVector2D>();
	if (Controller)
	{
		AddControllerYawInput(V.X * BaseTurnRate);
		AddControllerPitchInput(V.Y * BaseLookUpRate);
	}
}

void AABasePlayerCharacter::Interact()
{
	if (InteractionComponent) InteractionComponent->TryInteract(this);
}

void AABasePlayerCharacter::Equip(AWeapon* Weapon)
{
	if (!Weapon) return;
	CurrentWeapon = Weapon;

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
	if (CurrentWeapon && AttackMontage)
	{
		PlayAnimMontage(AttackMontage);
		CurrentWeapon->StartAttack();
	}
}