// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BENVIRONMENT_INPUT

#define _INC_BENVIRONMENT_INPUT

#include "BalestraPrecompiledHeader.h"
#include "IBalestraDevice.h"

namespace BalestraEngine
{
	class BalestraInputMouse;
	class BalestraInputKeyboard;

	class BalestraEnvironmentInput : public IBalestraDevice
	{
		public:

			// == METHODS ======================================

			BalestraEnvironmentInput(BalestraConfiguration* configuration);

			virtual BalestraInputMouse* getMouseDevice() = 0;
			virtual BalestraInputKeyboard* getKeyboardDevice() = 0;

		private:

		protected:
	};
}

#endif