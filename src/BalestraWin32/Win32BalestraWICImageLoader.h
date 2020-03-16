// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BWIC_IMAGE_LOADER

#define _INC_BWIC_IMAGE_LOADER

#include "Win32BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	class BalestraConfiguration;

	class Win32BalestraWICImageLoader : public BalestraImageLoader
	{
		public:

			// == METHODS ======================================
			Win32BalestraWICImageLoader(BalestraConfiguration* configuration, BalestraEnvironmentVideo* videoEnvironment);
			~Win32BalestraWICImageLoader();

			virtual BalestraImage* loadImage(BImageInfo imageInfo) override;

		private:
		protected:

			// == METHODS ======================================
			virtual BalestraImage* loadImageDirect2D(BImageInfo imageInfo);

			// == VAR & CONST ===================================

			BalestraConfiguration* configuration;
			BalestraEnvironmentVideo* videoEnvironment;
			IWICImagingFactory* WICFactory;
	};
}

#endif