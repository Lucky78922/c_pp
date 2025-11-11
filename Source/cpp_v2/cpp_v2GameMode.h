// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "cpp_v2GameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class Acpp_v2GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	Acpp_v2GameMode();
};



