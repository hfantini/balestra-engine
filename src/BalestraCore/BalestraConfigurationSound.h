
// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BCONFIGURATION_AUDIO

#define _INC_BCONFIGURATION_AUDIO

#include "BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	class BalestraConfigurationSound
	{
		public:

			// == GETTERS AND SETTERS ==========================
			int getSoundInterface();
			void setSoundInterface(int soundInterface);

		private:

			// == VAR & CONST ===================================
			int soundInterface = 0;

		protected:
	};
}

#endif