// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_W32_BPLATFORM_UTIL

#define _INC_W32_BPLATFORM_UTIL

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraConstants.h"

namespace BalestraEngine
{
	class Win32BalestraPlatformUtil
	{
		public:

			static wchar_t* convertCHARtoWCHAR(const char* value);
			static char* convertWCHARtoCHAR(const wchar_t* value);
			static std::string getOsSystemName(int osCode);

		private:
		protected:
	};
}

#endif