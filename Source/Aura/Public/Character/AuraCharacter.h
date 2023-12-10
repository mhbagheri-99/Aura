// Copyright MHBagheri

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	virtual int32 GetPlayerLevel() override;

protected:
	UPROPERTY(EditAnywhere, Category="Camera")
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(EditAnywhere, Category="Camera")
	TObjectPtr<USpringArmComponent> SpringArm;

private:
	virtual void InitAbilityActorInfo() override;
};
