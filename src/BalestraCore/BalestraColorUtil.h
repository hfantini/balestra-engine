// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BCOLOR_UTIL

#define _INC_BCOLOR_UTIL

#include "BalestraPrecompiledHeader.h"
#include "Balestra32ARGBColorUInt.h"
#include "Balestra32ARGBColorFloat.h"

namespace BalestraEngine
{
	class BalestraColorUtil
	{
		public:
			static B32ARGBColorFloat convertToFloatColor(B32ARGBColorUInt color);
			static B32ARGBColorUInt convertToUIntColor(B32ARGBColorFloat color);
			static B_BOOL compareColor(B32ARGBColorFloat* color1, B32ARGBColorFloat* color2);
		private:
		protected:
	};
}

#endif

