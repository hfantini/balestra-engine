// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BMATH_ANGLE

#define _INC_BMATH_ANGLE

#include "BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	class BAngle
	{
		public:

			// == METHODS ======================================
			BAngle(float angle);

			// == GETTERS AND SETTERS ==========================
			float getAngle();
			void setAngle(float angle);

		private:
		protected:

			// == VAR & CONST ===================================
			float angle;
	};
}

#endif