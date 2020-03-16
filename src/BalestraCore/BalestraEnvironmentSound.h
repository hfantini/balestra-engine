// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BENVIRONMENT_SOUND

#define _INC_BENVIRONMENT_SOUND

#include "BalestraPrecompiledHeader.h"
#include "IBalestraDevice.h"

namespace BalestraEngine
{
	class BalestraSoundChannel;

	class BalestraEnvironmentSound : public IBalestraDevice
	{
		public:

			// == METHODS ======================================
			BalestraEnvironmentSound(BalestraConfiguration* configuration);

			virtual BalestraSoundChannel* createSoundChannel();

		private:
		protected:
	};
}

#endif