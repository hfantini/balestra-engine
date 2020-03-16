// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BANIMATION_CONTROLLER

#define _INC_BANIMATION_CONTROLLER

#include "BalestraPrecompiledHeader.h"
#include "BalestraConstants.h"

namespace BalestraEngine
{
	class BalestraAnimationSequence;
	class BalestraGameTime;
	class BalestraImage;

	class BalestraAnimationController
	{
		public:

			// == METHODS ======================================

			BalestraAnimationController();
			~BalestraAnimationController();
			void update(BalestraGameTime* gameTime);

			// == GETTERS AND SETTERS ==========================
			int getAnimationState();
			void setAnimationState(int state);
			int getAnimationPlaySense();
			void setAnimationPlaySense(int platSense);
			int getCurrentFrame();
			void setCurrentFrame(int currentFrame);
			BalestraImage* getCurrentImage();
			BalestraAnimationSequence* getCurrentSequence();
			void setCurrentSequence(BalestraAnimationSequence* sequence);


		private:

			// == VAR & CONST ===================================

			float animationUpdateRateCounter = 0;
			int animationState = ANIMATION_PLAY_STATE;
			int animationPlaySense = ANIMATION_PLAY_SENSE_NORMAL;
			int currentFrame = 0;
			BalestraAnimationSequence* currentSequence;

		protected:
	};
}

#endif