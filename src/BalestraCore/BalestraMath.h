// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BMATH

#define _INC_BMATH

#define R_GENERATION_SIGN_POSITIVE 1
#define R_GENERATION_SIGN_NEGATIVE 2
#define R_GENERATION_SIGN_BOTH 3

#include "BalestraPrecompiledHeader.h"
#include "BalestraDataTypes.h"
#include "BalestraMathException.h"

namespace BalestraEngine
{
	class BRect;
	class BAngle;
	class BDoubleVector;

	class BalestraMath
	{
		public:

			//NUMERALS
			static int createRandomIntNumberOnInterval(int min, int max);
			static int createRandomIntNumberOnInterval(int min, int max, int ruleSignalGen);
			static float calcPercentageBetweenTwoValues(float value, float maxValue);
			static float calcPercentageBetweenPercAndValue(float perc, float value);
			static long getDigitsFromLongVar(long number);

			//GEOMETRY
			static B_BOOL isPointInsideRect(BDoubleVector* point, BRect* rect);

			//TRIGONOMETRY
			static BAngle getAngleBetweenTwoPoints(BDoubleVector pointA, BDoubleVector pointB);

			// == GETTERS AND SETTERS ==========================

			static void setRandomSeedValue(unsigned int randomSeed);

		private:

		protected:
	};
}

#endif 