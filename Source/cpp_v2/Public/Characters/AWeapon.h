#pragma once
#include "CoreMinimal.h"
#include "AItem.h"
#include "AWeapon.generated.h"

class USceneComponent;
class UBoxComponent;

UCLASS()
class CPP_V2_API AWeapon : public AItem
{
	GENERATED_BODY()

public:
	AWeapon();

	USceneComponent* GetGripPoint() const { return GripPoint; }

	UFUNCTION() void StartAttack();
	UFUNCTION() void EnableCollision();
	UFUNCTION() void DisableCollision();

protected:
	virtual void PickUp(AActor* Interactor) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) USceneComponent* GripPoint;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) UBoxComponent* CollisionBox;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) USceneComponent* StartTrace;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) USceneComponent* EndTrace;

	UFUNCTION() void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};