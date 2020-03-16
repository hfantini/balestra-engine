// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BANIMATION_COLOR

#define _INC_BANIMATION_COLOR

#include "BalestraPrecompiledHeader.h"
#include "IBalestraAnimationEffect.h"
#include "Balestra32ARGBColorFloat.h"

namespace BalestraEngine
{
	class BalestraAnimationEffectColor : public IBalestraAnimationEffect
	{
		public:

			// == METHODS ======================================
			BalestraAnimationEffectColor();
			~BalestraAnimationEffectColor();

			void apply(BalestraGameTime* gameTime) override;
			void reset() override;
			void unloadEffect() override;

			// == GETTERS AND SETTERS ==========================
			B32ARGBColorFloat* getCurrentColor();
			void setCurrentColor(B32ARGBColorFloat* color);
			B32ARGBColorFloat* getTargetColor();
			void setTargetColor(B32ARGBColorFloat* target);

		private:

			// == VAR & CONST ===================================
			B32ARGBColorFloat* currentColor;
			B32ARGBColorFloat* targetColor;

		protected:
	};
}

#endif