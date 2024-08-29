// Copyright, Anon Creation Games

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionInterface.generated.h"

class ABaseItem;

// This class does not need to be modified.
UINTERFACE()
class UInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

class ANONINTERACTIONSYSTEM_API IInteractionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/** Should notify the player if player has overlapped or WAS overlapped */
	virtual void NotifyItem(const ABaseItem* Item = nullptr) = 0;
};
