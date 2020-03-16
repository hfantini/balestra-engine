// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_W32_BALESTRA_PLATFORM_KEYBOARD

#define _INC_W32_BALESTRA_PLATFORM_KEYBOARD

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraPlatformKeyboardKeys.h"

namespace BalestraEngine
{
	// == DEFINE PLATFORM KEYS 
	// ==========================================

	class Win32BalestraPlatformKeyboard : public BalestraInputKeyboard
	{
		public:
		
			// == METHODS ======================================
			Win32BalestraPlatformKeyboard(BalestraConfiguration* configuration);
			virtual int getKeyState(short key) override;

		private:

			// == METHODS ======================================

		protected:
	};
}

#endif