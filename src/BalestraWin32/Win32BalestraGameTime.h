// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_W32_GAME_TIME

#define _INC_W32_GAME_TIME

#include "Win32BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	class Win32BalestraGameTime : public BalestraGameTime
	{
		public:

			// == METHODS ======================================

			Win32BalestraGameTime(BalestraConfiguration* config);
			~Win32BalestraGameTime();

			void initDevice() override;
			void tickTime(BalestraWorld* world) override;
			void cleanDevice() override;
			float syncWithTime(float value) override;

			// == GETTERS AND SETTERS ==========================

		private:

			// == VAR & CONST ===================================
			__int64 countsPerSec = 0;
			__int64 prevTime = 0;
			float secPerCount = 0;
			int frameCount = 0;
			float elapsedTimeMSCount = 0;
			float deltaAccumulator = 0;

		protected:
	};
}

#endif