#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Characters/CombatInterface.h"
#include "DestructibleProp.generated.h"

UCLASS()
class CPP_V2_API ADestructibleProp : public AActor, public ICombatInterface
{
	GENERATED_BODY()
	
public:	
	ADestructibleProp();
	
	// Important: Use _Implementation
	virtual void GetHit_Implementation(AActor* InstigatorActor, float Damage) override;

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, Category="Stats")
	int32 HitPoints = 2;
};