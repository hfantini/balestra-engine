// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"

#ifndef _INC_BIMAGE_LOADER

#define _INC_BIMAGE_LOADER

#include "BalestraPrecompiledHeader.h"
#include "BalestraDoubleVector.h"
#include "IBalestraDevice.h"

namespace BalestraEngine
{
	struct BImageInfo
	{
		std::string imagePath;
		BDoubleVector imageSize;
	};

	class BalestraImage;

	class BalestraImageLoader : IBalestraDevice
	{
		public:

			// == METHODS ======================================
			virtual void initDevice() override;
			virtual B_BOOL isCompatible() override;
			virtual BalestraImage* loadImage(BImageInfo imageInfo);
			virtual void cleanDevice() override;

		private:
		protected:
	};
}
#endif