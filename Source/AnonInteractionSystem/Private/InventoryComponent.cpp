// Copyright, Anon Creation Games

#include "InventoryComponent.h"

#include "BaseItem.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	// Init Items but ofc its empty
	Items.Add(EItemType::AttackBoost, FItemHandle());
	Items.Add(EItemType::DefenceBoost, FItemHandle());
	Items.Add(EItemType::HealthProvisions, FItemHandle());
	Items.Add(EItemType::ManaProvisions, FItemHandle());
	Items.Add(EItemType::StaminaProvisions, FItemHandle());
	Items.Add(EItemType::UniqueItem, FItemHandle());
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UInventoryComponent::AddItem(ABaseItem* NewItem)
{
	// Get Item Data then destroy the actor 
	UItemData* ItemData = NewItem->GetItemData();
	NewItem->Destroy();
	
	// Get the data
	TArray<UItemData*>& Data = GetItemsAtType(ItemData->ItemType);

	// Check is the item already exists
	for (int32 I = 0; I < Data.Num(); ++I)
	{
		// Already exists and less than capacity, then just add the item count
		if (Data[I]->ItemName == ItemData->ItemName && GetItemCountItems(ItemData->ItemType, I) < MaxCapacity)
		{
			AddItemCount(ItemData->ItemType, I);
			
			// Delegate
			OnItemAdded.Broadcast(ItemData->ItemName, ItemData->ItemIcon);
			
			return;
		}
	}

	// Item is not existsed yet, then just add
	Data.Add(ItemData);
	Items[ItemData->ItemType].ItemCount.Add(1);

	// Delegate
	OnItemAdded.Broadcast(ItemData->ItemName, ItemData->ItemIcon);
}

int32 UInventoryComponent::ItemIsExists(const FName& ItemName)
{
	for (const auto& Item :Items)
	{
		TArray<UItemData*> ItemData = Item.Value.Data;

		for (int32 I = 0; I < ItemData.Num(); ++I)
		{
			if (ItemData[I]->ItemName == ItemName)
				return GetItemCountItems(ItemData[I]->ItemType, I);
		}
	}
	
	return -1;
}
