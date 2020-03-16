// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// ======================================================

#ifndef _INC_IWIN32_BDEVICE

#define _INC_IWIN32_BDEVICE

#include "Win32BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	class Win32BalestraConfiguration;

	class IWin32BalestraDevice
	{
		public:
		private:

			// == METHODS ======================================
			virtual Win32BalestraConfiguration* getW32Configuration() = 0;

		protected:
	};
}

#endif