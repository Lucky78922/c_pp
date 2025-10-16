// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "c_ppGameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class Ac_ppGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	Ac_ppGameMode();
};



