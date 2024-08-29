// Copyright, Anon Creation Games

#pragma once

#include "CoreMinimal.h"
#include "InteractionType.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class ABaseItem;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemAddedSignature, FName, ItemName, UTexture2D*, ItemIcon);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ANONINTERACTIONSYSTEM_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInventoryComponent();

	// ==================== Lifecycles ==================== //
	
	virtual void BeginPlay() override;

	// ==================== Delegates ==================== //

	UPROPERTY(BlueprintAssignable)
	FOnItemAddedSignature OnItemAdded;

protected:
	// ==================== Items ==================== //
	
	UPROPERTY(BlueprintReadOnly)
	TMap<EItemType, FItemHandle> Items;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE TArray<UItemData*>& GetItemsAtType(EItemType Type)
	{
		return Items.Find(Type)->Data;
	}

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE int32 GetItemCountItems(EItemType Type, int32 Idx)
	{
		return Items.Find(Type)->ItemCount[Idx];
	}

	/** Max Capacity for each item. REMEMBER! EACH ITEM.
	 * NOTE: In the future, maybe we can add "Slot/Bag" system so the capacity will be increased
	 */
	int32 MaxCapacity = 2;

	FORCEINLINE void AddItemCount(EItemType Type, int32 Idx)
	{
		++Items[Type].ItemCount[Idx]; 
	}
	
public:

	UFUNCTION(BlueprintCallable)
	void AddItem(ABaseItem* NewItem);

	/** If exists, returns the amount. If not, return -1 */
	int32 ItemIsExists(const FName& ItemName);
};
