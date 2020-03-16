// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_COMPONENT_BDEBUG_TEXT

#define _INC_COMPONENT_BDEBUG_TEXT

#include "BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	class BalestraWorld;
	class BalestraGameTime;
	class BalestraRenderGear;
	class Balestra2DText;

	class BalestraDebugText
	{
		public:

			// == METHODS ======================================

			BalestraDebugText();
			~BalestraDebugText();

			void loadContent(BalestraWorld* world);
			void unloadContent(BalestraWorld* world);
			void update(BalestraGameTime* gameTime);
			void draw(BalestraRenderGear* renderGear);

		private:

			// == VAR & CONST ===================================
			Balestra2DText* debugMode;
			Balestra2DText* gameTimeDbgText;

		protected:
	};
}

#endif