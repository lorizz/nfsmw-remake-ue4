// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NFSMW_RemasterGameModeBase.generated.h"

UCLASS()
class NFSMW_REMASTER_API ANFSMW_RemasterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};
