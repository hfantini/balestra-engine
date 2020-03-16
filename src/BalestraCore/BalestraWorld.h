// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BWORLD

#define _INC_BWORLD

#include "BalestraPrecompiledHeader.h"
#include "Balestra32ARGBColorFloat.h"

namespace BalestraEngine
{
	class BalestraEnvironment;
	class BalestraGameTime;
	class BalestraRenderGear;
	class Balestra2DText;
	class BalestraDebugText;

	class BalestraWorld
	{
		public:

			// == METHODS ======================================
			BalestraWorld();
			BalestraWorld(BalestraRenderGear* renderGear);
			~BalestraWorld();

			virtual void loadContent();
			virtual void unloadContent();
			virtual void update(BalestraGameTime* gameTime);
			virtual void draw();
			BalestraEnvironment* getEnvironment();
			void setEnvironment(BalestraEnvironment* env);

			// == GETTERS AND SETTERS ==========================
			B32ARGBColorFloat* getBackgroundColor();
			void setBackgroundColor(B32ARGBColorFloat color);

		private:

			// == VAR & CONST ==================================
			std::vector<int> objectList;
			B32ARGBColorFloat backgroundColor;

		protected:

			// == VAR & CONST ==================================
			BalestraEnvironment* env;
			BalestraRenderGear* renderGear;
	};
}

#endif