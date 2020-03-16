// == BALESTRA TEST CHAMBER FOR WIN 32 - Codecraft Productions
// ===========================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_SQUARE

#define _INC_SQUARE

#include <Balestra2DSprite.h>
#include <Balestra2DRect.h>
#include <Balestra32ARGBColorSInt.h>

namespace BalestraEngine
{
	class World;

	class Sprite : public Balestra2DSprite
	{
		public:

			Sprite();
			void loadContent(BalestraWorld* world) override;
			void update(BalestraGameTime* gameTime) override;

		private:

		protected:
	};
}

#endif