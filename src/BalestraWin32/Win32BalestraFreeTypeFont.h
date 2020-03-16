// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_FREETYPE_FONT

#define _INC_FREETYPE_FONT

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraOpenGLTexture.h"

namespace BalestraEngine
{
	struct BalestraGlyph
	{
		Win32BalestraOpenGLTexture texture;
		int width;
		int height;
		int advancement;
		int heightOffset;
	};

	class Win32BalestraFreeTypeFont : public BalestraFont
	{
		public:

			// == VAR 

			// == CLASS METHODS

			Win32BalestraFreeTypeFont();
			~Win32BalestraFreeTypeFont();

			void unloadResource() override;

			// == GETTERS AND SETTERS
			BalestraGlyph getCharAt(int value);
			void setCharAt(BalestraGlyph value, int pos);
			std::string getFilePath();
			void setFilePath(std::string value);

		private:
		protected:		
			
			BalestraGlyph characterMap[256];
			std::string filePath;
	};
}

#endif