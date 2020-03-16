// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BSPRITE2D_TEXT

#define _INC_BSPRITE2D_TEXT

#include "BalestraPrecompiledHeader.h"
#include "Balestra2DWorldObject.h"

namespace BalestraEngine
{
	class BalestraText;
	class BalestraFont;

	class Balestra2DText : public Balestra2DWorldObject
	{
		public:

			// == VAR & CONST ===================================

			// == METHODS ======================================
			Balestra2DText(BalestraFont* font, std::string text);
			~Balestra2DText();

			void loadContent(BalestraWorld* world) override;
			void unloadContent(BalestraWorld* world) override;
			void update(BalestraGameTime* gameTime) override;
			void draw(BalestraRenderGear* renderGear) override;

			// == GETTERS AND SETTERS ==========================

			std::string getText();
			void setText(std::string value);
			BalestraFont* getFont();
			void setFont(BalestraFont* font);

		private:

			// == VAR & CONST ===================================
			BalestraFont* font;
			std::string text;


		protected:
	};
}

#endif