// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BANIMATION_DOUBLE_VECTOR

#define _INC_BANIMATION_DOUBLE_VECTOR

#include "BalestraPrecompiledHeader.h"
#include "IBalestraAnimationEffect.h"

namespace BalestraEngine
{
	class BDoubleVector;

	class BalestraAnimationEffectDoubleVector : public IBalestraAnimationEffect
	{
		public:

			// == METHODS ======================================
			BalestraAnimationEffectDoubleVector();
			~BalestraAnimationEffectDoubleVector();

			void apply(BalestraGameTime* gameTime) override;
			void reset() override;
			void unloadEffect() override;

			// == GETTERS AND SETTERS ==========================
			BDoubleVector* getCurrentVector();
			void setCurrentVector(BDoubleVector* cVector);
			BDoubleVector* getTargetVector();
			void setTargetVector(BDoubleVector* tVector);

		private:

			// == VAR & CONST ===================================
			BDoubleVector* currentVector;
			BDoubleVector* targetVector;

		protected:
	};
}

#endif