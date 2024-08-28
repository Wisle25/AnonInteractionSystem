// Copyright, Anon Creation Games

#include "InventoryComponent.h"

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

void UInventoryComponent::AddItem(UItemData* NewItem)
{
	// Get the data
	TArray<UItemData*>& ItemsData = GetItemsAtType(NewItem->ItemType);

	// Check is the item already exists
	for (const auto& Item : ItemsData)
	{
		// Already exists and less than capacity, then just add the item count
		if (Item->ItemName == NewItem->ItemName && Item->ItemCount < MaxCapacity)
		{
			++Item->ItemCount;
			
			// Delegate
			OnItemAdded.Broadcast(NewItem->ItemName, NewItem->ItemIcon);
			
			return;
		}
	}

	// Item is not existsed yet, then just add
	ItemsData.Add(NewItem);

	// Delegate
	OnItemAdded.Broadcast(NewItem->ItemName, NewItem->ItemIcon);
}

int32 UInventoryComponent::ItemIsExists(const FName& ItemName)
{
	for (const auto& Item :Items)
	{
		TArray<UItemData*> ItemData = Item.Value.Data;

		for (const auto& Data : ItemData)
		{
			if (Data->ItemName == ItemName)
				return Data->ItemCount;
		}
	}
	
	return -1;
}
