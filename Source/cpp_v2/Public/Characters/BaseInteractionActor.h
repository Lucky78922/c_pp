#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseInteractionActor.generated.h"

UCLASS()
class CPP_V2_API ABaseInteractionActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseInteractionActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
