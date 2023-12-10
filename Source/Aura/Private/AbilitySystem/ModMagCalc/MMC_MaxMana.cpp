// Copyright MHBagheri


#include "AbilitySystem/ModMagCalc/MMC_MaxMana.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "Interaction/CombatInterface.h"

UMMC_MaxMana::UMMC_MaxMana()
{
	IntelDef.AttributeToCapture = UAuraAttributeSet::GetIntelligenceAttribute();
	IntelDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	IntelDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(IntelDef);
}

float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FGameplayTagContainer* SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = SourceTags;
	EvaluationParameters.TargetTags = TargetTags;

	float Intel = 0.0f;
	GetCapturedAttributeMagnitude(IntelDef, Spec, EvaluationParameters, Intel);
	Intel = FMath::Max<float>(Intel, 0.0f);

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel = CombatInterface->GetPlayerLevel();

	return 80.0f + 2.5f * Intel + 10.0f * PlayerLevel;
}
