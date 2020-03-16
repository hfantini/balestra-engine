// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BCONFIGURATION_GAMETIME

#define _INC_BCONFIGURATION_GAMETIME

#include "BalestraPrecompiledHeader.h"
#include "BalestraDataTypes.h"

namespace BalestraEngine
{
	class BalestraConfigurationGameTime
	{
		public:
			B_BOOL getRunning();
			void setRunning(B_BOOL);
			int getMode();
			void setMode(int mode);
			int getTargetFPS();
			void setTargetFPS(int FPS);
			int getMaxFrameSkip();
			void setMaxFrameSkip(int maxFrameSkip);

		private:

		protected:
			B_BOOL isRunning;
			int mode;
			int targetFPS;
			int maxFrameSkip;
	};
}

#endif