// == BALESTRA TEST CHAMBER FOR WIN 32 - Codecraft Productions
// ===========================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// ===========================================================

#ifndef _INC_PLAYER

#define _INC_PLAYER

#include "PCHeader.h"

namespace BalestraEngine
{
	#define PLAYER_STATEX_IDLE 0
	#define PLAYER_STATEX_RUN_L 1
	#define PLAYER_STATEX_RUN_R 2
	#define PLAYER_STATEY_LANDED 3
	#define PLAYER_STATEY_FALLING 4
	#define PLAYER_STATEY_JUMPING 6

	class BalestraImageLoader;
	class BalestraSoundLoader;
	class BalestraAnimationSequence;
	class BalestraSound;
	class BalestraSoundChannel;

	class Player : public Balestra2DSprite
	{
		public:

			// == VAR & CONST ===================================
			Player(BalestraImageLoader* imageLoader, BalestraSoundLoader* soundLoader);
			~Player();
			void loadContent(BalestraWorld* world) override;
			void unloadContent(BalestraWorld* world) override;
			void update(BalestraGameTime* gameTime) override;
			void draw(BalestraRenderGear* renderGear) override;
			void idle();

			// == EVENTS ========================================
			void onKeyRightPress();
			void onKeyLeftPress();
			void onSpaceBarPress();
			void onSpaceBarNotPress();

			// == GETTERS AND SETTERS ==========================
			float getVelX();
			void setPlayerIsRunning(B_BOOL value);
			B_BOOL getPlayerIsRunning();

		private:

			// == VAR & CONST ===================================
			float playerStateX = PLAYER_STATEX_IDLE;
			float playerStateY = PLAYER_STATEY_FALLING;
			float playerMaxY = 460;

			float accelX = 0;
			float accelY = 0;
			float maxVelX = 300;
			float maxVelY = 500;
			float velX = 0;
			float velY = 0;
			float posYBeforeJump = 0;
			float maxJump = 135;

			B_BOOL calcJump = B_FALSE;
			B_BOOL canJump = B_FALSE;
			B_BOOL isRunning = B_FALSE;

			BalestraImageLoader* imageLoader;
			BalestraSoundLoader* soundLoader;

			//SPRITES
			BalestraImage* pIdleSeq1;
			BalestraImage* pIdleSeq2;
			BalestraImage* pIdleSeq3;
			BalestraImage* pIdleSeq4;
			BalestraImage* pIdleSeq5;
			BalestraImage* pIdleSeq6;
			BalestraImage* pIdleSeq7;
			BalestraImage* pIdleSeq8;
			BalestraAnimationSequence* seqPlayerIdle;

			BalestraImage* pRunSeq1;
			BalestraImage* pRunSeq2;
			BalestraImage* pRunSeq3;
			BalestraImage* pRunSeq4;
			BalestraImage* pRunSeq5;
			BalestraImage* pRunSeq6;
			BalestraImage* pRunSeq7;
			BalestraImage* pRunSeq8;
			BalestraImage* pRunSeq9;
			BalestraImage* pRunSeq10;
			BalestraAnimationSequence* seqPlayerRun;

			BalestraImage* pPounceSeq1;
			BalestraAnimationSequence* seqPlayerPounce;

			BalestraImage* pJumpSeq1;
			BalestraImage* pJumpSeq2;
			BalestraImage* pJumpSeq3;
			BalestraImage* pJumpSeq4;
			BalestraImage* pJumpSeq5;
			BalestraImage* pJumpSeq6;
			BalestraImage* pJumpSeq7;
			BalestraAnimationSequence* seqPlayerJump;
			
			//SOUND
			BalestraSound* playerWalkSound;
			BalestraSoundChannel* playerWalkChannel;

			// == METHODS ======================================
			void setPlayerStateX(float state);
			void setPlayerStateY(float state);

		protected:
	};
}

#endif