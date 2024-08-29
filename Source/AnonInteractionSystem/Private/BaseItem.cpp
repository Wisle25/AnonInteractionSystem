// Copyright, Anon Creation Games

#include "BaseItem.h"

#include "InteractionInterface.h"

ABaseItem::ABaseItem()
{
	PrimaryActorTick.bCanEverTick = false;
	
}

// ==================== Lifecycles ==================== //

void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// ==================== Collision Events ==================== //

void ABaseItem::OnItemBeginOverlap(AActor* OtherActor)
{
	if (IInteractionInterface* InteractionInterface = Cast<IInteractionInterface>(OtherActor))
	{
		InteractionInterface->NotifyItem(this);
	}
}

void ABaseItem::OnItemEndOverlap(AActor* OtherActor)
{
	if (IInteractionInterface* InteractionInterface = Cast<IInteractionInterface>(OtherActor))
	{
		InteractionInterface->NotifyItem();
	}
}
