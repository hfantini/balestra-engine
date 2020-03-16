// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BCOLOR_ARGB_INT

#define _INC_BCOLOR_ARGB_INT

#include "BalestraPrecompiledHeader.h"
#include "BalestraDataTypes.h"

namespace BalestraEngine
{
	class B32ARGBColorUInt
	{
		public:

			// == METHODS ======================================
			B32ARGBColorUInt();
			B32ARGBColorUInt(B_UNSIGNED_BYTE alpha, B_UNSIGNED_BYTE red, B_UNSIGNED_BYTE green, B_UNSIGNED_BYTE blue);

			// == GETTERS AND SETTERS ==========================
			B_UNSIGNED_BYTE getAlpha();
			void setAlpha(B_UNSIGNED_BYTE alpha);
			B_UNSIGNED_BYTE getRed();
			void setRed(B_UNSIGNED_BYTE red);
			B_UNSIGNED_BYTE getGreen();
			void setGreen(B_UNSIGNED_BYTE green);
			B_UNSIGNED_BYTE getBlue();
			void setBlue(B_UNSIGNED_BYTE blue);

		private:



		protected:

		// == VAR & CONST ===================================
		B_UNSIGNED_BYTE alpha;
		B_UNSIGNED_BYTE red;
		B_UNSIGNED_BYTE green;
		B_UNSIGNED_BYTE blue;
	};
}

#endif