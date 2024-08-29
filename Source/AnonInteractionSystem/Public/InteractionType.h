// Copyright, Anon Creation Games

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "GameplayTagContainer.h"
#include "InteractionType.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	HealthProvisions,
	ManaProvisions,
	StaminaProvisions,
	AttackBoost,
	DefenceBoost,
	UniqueItem // This is used for quest only OR maybe later can be used as craftable
};

UCLASS(BlueprintType)
class UItemData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName ItemName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag ItemTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> EffectClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EItemType ItemType = EItemType::UniqueItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UTexture2D> ItemIcon;
};

USTRUCT(BlueprintType)
struct FItemHandle
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly)
	TArray<UItemData*> Data;

	// How many item is being carried, Once the item is already exists in the inventory, just add this ItemCount
	UPROPERTY(BlueprintReadOnly)
	TArray<int32> ItemCount;
};
