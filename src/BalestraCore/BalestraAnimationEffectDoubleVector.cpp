// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraAnimationEffectDoubleVector.h"
#include "BalestraDoubleVector.h"
#include "BalestraGameTime.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BalestraAnimationEffectDoubleVector::BalestraAnimationEffectDoubleVector()
	{

	}

	BalestraAnimationEffectDoubleVector::~BalestraAnimationEffectDoubleVector()
	{

	}

	void BalestraAnimationEffectDoubleVector::apply(BalestraGameTime* gameTime)
	{
		animationState = ANIMATION_EFFECT_STATE_FINISHED;

		if (currentVector)
		{
			// == X

			float changeRateX = gameTime->syncWithTime(getAnimationRate());

			float currentX = currentVector->getX();
			float targetX = targetVector->getX();

			if (currentX < targetX)
			{
				animationState = ANIMATION_EFFECT_STATE_RUNNING;
				currentX = currentX + changeRateX;

				if (currentX > targetX)
				{
					currentX = targetX;
				}

			}
			else if (currentX > targetX)
			{
				animationState = ANIMATION_EFFECT_STATE_RUNNING;
				currentX = currentX - changeRateX;

				if (currentX < targetX)
				{
					currentX = targetX;
				}
			}

			// == Y

			float changeRateY = gameTime->syncWithTime(getAnimationRate());

			float currentY = currentVector->getY();
			float targetY = targetVector->getY();

			if (currentY < targetY)
			{
				animationState = ANIMATION_EFFECT_STATE_RUNNING;
				currentY = currentY + changeRateY;

				if (currentY > targetY)
				{
					currentY = targetY;
				}
			}
			else if (currentY > targetY)
			{
				animationState = ANIMATION_EFFECT_STATE_RUNNING;
				currentY = currentY - changeRateY;

				if (currentY < targetY)
				{
					currentY = targetY;
				}
			}

			// == UPDATING VECTOR
			currentVector->setX(currentX);
			currentVector->setY(currentY);
		}
	}

	void BalestraAnimationEffectDoubleVector::reset()
	{

	}

	void BalestraAnimationEffectDoubleVector::unloadEffect()
	{

	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	BDoubleVector* BalestraAnimationEffectDoubleVector::getCurrentVector()
	{
		return BalestraAnimationEffectDoubleVector::currentVector;
	}

	void BalestraAnimationEffectDoubleVector::setCurrentVector(BDoubleVector* vector)
	{
		BalestraAnimationEffectDoubleVector::currentVector = vector;
	}

	BDoubleVector* BalestraAnimationEffectDoubleVector::getTargetVector()
	{
		return BalestraAnimationEffectDoubleVector::targetVector;
	}

	void BalestraAnimationEffectDoubleVector::setTargetVector(BDoubleVector* vector)
	{
		BalestraAnimationEffectDoubleVector::targetVector = vector;
	}
}