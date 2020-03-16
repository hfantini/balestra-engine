// == BALESTRA TEST CHAMBER FOR WIN 32 - Codecraft Productions
// ===========================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_COIN

#define _INC_COIN

#include "PCHeader.h"

namespace BalestraEngine
{

	class BalestraAnimationSequence;
	class BalestraImageLoader;

	class Coin : public Balestra2DSprite
	{
		public:

			Coin(BalestraImageLoader* imageLoader);
			~Coin();
			void loadContent(BalestraWorld* world) override;
			void unloadContent(BalestraWorld* world) override;
			void update(BalestraGameTime* gameTime) override;
			void draw(BalestraRenderGear* renderGear) override;


		private:

			BalestraImageLoader* imageLoader;

			//SPRITES

			BalestraImage* mSeq1;
			BalestraImage* mSeq2;
			BalestraImage* mSeq3;
			BalestraImage* mSeq4;
			BalestraImage* mSeq5;
			BalestraImage* mSeq6;
			BalestraImage* mSeq7;
			BalestraAnimationSequence* seqCoin;

		protected:
	};
}

#endif