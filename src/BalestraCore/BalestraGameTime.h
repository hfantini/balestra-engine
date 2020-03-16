// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BGAME_TIME

#define _INC_BGAME_TIME

#include "BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	class BalestraRenderGear;
	class BalestraWorld;
	class BalestraConfiguration;
	class BalestraEnvironment;

	class BalestraGameTime
	{
		public:

			// == METHODS ======================================
			BalestraGameTime(BalestraConfiguration* config);
			~BalestraGameTime();

			virtual void initDevice();
			virtual void tickTime(BalestraWorld* world);
			virtual void cleanDevice();
			virtual float syncWithTime(float value);

			// == GETTERS AND SETTERS ==========================
			int getCurrentFPS();
			virtual long getTotalElapsedTimeInMS();
			virtual long getTotalElapsedTimeInSec();
			std::string getGameTimeInfo();
			float getDeltaTime();

		private:

		protected:

			// == VAR & CONST ==================================
			BalestraConfiguration* configuration;
			float deltaTime = 0;
			int currentFPS = 0;
			float totalElapsedTimeMS = 0;

	};
}

#endif