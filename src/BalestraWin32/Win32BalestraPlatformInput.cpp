// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraConfiguration.h"
#include "Win32BalestraPlatformInput.h"
#include "Win32BalestraPlatformMouse.h"
#include "Win32BalestraPlatformKeyboard.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	Win32BalestraPlatformInput::Win32BalestraPlatformInput(BalestraConfiguration* configuration) : BalestraEnvironmentInput(configuration)
	{
		Win32BalestraPlatformInput::configuration = configuration;
	}

	Win32BalestraPlatformInput::~Win32BalestraPlatformInput()
	{
		cleanDevice();
	}

	void Win32BalestraPlatformInput::initDevice()
	{
		switch (configuration->getInputConfiguration()->getInputType())
		{
			case BINPUT_TYPE_KEYBOARD_MOUSE:
				mouse = new Win32BalestraPlatformMouse(configuration);
				keyboard = new Win32BalestraPlatformKeyboard(configuration);
				break;

			default:
				//THROW EXCEPTION
				break;
		}
	}

	B_BOOL Win32BalestraPlatformInput::isCompatible()
	{
		return B_TRUE;
	}

	void Win32BalestraPlatformInput::cleanDevice()
	{
		if (mouse)
		{
			delete mouse;
			mouse = { 0 };
		}

		if (keyboard)
		{
			delete keyboard;
			keyboard = { 0 };
		}
	}

	BalestraInputMouse* Win32BalestraPlatformInput::getMouseDevice()
	{
		return Win32BalestraPlatformInput::mouse;
	}

	BalestraInputKeyboard* Win32BalestraPlatformInput::getKeyboardDevice()
	{
		return Win32BalestraPlatformInput::keyboard;
	}


	Win32BalestraConfiguration* Win32BalestraPlatformInput::getW32Configuration()
	{
		return static_cast<Win32BalestraConfiguration*>(configuration);
	}
}