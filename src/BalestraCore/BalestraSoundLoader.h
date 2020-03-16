// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BSOUND_LOADER

#define _INC_BSOUND_LOADER

#include "BalestraPrecompiledHeader.h"
#include "IBalestraDevice.h"

namespace BalestraEngine
{
	class BalestraSound;

	class BalestraSoundLoader
	{
		public:

			virtual BalestraSound* loadSound(std::string soundPath, int fileType);
			virtual void unloadSound(BalestraSound* sound);

		private:
		protected:
	};
}

#endif