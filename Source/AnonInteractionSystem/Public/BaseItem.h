// Copyright, Anon Creation Games

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseItem.generated.h"

class UItemData;

UCLASS()
class ANONINTERACTIONSYSTEM_API ABaseItem : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseItem();

	// ==================== Lifecycles ==================== //
	
	virtual void BeginPlay() override;

protected:
	// ==================== Collision Events ==================== //
	
	UFUNCTION(BlueprintCallable)
	void OnItemBeginOverlap(AActor* OtherActor
	);

	UFUNCTION(BlueprintCallable)
	void OnItemEndOverlap(AActor* OtherActor);

private:
	// ==================== Item Data ==================== //

	UPROPERTY(EditAnywhere, Category=Data)
	TObjectPtr<UItemData> Data;

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FORCEINLINE UItemData* GetItemData()
	{
		return Data;
	}
};
