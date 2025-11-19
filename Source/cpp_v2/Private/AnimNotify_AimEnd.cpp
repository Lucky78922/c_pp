#include "AnimNotify_AimEnd.h"
#include "Characters/ABaseCharacter.h"

void UAnimNotify_AimEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (!MeshComp || !MeshComp->GetOwner()) return;

	if (AABaseCharacter* Character = Cast<AABaseCharacter>(MeshComp->GetOwner()))
	{
		Character->SetWeaponCollision(false);
	}
}