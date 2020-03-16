// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// ===========================================================

#ifndef _INC_COMPONENT_IMAGE_BTN

#define _INC_COMPONENT_IMAGE_BTN

#include "BalestraPrecompiledHeader.h"
#include "Balestra2DSprite.h"

namespace BalestraEngine
{
	#define BUTTON_STATE_NORMAL 1
	#define BUTTON_STATE_MOUSE_OVER 2
	#define BUTTON_STATE_MOUSE_CLICK 3
	#define BUTTON_STATE_MOUSE_RELEASE 4

	class BalestraEnvironmentInput;
	class BalestraImageLoader;
	class BalestraAnimationSequence;

	class BalestraImageButton : public Balestra2DSprite
	{
		public:

			// == METHODS ======================================

			BalestraImageButton(BalestraEnvironmentInput* envInput, BalestraImageLoader* loader);
			~BalestraImageButton();

			void unloadContent(BalestraWorld* world) override;
			void update(BalestraGameTime* world) override;

			// == GETTERS AND SETTERS ==========================
			int getButtonState();
			void setButtonState(int state);
			BalestraAnimationSequence* getNormalSequence();
			void setNormalSequence(BalestraAnimationSequence* seq);
			BalestraAnimationSequence* getMouseOverSequence();
			void setMouseOverSequence(BalestraAnimationSequence* seq);


		private:

		protected:

			int buttonState;

			//RESOURCES
			BalestraEnvironmentInput* envInput;
			BalestraImageLoader* imageLoader;

			//SPRITE
			BalestraAnimationSequence* normalSeq;
			BalestraAnimationSequence* mOverSeq;
	};

}

#endif