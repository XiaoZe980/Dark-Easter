// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "AuraEnemy.generated.h"

class UWidgetComponent;

UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase , public IEnemyInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();
	
#pragma region 敌人接口
	virtual void HighLightActor() override;
	virtual void UnHighLightActor() override;
#pragma  endregion 
	
#pragma region 战斗接口
	virtual int32 GetPlayerLevel() override;
#pragma endregion 
	
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnHealthChanged;
	
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangedSignature OnMaxHealthChanged;
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Character Class Defaults")
	int32 Level = 1;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category= "UI")
	TObjectPtr<UWidgetComponent> HealthBar;
};
