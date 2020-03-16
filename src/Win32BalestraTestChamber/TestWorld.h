// == BALESTRA TEST CHAMBER FOR WIN 32 - Codecraft Productions
// ===========================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_TESTWORLD

#define _INC_TESTWORLD

#include "PCHeader.h"

namespace BalestraEngine
{
	class Win32BalestraEnvironment;
	class BalestraInputMouse;
	class BalestraInputKeyboard;
	class BalestraImageLoader;
	class BalestraSound;
	class BalestraSoundLoader;
	class Balestra2DSprite;
	class Balestra2DText;
	class BalestraSoundChannel;
	class BalestraGameTime;
	class Scenario;
	class Coin;
	class Player;

	class TestWorld : public BalestraWorld
	{
		public:

			// == METHODS ======================================
			TestWorld();
			~TestWorld();

			virtual void loadContent() override;
			virtual void unloadContent() override;
			virtual void update(BalestraGameTime* gameTime) override;
			virtual void draw() override;

			Win32BalestraEnvironment* w32Env;

		private:

			// == VAR & CONST ===================================

			BalestraImage* bgImage;
			Scenario* scenario;
			Coin* coin;
			Player* player;
			BalestraSound* bgMusic;
			Balestra2DSprite* bg;
			Balestra2DText* creatorText;
			BalestraInputMouse* mouse;
			BalestraInputKeyboard* keyboard;
			BalestraImageLoader* imageLoader;
			BalestraSoundLoader* soundLoader;
			BalestraFontLoader* fontLoader;
			BalestraSoundChannel* musicChannel;
			BalestraDebugText* dbgInfo;
			BalestraAnimationSequence* seqBg;
			BalestraFont* font_times_16;

	};
}

#endif