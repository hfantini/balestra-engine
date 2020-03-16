// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BRENDER_GEAR

#define _INC_BRENDER_GEAR

#include "BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	class BalestraEnvironmentVideo;
	class BalestraWorld;
	class Balestra2DSprite;
	class B32ARGBColorFloat;
	class Balestra2DRect;
	class Balestra2DText;

	class BalestraRenderGear
	{
		public:

			// == METHODS ======================================
			BalestraRenderGear(BalestraEnvironmentVideo* videoEnv);
			~BalestraRenderGear();

			virtual void startDraw();
			virtual void draw2DRect(Balestra2DRect* rect);
			virtual void draw2DText(Balestra2DText* text);
			virtual void draw2DSprite(Balestra2DSprite* sprite);
			virtual void clearRenderTarget(B32ARGBColorFloat* color);
			virtual void stopDraw();

		private:
			
		protected:

			// == VAR & CONST ===================================
			BalestraEnvironmentVideo* videoEnv;
	};
}

#endif