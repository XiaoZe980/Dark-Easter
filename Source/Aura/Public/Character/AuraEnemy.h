// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

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
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Character Class Defaults")
	int32 Level = 1;
};
