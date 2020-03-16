// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BCAMERA

#define _INC_BCAMERA

#include "BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	class BalestraCamera
	{
		public:

			// == VAR & CONST ===================================
			BalestraCamera();
			BalestraCamera(float X, float Y, float Z);
			~BalestraCamera();

			// == GETTERS AND SETTERS ==========================

			float getX();
			void setX(float X);
			float getY();
			void setY(float Y);
			float getZ();
			void setZ(float Z);

		private:

			// == VAR & CONST ===================================

			float X;
			float Y;
			float Z;

		protected:
	};
}

#endif