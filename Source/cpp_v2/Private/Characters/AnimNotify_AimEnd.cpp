#include "Characters/AnimNotify_AimEnd.h"
#include "Characters/ABasePlayerCharacter.h"
#include "Characters/AWeapon.h"

void UAnimNotify_AimEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (AABasePlayerCharacter* Player = Cast<AABasePlayerCharacter>(MeshComp->GetOwner()))
		if (AWeapon* Weapon = Player->CurrentWeapon)
			Weapon->EnableCollision();
}