// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================
#ifndef _INC_DEVIL_IMAGE_LOADER

#define _INC_DEVIL_IMAGE_LOADER

#include "Win32BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	class BalestraConfiguration;

	class Win32BalestraDevILImageLoader : public BalestraImageLoader
	{
		public:

			// == METHODS ======================================

			Win32BalestraDevILImageLoader(BalestraConfiguration* configuration, BalestraEnvironmentVideo* videoEnvironment);
			~Win32BalestraDevILImageLoader();
			virtual BalestraImage* loadImage(BImageInfo imageInfo) override;

		private:
		protected:

			virtual BalestraImage* loadImageWithDevIL(BImageInfo imageInfo);

			BalestraConfiguration* configuration;
			BalestraEnvironmentVideo* videoEnvironment;

			// == VAR & CONST ===================================

	};
}

#endif
