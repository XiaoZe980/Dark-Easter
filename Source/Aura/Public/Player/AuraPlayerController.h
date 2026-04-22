// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

struct FInputActionValue;
class IEnemyInterface;
class UInputMappingContext;
class UInputAction;
class UEnemyInterface;
/**
 * 
 */
UCLASS(PrioritizeCategories = "Input")
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	AAuraPlayerController();
	virtual void PlayerTick(float DeltaTime) override;
	
protected:
	
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
private:
	
	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputMappingContext> AuraContext;
	
	UPROPERTY(EditAnywhere, Category= "Input")
	TObjectPtr<UInputAction> MoveAction;
	
	void Move(const FInputActionValue& InputActionValue);
	
	void CursorTrace();
	// 这里没有使用TObjectPtr，因为在TObjectPtr不支持接口，所以这里使用原生指针
	// TObjectPtr<IEnemyInterface> LastActor;
	// TObjectPtr<IEnemyInterface> ThisActor;
	IEnemyInterface* LastActor;
	IEnemyInterface* ThisActor;
};
