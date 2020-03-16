// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_B2D_RECT

#define _INC_B2D_RECT

#include "BalestraPrecompiledHeader.h"
#include "Balestra2DWorldObject.h"
#include "BalestraDataTypes.h"

namespace BalestraEngine
{
	class Balestra2DRect : public Balestra2DWorldObject
	{
		public:

			// == METHODS ======================================
			virtual void loadContent(BalestraWorld* world) override;
			virtual void unloadContent(BalestraWorld* world) override;
			virtual void update(BalestraGameTime* gameTime) override;
			virtual void draw(BalestraRenderGear* renderGear) override;
			
			// == GETTERS AND SETTERS ==========================

		private:
		protected:

			// == VAR & CONST ==================================
	};
}

#endif 