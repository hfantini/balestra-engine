// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_IBALESTRA_DEVICE

#define _INC_IBALESTRA_DEVICE

#include "BalestraPrecompiledHeader.h"
#include "BalestraDataTypes.h"

namespace BalestraEngine
{
	class BalestraConfiguration;

	class IBalestraDevice
	{
		public:

			// == METHODS ======================================
			virtual ~IBalestraDevice(){}

			virtual void initDevice() = 0;
			virtual B_BOOL isCompatible() = 0;
			virtual void cleanDevice() = 0;

			// == GETTERS AND SETTERS ==========================
			BalestraConfiguration* getConfiguration();

		private:
		protected:

			// == VAR & CONST ===================================
			BalestraConfiguration* configuration;
	};
}

#endif