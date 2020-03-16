// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// ===========================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraImageButton.h"
#include "BalestraInputMouse.h"
#include "BalestraImageLoader.h"
#include "BalestraAnimationSequence.h"
#include "BalestraAnimationController.h"
#include "BalestraMath.h"
#include "BalestraRect.h"
#include "BalestraEnvironmentInput.h"
#include "BalestraConfiguration.h"
#include "BalestraConfigurationInput.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BalestraImageButton::BalestraImageButton(BalestraEnvironmentInput* envInput, BalestraImageLoader* loader)
	{
		BalestraImageButton::envInput = envInput;
		BalestraImageButton::imageLoader = loader;
	}

	BalestraImageButton::~BalestraImageButton()
	{
		BalestraImageButton::unloadContent(currentWorld);
	}

	void BalestraImageButton::unloadContent(BalestraWorld* world)
	{
		Balestra2DSprite::unloadContent(world);

		if (mOverSeq)
		{
			delete mOverSeq;
		}

		if (normalSeq)
		{
			delete normalSeq;
		}
	}

	void BalestraImageButton::update(BalestraGameTime* gameTime)
	{
		if (envInput->getConfiguration()->getInputConfiguration()->getInputType() == BINPUT_TYPE_KEYBOARD_MOUSE)
		{
			BDoubleVector mousePos = BDoubleVector(envInput->getMouseDevice()->getMouseState()->X, envInput->getMouseDevice()->getMouseState()->Y);
			getAnimationController()->setCurrentSequence(normalSeq);

			if (BalestraMath::isPointInsideRect(&mousePos, &(getRect())))
			{
				if (envInput->getMouseDevice()->getMouseState()->lButtonState == BMOUSE_BUTTON_DOWN)
				{
					buttonState = BUTTON_STATE_MOUSE_CLICK;
				}
				else
				{
					if (buttonState == BUTTON_STATE_MOUSE_CLICK)
					{
						buttonState = BUTTON_STATE_MOUSE_RELEASE;
						getAnimationController()->setCurrentSequence(mOverSeq);
					}
					else
					{
						buttonState = BUTTON_STATE_MOUSE_OVER;
						getAnimationController()->setCurrentSequence(mOverSeq);
					}
				}
			}
			else
			{
				buttonState = BUTTON_STATE_NORMAL;
			}
		}
		else
		{
			//THROW EXCEPTION
		}

		Balestra2DSprite::update(gameTime);
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	int BalestraImageButton::getButtonState()
	{
		return BalestraImageButton::buttonState;
	}

	void BalestraImageButton::setButtonState(int state)
	{
		BalestraImageButton::buttonState = state;
	}

	BalestraAnimationSequence* BalestraImageButton::getNormalSequence()
	{
		return BalestraImageButton::normalSeq;
	}

	void BalestraImageButton::setNormalSequence(BalestraAnimationSequence* seq)
	{
		BalestraImageButton::normalSeq = seq;
	}

	BalestraAnimationSequence* BalestraImageButton::getMouseOverSequence()
	{
		return BalestraImageButton::mOverSeq;
	}

	void BalestraImageButton::setMouseOverSequence(BalestraAnimationSequence* seq)
	{
		BalestraImageButton::mOverSeq = seq;
	}

}
