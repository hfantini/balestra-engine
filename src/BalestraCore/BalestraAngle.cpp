// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraAngle.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BAngle::BAngle(float angle)
	{
		BAngle::angle = angle;
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	float BAngle::getAngle()
	{
		return BAngle::angle;
	}

	void BAngle::setAngle(float angle)
	{
		if (angle >= 0 && angle < 360)
		{
			BAngle::angle = angle;
		}
		else
		{
			if (angle < 0)
			{
				//THROW EXCEPTION
			}
			else if (angle > 360)
			{
				//CALCULATING ANGLE CORRECTION TO FIT IN THE RANGE (0 ~ 360) DEGREES
				int factor = angle / 360;
				BAngle::angle = angle - (factor * 360);
			}
		}
	}
}