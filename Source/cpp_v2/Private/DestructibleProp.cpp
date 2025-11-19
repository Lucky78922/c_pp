#include "DestructibleProp.h"

ADestructibleProp::ADestructibleProp()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
}

// Changed to _Implementation
void ADestructibleProp::GetHit_Implementation(AActor* InstigatorActor, float Damage)
{
	HitPoints--;
	if (HitPoints <= 0)
	{
		Destroy();
	}
}