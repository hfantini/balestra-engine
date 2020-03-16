// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BCONFIGURATION_DEBUG

#define _INC_BCONFIGURATION_DEBUG

#include "BalestraPrecompiledHeader.h"
#include "BalestraDataTypes.h"

namespace BalestraEngine
{
	class BalestraConfigurationDebug
	{
		public:

			// == METHODS ======================================
			BalestraConfigurationDebug();
			~BalestraConfigurationDebug();

			// == GETTERS AND SETTERS ==========================
			B_BOOL getDebugMode();
			void setDebugMode(B_BOOL value);

		private:

		protected:
			B_BOOL debugMode = B_FALSE;
	};
}

#endif