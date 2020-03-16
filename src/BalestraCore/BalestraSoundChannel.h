// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BAUDIO_CHANNEL

#define _INC_BAUDIO_CHANNEL

#include "BalestraPrecompiledHeader.h"
#include "IBalestraDevice.h"

namespace BalestraEngine
{
	class BalestraSound;

	class BalestraSoundChannel : public IBalestraDevice
	{
		public:

			// == METHODS ======================================
			virtual void play();
			virtual void stop();
			virtual void pause();

			// == GETTERS AND SETTERS ==========================
			virtual BalestraSound* getCurrentSound();
			virtual void setCurrentSound(BalestraSound* sound);

		private:

		protected:

			// == VAR & CONST ===================================
			BalestraSound* currentSound;
	};
}

#endif