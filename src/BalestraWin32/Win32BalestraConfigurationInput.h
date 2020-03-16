// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_W32_BALESTRA_INPUT_CONFIG

#define _INC_W32_BALESTRA_INPUT_CONFIG

#include "Win32BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	class Win32BalestraConfigurationInput : public BalestraConfigurationInput
	{
		public:

			// == GETTERS AND SETTERS ==========================
			B_BOOL getAllowMouse();
			void setAllowMouse(B_BOOL value);
			B_BOOL getAllowKeyboard();
			void setAllowKeyboard(B_BOOL value);

		private:
		protected:

			B_BOOL allowMouse = 0;
			B_BOOL allowKeyboard = 0;

	};
}

#endif