// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_W32_BALESTRA_PLATFORM_MOUSE

#define _INC_W32_BALESTRA_PLATFORM_MOUSE

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraPlatformMouseButtons.h"
#include "IWin32BalestraDevice.h"

namespace BalestraEngine
{
	class Win32BalestraConfiguration;

	class Win32BalestraPlatformMouse : public BalestraInputMouse, public IWin32BalestraDevice
	{
		public:

			// == VAR & CONST ==================================
			BMouseState currentState;

			// == METHODS ======================================
			Win32BalestraPlatformMouse(BalestraConfiguration* configuration);
			~Win32BalestraPlatformMouse();

			virtual BMouseState* getMouseState() override;
			virtual void updateMouseState() override;

		private:


		protected:

			Win32BalestraConfiguration* getW32Configuration() override;

	};
}

#endif