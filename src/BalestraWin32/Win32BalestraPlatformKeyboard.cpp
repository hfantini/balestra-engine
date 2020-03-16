// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraPlatformKeyboard.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	Win32BalestraPlatformKeyboard::Win32BalestraPlatformKeyboard(BalestraConfiguration* configuration) : BalestraInputKeyboard(configuration)
	{

	}

	int Win32BalestraPlatformKeyboard::getKeyState(short key)
	{
		if (GetAsyncKeyState(key))
		{
			return BKEYBOARD_KEY_DOWN;
		}
		else
		{
			return BKEYBOARD_KEY_UP;
		}
	}

}