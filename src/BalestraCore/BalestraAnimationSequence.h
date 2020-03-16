// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BANIMATION_SEQUENCE

#define _INC_BANIMATION_SEQUENCE

#include "BalestraPrecompiledHeader.h"

namespace BalestraEngine
{
	#define ON_SEQUENCE_END_REPEAT 0
	#define ON_SEQUENCE_END_PAUSE 1
	#define ON_SQUENCE_END_STOP 2

	class BalestraImage;

	class BalestraAnimationSequence
	{
		public:

			// == METHODS ======================================
			BalestraAnimationSequence();
			BalestraAnimationSequence(BalestraImage* image);
			BalestraAnimationSequence(BalestraImage* imageArray[]);
			~BalestraAnimationSequence();

			void addImage(BalestraImage* image);
			void removeImage(int frame);
			void removeImage(BalestraImage* image);

			// == GETTERS AND SETTERS ==========================
			BalestraImage* getFrame(int frame);
			int getSizeOfSequence();
			int getAnimationUpdateRateMs();
			void setAnimtionUpdateRateMs(int rate);
			int getOnSequenceEnd();
			void setOnSequenceEnd(int onSequenceEnd);

		private:

			// == VAR & CONST ===================================
			int onSequenceEnd = ON_SEQUENCE_END_REPEAT;
			int animationUpdateRateMs = 0;
			std::vector<BalestraImage*> bImageVector;

		protected:
	};
}

#endif