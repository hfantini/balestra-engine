// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BSPRITE_2D

#define _INC_BSPRITE_2D

#include "BalestraPrecompiledHeader.h"
#include "Balestra2DWorldObject.h"

namespace BalestraEngine
{
	class BalestraImage;
	class BalestraAnimationController;

	class Balestra2DSprite : public Balestra2DWorldObject
	{
		public:


			// == METHODS ======================================
			Balestra2DSprite();
			~Balestra2DSprite();

			virtual void loadContent(BalestraWorld* world) override;
			virtual void unloadContent(BalestraWorld* world) override;
			virtual void update(BalestraGameTime* gameTime) override;
			virtual void draw(BalestraRenderGear* renderGear) override;

			// == GETTERS AND SETTERS ==========================

			BalestraAnimationController* getAnimationController();
			int getSizeMode();
			void setSizeMode(int sizeMode);

		private:

			// == VAR & CONST ===================================
			int sizeMode = OBJ_SIZE_MODE_AUTO;
			BalestraAnimationController* animationController;

		protected:
	};
}

#endif