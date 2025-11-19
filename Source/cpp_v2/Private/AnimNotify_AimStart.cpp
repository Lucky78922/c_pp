#include "AnimNotify_AimStart.h"
#include "Characters/ABaseCharacter.h"

void UAnimNotify_AimStart::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (!MeshComp || !MeshComp->GetOwner()) return;

	if (AABaseCharacter* Character = Cast<AABaseCharacter>(MeshComp->GetOwner()))
	{
		Character->SetWeaponCollision(true);
	}
}