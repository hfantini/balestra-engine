// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BINPUT_MOUSE

#define _INC_BINPUT_MOUSE

#include "BalestraPrecompiledHeader.h"
#include "BalestraDataTypes.h"
#include "IBalestraDevice.h"

namespace BalestraEngine
{
	class BalestraInputMouse : public IBalestraDevice
	{
		public:

			// == METHODS ======================================	
			BalestraInputMouse(BalestraConfiguration* configuration);

			void initDevice() override {}
			B_BOOL isCompatible() override { return B_TRUE; }
			void cleanDevice() override {}
			virtual BMouseState* getMouseState();
			virtual void updateMouseState();

		private:
		protected:
	};
}

#endif