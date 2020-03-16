// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "IBalestraAnimationEffect.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	float IBalestraAnimationEffect::getAnimationRate()
	{
		return IBalestraAnimationEffect::animationRate;
	}

	void IBalestraAnimationEffect::setAnimationRate(float animationRate)
	{
		IBalestraAnimationEffect::animationRate = animationRate;
	}

	int IBalestraAnimationEffect::getAnimationState()
	{
		return IBalestraAnimationEffect::animationState;
	}
}