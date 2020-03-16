//== BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"

#ifndef _INC_BALESTRA_FONT_LOADER

#define _INC_BALESTRA_FONT_LOADER

#include "IBalestraDevice.h"

namespace BalestraEngine
{
	struct BFontInfo
	{
		std::string fontPath;
	};

	class BalestraFont;

	class BalestraFontLoader : IBalestraDevice
	{
		public:

			BalestraFontLoader();
			~BalestraFontLoader();

			virtual void initDevice() override;
			virtual BalestraFont* loadFont(BFontInfo fontInfo);
			virtual void cleanDevice() override;

		private:
		protected:
	};
}

#endif