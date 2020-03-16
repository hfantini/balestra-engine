// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_W32_BALESTRA_PLATFORM_INPUT

#define _INC_W32_BALESTRA_PLATFORM_INPUT

#include "Win32BalestraPrecompiledHeader.h"
#include "IWin32BalestraDevice.h"

namespace BalestraEngine
{
	class Win32BalestraPlatformMouse;
	class Win32BalestraPlatformKeyboard;
	class Win32BalestraConfiguration;
	class BDoubleVector;

	class Win32BalestraPlatformInput : public BalestraEnvironmentInput, public IWin32BalestraDevice
	{
		public:

			// == METHODS ======================================

			Win32BalestraPlatformInput(BalestraConfiguration* configuration);
			~Win32BalestraPlatformInput();

			void initDevice() override;
			B_BOOL isCompatible() override;
			void cleanDevice() override;

			// == GETTERS AND SETTERS ==========================

			BalestraInputMouse* getMouseDevice() override;
			BalestraInputKeyboard* getKeyboardDevice() override;

		private:

			// == VAR & CONST ===================================
			BalestraInputMouse* mouse;
			BalestraInputKeyboard* keyboard;

		protected:
			Win32BalestraConfiguration* getW32Configuration() override;
	};
}

#endif