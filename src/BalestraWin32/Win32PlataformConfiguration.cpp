// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================
#include "Win32PlataformConfiguration.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	HINSTANCE Win32PlataformConfiguration::getWin32Instance()
	{
		return Win32PlataformConfiguration::win32Instance;
	}

	void Win32PlataformConfiguration::setWin32Instance(HINSTANCE instance)
	{
		Win32PlataformConfiguration::win32Instance = instance;
	}

	HWND Win32PlataformConfiguration::getMainWindowHandle()
	{
		return Win32PlataformConfiguration::mainWindowHandle;
	}

	void Win32PlataformConfiguration::setMainWindowHandle(HWND handle)
	{
		Win32PlataformConfiguration::mainWindowHandle = handle;
	}
}