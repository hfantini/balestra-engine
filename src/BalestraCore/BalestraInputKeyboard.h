// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BINPUT_KEYBOARD

#define _INC_BINPUT_KEYBOARD

#include "BalestraPrecompiledHeader.h"
#include "IBalestraDevice.h"

namespace BalestraEngine
{
	class BalestraConfiguration;

	class BalestraInputKeyboard : public IBalestraDevice
	{
		public:

			// == METHODS ======================================

			BalestraInputKeyboard(BalestraConfiguration* configuration);

			void initDevice() override {}
			B_BOOL isCompatible() override { return B_TRUE; }
			void cleanDevice() override {}
			virtual int getKeyState(short key);

		private:
		protected:
	};
}

#endif