// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BTEXT

#define _INC_BTEXT

#include "BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	class BalestraText
	{
		public:

			// == METHODS ======================================

			BalestraText();
			BalestraText(std::string fontName, float fontSize);
			~BalestraText();

			// == GETTERS AND SETTERS ==========================

			std::string getFontName();
			void setFontName(std::string fontName);
			float getFontSize();
			void setFontSize(float size);

		private:

			// == VAR & CONST ===================================

			std::string fontName;
			float fontSize;

		protected:
	};
}

#endif