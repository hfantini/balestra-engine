
// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BCONFIGURATION_INPUT

#define _INC_BCONFIGURATION_INPUT

#include "BalestraPrecompiledHeader.h"

namespace BalestraEngine
{

	// == STRUCT
	// ======================================================

	// == CLASS
	// ======================================================

	class BalestraConfigurationInput
	{
		public:

			// == METHODS ======================================

			// == GETTERS AND SETTERS ==========================
			int getInputInterface();
			void setInputInterface(int interfaceValue);
			int getInputType();
			void setInputType(int inputType);

		private:
		protected:

		// == VAR & CONST ===================================
			int inputInterface = 0;
			int inputType = 0;
	};

}

#endif