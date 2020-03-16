// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraAnimationEffectColor.h"
#include "BalestraColorUtil.h"
#include "BalestraGameTime.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================
	BalestraAnimationEffectColor::BalestraAnimationEffectColor()
	{

	}

	BalestraAnimationEffectColor::~BalestraAnimationEffectColor()
	{
		unloadEffect();
	}

	void BalestraAnimationEffectColor::apply(BalestraGameTime* gameTime)
	{
		animationState = ANIMATION_EFFECT_STATE_FINISHED;

		float updateRateInFloat = (gameTime->syncWithTime(getAnimationRate())) / 255;

		// == ALPHA

		if (currentColor->getAlpha() != targetColor->getAlpha())
		{
			if (currentColor->getAlpha() < targetColor->getAlpha())
			{
				currentColor->setAlpha(currentColor->getAlpha() + updateRateInFloat);
				animationState = ANIMATION_EFFECT_STATE_RUNNING;

				if (currentColor->getAlpha() > targetColor->getAlpha())
				{
					currentColor->setAlpha(targetColor->getAlpha());
				}
			}
			else if (currentColor->getAlpha() > targetColor->getAlpha())
			{
				currentColor->setAlpha(currentColor->getAlpha() - updateRateInFloat);
				animationState = ANIMATION_EFFECT_STATE_RUNNING;

				if (currentColor->getAlpha() < targetColor->getAlpha())
				{
					currentColor->setAlpha(targetColor->getAlpha());
				}
			}
		}

		// == RED
		if (currentColor->getRed() != targetColor->getRed())
		{
			if (currentColor->getRed() < targetColor->getRed())
			{
				currentColor->setRed(currentColor->getRed() + updateRateInFloat);
				animationState = ANIMATION_EFFECT_STATE_RUNNING;

				if (currentColor->getRed() > targetColor->getRed())
				{
					currentColor->setRed(targetColor->getRed());
				}
			}
			else if (currentColor->getRed() > targetColor->getRed())
			{
				currentColor->setRed(currentColor->getRed() - updateRateInFloat);
				animationState = ANIMATION_EFFECT_STATE_RUNNING;

				if (currentColor->getRed() < targetColor->getRed())
				{
					currentColor->setRed(targetColor->getRed());
				}
			}
		}
			
		// == GREEN

		if (currentColor->getGreen() != targetColor->getGreen())
		{
			if (currentColor->getGreen() < targetColor->getGreen())
			{
				currentColor->setGreen(currentColor->getGreen() + updateRateInFloat);
				animationState = ANIMATION_EFFECT_STATE_RUNNING;

				if (currentColor->getGreen() > targetColor->getGreen())
				{
					currentColor->setGreen(targetColor->getGreen());
				}
			}
			else if (currentColor->getGreen() > targetColor->getGreen())
			{
				currentColor->setGreen(currentColor->getGreen() - updateRateInFloat);
				animationState = ANIMATION_EFFECT_STATE_RUNNING;

				if (currentColor->getGreen() < targetColor->getGreen())
				{
					currentColor->setGreen(targetColor->getGreen());
				}
			}
		}

		// == BLUE

		if (currentColor->getBlue() != targetColor->getBlue())
		{
			if (currentColor->getBlue() < targetColor->getBlue())
			{
				currentColor->setBlue(currentColor->getBlue() + updateRateInFloat);
				animationState = ANIMATION_EFFECT_STATE_RUNNING;

				if (currentColor->getBlue() > targetColor->getBlue())
				{
					currentColor->setBlue(targetColor->getBlue());
				}
			}
			else if (currentColor->getBlue() > targetColor->getBlue())
			{
				currentColor->setBlue(currentColor->getBlue() - updateRateInFloat);
				animationState = ANIMATION_EFFECT_STATE_RUNNING;

				if (currentColor->getBlue() < targetColor->getBlue())
				{
					currentColor->setBlue(targetColor->getBlue());
				}
			}
		}
	}

	void BalestraAnimationEffectColor::reset()
	{

	}

	void BalestraAnimationEffectColor::unloadEffect()
	{

	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	B32ARGBColorFloat* BalestraAnimationEffectColor::getCurrentColor()
	{
		return BalestraAnimationEffectColor::currentColor;
	}

	void BalestraAnimationEffectColor::setCurrentColor(B32ARGBColorFloat* color)
	{
		BalestraAnimationEffectColor::currentColor = color;
	}

	B32ARGBColorFloat* BalestraAnimationEffectColor::getTargetColor()
	{
		return targetColor;
	}

	void BalestraAnimationEffectColor::setTargetColor(B32ARGBColorFloat* target)
	{
		if (!targetColor)
		{
			BalestraAnimationEffectColor::targetColor = target;
		}
		else if (!BalestraColorUtil::compareColor(targetColor, target))
		{
			BalestraAnimationEffectColor::targetColor = target;
			BalestraAnimationEffectColor::animationState = ANIMATION_EFFECT_STATE_RUNNING;
		}
	}
}