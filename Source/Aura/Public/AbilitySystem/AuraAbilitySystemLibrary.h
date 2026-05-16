// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/CharacterClassInfo.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AuraAbilitySystemLibrary.generated.h"

struct FGameplayEffectContextHandle;
class UAbilitySystemComponent;
class UAttributeMenuWidgetController;
class UOverlayWidgetController;
/**
 * 
 */
UCLASS()






/**
* @brief Aura能力系统的蓝图函数库，提供Widget控制器获取、角色默认属性初始化及启动能力授予等工具方法。
*/
class AURA_API UAuraAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	
	/**
	* @brief 获取Overlay界面的Widget控制器。
	* @param WorldContextObject 世界上下文对象，用于获取当前关卡中的相关子系统。
	* @return 指向UOverlayWidgetController的指针，若未找到则返回nullptr。
	*/
	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemLibrary|WidgetController")
	static UOverlayWidgetController* GetOverlayWidgetController(const UObject* WorldContextObject);
	
	/**
	* @brief 获取属性菜单的Widget控制器。
	* @param WorldContextObject 世界上下文对象，用于获取当前关卡中的相关子系统。
	* @return 指向UAttributeMenuWidgetController的指针，若未找到则返回nullptr。
	*/	
	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemLibrary|WidgetController")
	static UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const UObject* WorldContextObject);
	
	/**
	* @brief 根据角色职业和等级初始化默认属性。
	* @param WorldContextObject 世界上下文对象，用于获取角色类默认信息。
	* @param CharacterClass 角色职业类型枚举。
	* @param Level 角色等级，影响属性初始化数值。
	* @param ASC 目标能力系统组件，属性将应用到此ASC上。
	*/
	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemLibrary|CharacterClassDefaults")
	static void InitializeDefaultAttributes(const UObject* WorldContextObject, ECharacterClass CharacterClass, float Level, UAbilitySystemComponent* ASC);
	
	/**
	* @brief 授予角色的启动能力（Startup Abilities）。
	* @param WorldContextObject 世界上下文对象，用于获取角色类默认信息。
	* @param ASC 目标能力系统组件，启动能力将授予此ASC。
	*/
	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemLibrary|CharacterClassDefaults")
	static void GiveStartupAbilities(const UObject* WorldContextObject, UAbilitySystemComponent* ASC);
	
	/**
	* @brief 获取角色类默认配置信息。
	* @param WorldContextObject 世界上下文对象，用于获取游戏实例中的角色类信息。
	* @return 指向UCharacterClassInfo的指针，包含各职业的默认属性与能力配置；若未找到则返回nullptr。
	*/
	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemLibrary|CharacterClassDefaults")
	static UCharacterClassInfo* GetCharacterClassInfo(const UObject* WorldContextObject);
	
	/**
 	* @brief 检查游戏效果上下文是否为格挡命中
 	* @param EffectContextHandle 游戏效果上下文句柄，用于获取自定义的Aura效果上下文
 	* @return 如果效果上下文有效且为格挡命中则返回true，否则返回false
 	*/
	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemLibrary|GameplayEffects")
	static bool IsBlockedHit(const FGameplayEffectContextHandle& EffectContextHandle);
	
	/**
	* @brief 检查游戏效果上下文是否为暴击命中
	* @param EffectContextHandle 游戏效果上下文句柄，用于获取暴击信息
	* @return 如果上下文为暴击命中则返回 true；如果上下文无法转换为 FAuraGameplayEffectContext 或非暴击，则返回 false
	*/
	UFUNCTION(BlueprintPure, Category="AuraAbilitySystemLibrary|GameplayEffects")
	static bool IsCriticalHit(const FGameplayEffectContextHandle& EffectContextHandle);
	
	/**
	* @brief 设置游戏效果上下文为格挡命中
	* @param EffectContextHandle 游戏效果上下文句柄，用于设置自定义的Aura效果上下文
	* @param bInIsBlockedHit 是否为格挡命中
	*/
	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemLibrary|GameplayEffects")
	static void SetIsBlockedHit(UPARAM(ref)FGameplayEffectContextHandle& EffectContextHandle, bool bInIsBlockedHit);
	
	/**
	* @brief 设置游戏效果上下文为暴击命中
	* @param EffectContextHandle 游戏效果上下文句柄，用于设置自定义的Aura效果上下文
	* @param bInIsCriticalHit 是否为暴击命中
	*/
	UFUNCTION(BlueprintCallable, Category="AuraAbilitySystemLibrary|GameplayEffects")
	static void SetIsCriticalHit(UPARAM(ref)FGameplayEffectContextHandle& EffectContextHandle, bool bInIsCriticalHit);
};
