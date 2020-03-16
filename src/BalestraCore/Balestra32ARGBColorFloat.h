// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BCOLOR

#define _INC_BCOLOR

#include "BalestraDataTypes.h"
#include "BalestraConstants.h"

namespace BalestraEngine
{
	class B32ARGBColorFloat
	{
		public:

			B32ARGBColorFloat();
			B32ARGBColorFloat(float alpha, float red, float green, float blue);

			// == GETTERS AND SETTERS ==========================
			float getAlpha();
			void setAlpha(float alpha);
			float getRed();
			void setRed(float red);
			float getGreen();
			void setGreen(float green);
			float getBlue();
			void setBlue(float blue);

		private:
		protected:

			// == VAR & CONST ===================================
			float alpha;
			float red;
			float green;
			float blue;
	};
}

#endif