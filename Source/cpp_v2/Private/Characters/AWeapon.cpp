#include "Characters/AWeapon.h"
#include "Characters/ABasePlayerCharacter.h"
#include "Components/BoxComponent.h"
#include "Characters/CombatInterface.h"
#include "DrawDebugHelpers.h"

AWeapon::AWeapon()
{
	GripPoint = CreateDefaultSubobject<USceneComponent>(TEXT("GripPoint"));
	GripPoint->SetupAttachment(RootComponent);

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(GripPoint);
	CollisionBox->SetBoxExtent(FVector(10.f, 10.f, 80.f));
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CollisionBox->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	CollisionBox->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap); 
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AWeapon::OnOverlapBegin);

	StartTrace = CreateDefaultSubobject<USceneComponent>(TEXT("StartTrace"));
	StartTrace->SetupAttachment(GripPoint);
	StartTrace->SetRelativeLocation(FVector(0.f, 0.f, 0.f));

	EndTrace = CreateDefaultSubobject<USceneComponent>(TEXT("EndTrace"));
	EndTrace->SetupAttachment(GripPoint);
	EndTrace->SetRelativeLocation(FVector(100.f, 0.f, 0.f));
}

void AWeapon::PickUp(AActor* Interactor)
{
	if (AABasePlayerCharacter* Player = Cast<AABasePlayerCharacter>(Interactor))
		Player->Equip(this);
}

void AWeapon::StartAttack() { }

void AWeapon::EnableCollision()
{
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void AWeapon::DisableCollision()
{
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AWeapon::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor || OtherActor == this || OtherActor == GetOwner()) return;

	FHitResult Hit;
	const FVector Start = StartTrace->GetComponentLocation();
	const FVector End = EndTrace->GetComponentLocation();

	bool bHit = GetWorld()->SweepSingleByChannel(
		Hit, Start, End, FQuat::Identity, ECC_Pawn,
		FCollisionShape::MakeBox(CollisionBox->GetScaledBoxExtent())
	);

	if (bHit && Hit.GetActor())
	{
		if (Hit.GetActor()->Implements<UCombatInterface>())
		{
			ICombatInterface::Execute_GetHit(Hit.GetActor(), GetOwner(), 10.f);
		}
		DrawDebugPoint(GetWorld(), Hit.Location, 10.f, FColor::Red, false, 2.f);
	}
}