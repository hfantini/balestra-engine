// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BENVIRONMENT_RESOURCE

#define _INC_BENVIRONMENT_RESOURCE

#include "BalestraPrecompiledHeader.h"
#include "IBalestraDevice.h"

namespace BalestraEngine
{
	class BalestraConfiguration;
	class BalestraEnvironmentVideo;
	class BalestraImageLoader;
	class BalestraSoundLoader;
	class BalestraFontLoader;

	class BalestraEnvironmentResource : public IBalestraDevice
	{
		public:

			BalestraEnvironmentResource(BalestraConfiguration* configuration, BalestraEnvironmentVideo* videoEnvironment);
			virtual BalestraImageLoader* createImageLoader();
			virtual BalestraSoundLoader* createSoundLoader();
			virtual BalestraFontLoader* createFontLoader();

		private:
		protected:

			BalestraEnvironmentVideo* videoEnvironment;
	};
}

#endif 