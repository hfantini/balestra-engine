// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_FREETYPE_FONT_LOADER

#define _INC_FREETYPE_FONT_LOADER

#include "Win32BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	class Win32BalestraFreeTypeFontLoader : public BalestraFontLoader
	{
		public:

			Win32BalestraFreeTypeFontLoader();
			~Win32BalestraFreeTypeFontLoader();

			virtual void initDevice() override;
			virtual B_BOOL isCompatible() override;
			virtual BalestraFont* loadFont(BFontInfo fontInfo);
			virtual void cleanDevice() override;

		private:
		protected:

			//FREETYPE-GL VAR
			FT_Library ftLibrary;
	};
}

#endif
