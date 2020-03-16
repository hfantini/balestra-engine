// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraMath.h"
#include "BalestraDoubleVector.h"
#include "BalestraRect.h"
#include "BalestraAngle.h"
#include "BalestraConstants.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================
	
	// == NUMERALS =========================================
	int BalestraMath::createRandomIntNumberOnInterval(int min, int max)
	{
		return createRandomIntNumberOnInterval(min, max, R_GENERATION_SIGN_POSITIVE);
	}

    int BalestraMath::createRandomIntNumberOnInterval(int min, int max, int ruleSignalGen)
	{
		int retValue = (rand() % ((max + 1) - min) + min);

		int sign;

		switch (ruleSignalGen)
		{
			case R_GENERATION_SIGN_NEGATIVE:
				retValue = retValue * -1;
				break;
			
			case R_GENERATION_SIGN_BOTH:

				sign = createRandomIntNumberOnInterval(0, 1);

				if (sign == 1)
				{
					retValue = retValue * -1;
				}

				break;

			default:
				//THROW EXCEPTION
				break;
		}

		return retValue;
	}

	float BalestraMath::calcPercentageBetweenTwoValues(float value, float maxValue)
	{
		if (maxValue == 0)
		{
			//THROW EXCEPTION
		}

		return ((value * 100) / maxValue);
	}

	float BalestraMath::calcPercentageBetweenPercAndValue(float perc, float value)
	{
		if (value == 0)
		{
			//THROW EXCEPTION
		}

		return ((perc * value) / 100);
	}

	long BalestraMath::getDigitsFromLongVar(long number)
	{
		long digits = 0;
		long division = number;

		while (B_TRUE)
		{
			division = (division / 10);
			digits++;

			if (division == 0)
			{
				break;
			}
		}

		return digits;
	}

	// == GEOMETRY =========================================

	B_BOOL BalestraMath::isPointInsideRect(BDoubleVector* point, BRect* rect)
	{
		if (point->getX() <= rect->getX())
		{
			return B_FALSE;
		}

		if (point->getX() >= rect->getWidth())
		{
			return B_FALSE;
		}

		if (point->getY() <= rect->getY())
		{
			return B_FALSE;
		}

		if (point->getY() >= rect->getHeight())
		{
			return B_FALSE;
		}

		return B_TRUE;
	}

	// == TRIGONOMETRY =====================================

	BAngle BalestraMath::getAngleBetweenTwoPoints(BDoubleVector pointA, BDoubleVector pointB)
	{
		float opSide = 0;
		float adSide = 0;

		opSide = pointA.getY() - pointB.getY();
		adSide = pointA.getX() - pointB.getX();

		if (opSide < 0)
		{
			opSide = opSide * 1;
		}

		if (adSide < 0)
		{
			adSide = adSide * 1;
		}

		BAngle angle = BAngle((std::atan2(opSide, adSide) * 180 / BALESTRA_PI));

		return angle;
	}

	// == IMPLEMENTATION: Getters & Setters
	// =====================================================

	void BalestraMath::setRandomSeedValue(unsigned int randomSeed)
	{
		srand(randomSeed);
	}
}