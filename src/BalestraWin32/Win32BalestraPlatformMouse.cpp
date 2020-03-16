// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// ======================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraPlatformMouse.h"
#include "Win32BalestraConfiguration.h"
#include "Win32BalestraConfigurationPlatform.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	Win32BalestraPlatformMouse::Win32BalestraPlatformMouse(BalestraConfiguration* configuration) : BalestraInputMouse(configuration)
	{

	}

	Win32BalestraPlatformMouse::~Win32BalestraPlatformMouse()
	{

	}

	BMouseState* Win32BalestraPlatformMouse::getMouseState()
	{
		return &currentState;
	}

	void Win32BalestraPlatformMouse::updateMouseState()
	{
		// == UPDATING MOUSE POS (RELATIVE TO THE WINDOW) =============

		POINT mPoint;
		GetCursorPos(&mPoint);
		ScreenToClient(getW32Configuration()->getPlatformConfiguration()->getMainWindowHandle(), &mPoint);

		currentState.X = mPoint.x;
		currentState.Y = mPoint.y;

		// CHECKING FOR BUTTONS

		if (GetAsyncKeyState(BMOUSE_LEFT))
		{
			currentState.lButtonState = BMOUSE_BUTTON_DOWN;
		}
		else
		{
			if (currentState.lButtonState == BMOUSE_BUTTON_DOWN)
			{
				currentState.lButtonState = BMOUSE_BUTTON_RELEASED;
			}
			else
			{
				currentState.lButtonState = BMOUSE_BUTTON_UP;
			}
		}

		if (GetAsyncKeyState(BMOUSE_MIDDLE))
		{
			currentState.mButtonState = BMOUSE_BUTTON_DOWN;
		}
		else
		{
			if (currentState.mButtonState == BMOUSE_BUTTON_DOWN)
			{
				currentState.mButtonState = BMOUSE_BUTTON_RELEASED;
			}
			else
			{
				currentState.mButtonState = BMOUSE_BUTTON_UP;
			}
		}

		if (GetAsyncKeyState(BMOUSE_RIGHT))
		{
			currentState.rButtonState = BMOUSE_BUTTON_DOWN;
		}
		else
		{
			if (currentState.rButtonState == BMOUSE_BUTTON_DOWN)
			{
				currentState.rButtonState = BMOUSE_BUTTON_RELEASED;
			}
			else
			{
				currentState.rButtonState = BMOUSE_BUTTON_UP;
			}
		}
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	Win32BalestraConfiguration* Win32BalestraPlatformMouse::getW32Configuration()
	{
		return static_cast<Win32BalestraConfiguration*>(configuration);
	}
}