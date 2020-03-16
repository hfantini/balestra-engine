// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraD2D1Environment.h"

namespace BalestraEngine
{
	class Win32BalestraD2D1RenderGear : public BalestraRenderGear
	{
		public:

			// == VAR & CONST ===================================

			// == METHODS ======================================
			Win32BalestraD2D1RenderGear(Win32BalestraD2D1Environment* videoEnv);
			~Win32BalestraD2D1RenderGear();

			void startDraw() override;
			void draw2DRect(Balestra2DRect* rect) override;
			void draw2DText(Balestra2DText* text) override;
			void draw2DSprite(Balestra2DSprite* sprite) override;
			void clearRenderTarget(B32ARGBColorFloat* color) override;
			void stopDraw() override;

		private:
		protected:
	};
}