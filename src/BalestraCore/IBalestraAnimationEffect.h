// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_IBALESTRA_ANIMATION

#define _INC_IBALESTRA_ANIMATION

#include "BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
#define ANIMATION_EFFECT_STATE_RUNNING 1
#define ANIMATION_EFFECT_STATE_FINISHED 2

	class BalestraGameTime;

	class IBalestraAnimationEffect
	{
		public:

			// == METHODS ======================================
			virtual void apply(BalestraGameTime* gameTime) = 0;
			virtual void reset() = 0;
			virtual void unloadEffect() = 0;

			// == GETTERS AND SETTERS ==========================
			float getAnimationRate();
			void setAnimationRate(float animationRate);
			int getAnimationState();

		private:

			// == VAR & CONST ===================================
			float animationRate = 0.f;		

		protected:

			// == VAR & CONST ===================================
			int animationState = 0;
	};
}

#endif