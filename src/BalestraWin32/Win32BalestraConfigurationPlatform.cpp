// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

#pragma once;

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraConfigurationPlatform.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	Win32BalestraConfigurationPlatform::Win32BalestraConfigurationPlatform()
	{

	}

	Win32BalestraConfigurationPlatform::~Win32BalestraConfigurationPlatform()
	{

	}

	void Win32BalestraConfigurationPlatform::gatherSystemInformation()
	{
		gatherSOInfo();
	}

	void Win32BalestraConfigurationPlatform::gatherSOInfo()
	{
		// -- GATHERING OPERATIONAL SYSTEM INFO ----------------------

		if (!IsWindowsXPOrGreater())
		{
			operationalSystem = BPLATFORM_OS_UNSUPORTED;
			return;
		}

		if (!IsWindowsXPSP1OrGreater())
		{
			operationalSystem = BPLATFORM_OS_XP;
			return;
		}

		if (!IsWindowsXPSP2OrGreater())
		{
			operationalSystem = BPLATFORM_OS_XP_SP1;
			return;
		}

		if (!IsWindowsXPSP3OrGreater())
		{
			operationalSystem = BPLATFORM_OS_XP_SP2;
			return;
		}

		if (!IsWindowsVistaOrGreater())
		{
			operationalSystem = BPLATFORM_OS_XP_SP3;
			return;
		}

		if (!IsWindowsVistaSP1OrGreater())
		{
			operationalSystem = BPLATFORM_OS_VISTA;
			return;
		}

		if (!IsWindowsVistaSP2OrGreater())
		{
			operationalSystem = BPLATFORM_OS_VISTA_SP1;
			return;
		}

		if (!IsWindows7OrGreater())
		{
			operationalSystem = BPLATFORM_OS_VISTA_SP2;
			return;
		}

		if (!IsWindows7SP1OrGreater())
		{
			operationalSystem = BPLATFORM_OS_WIN7;
			return;
		}

		if (!IsWindows8OrGreater())
		{
			operationalSystem = BPLATFORM_OS_WIN7_SP1;
			return;
		}

		if (!IsWindows8Point1OrGreater())
		{
			operationalSystem = BPLATFORM_OS_WIN8;
			return;
		}
		else
		{
			operationalSystem = BPLATFORM_OS_WIN8_1;
			return;
		}

		operationalSystem = BPLATFORM_OS_UNSUPORTED;
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	HINSTANCE Win32BalestraConfigurationPlatform::getWin32Instance()
	{
		return Win32BalestraConfigurationPlatform::win32Instance;
	}

	void Win32BalestraConfigurationPlatform::setWin32Instance(HINSTANCE hInstance)
	{
		Win32BalestraConfigurationPlatform::win32Instance = hInstance;
	}

	HWND Win32BalestraConfigurationPlatform::getMainWindowHandle()
	{
		return Win32BalestraConfigurationPlatform::mainWindowHandle;
	}

	void Win32BalestraConfigurationPlatform::setMainWindowHandle(HWND handle)
	{
		Win32BalestraConfigurationPlatform::mainWindowHandle = handle;
	}

	BRect* Win32BalestraConfigurationPlatform::getWindowRect()
	{
		return &(Win32BalestraConfigurationPlatform::windowRect);
	}

	void Win32BalestraConfigurationPlatform::setWindowRect(BRect rect)
	{
		Win32BalestraConfigurationPlatform::windowRect = rect;
	}

	B_BOOL Win32BalestraConfigurationPlatform::getRunOnBackground()
	{
		return Win32BalestraConfigurationPlatform::runOnBackground;
	}

	void Win32BalestraConfigurationPlatform::setRunOnBackground(B_BOOL value)
	{
		Win32BalestraConfigurationPlatform::runOnBackground = value;
	}

	B_BOOL Win32BalestraConfigurationPlatform::getUseCustomIco()
	{
		return Win32BalestraConfigurationPlatform::useCustomIco;
	}

	void Win32BalestraConfigurationPlatform::setUseCustomIco(B_BOOL value)
	{
		Win32BalestraConfigurationPlatform::useCustomIco = value;
	}

	B_BOOL Win32BalestraConfigurationPlatform::getMouseCursorVisibility()
	{
		return Win32BalestraConfigurationPlatform::mouseCursorVisibility;
	}

	void Win32BalestraConfigurationPlatform::setMouseCursorVisibility(B_BOOL visibility)
	{
		Win32BalestraConfigurationPlatform::mouseCursorVisibility = visibility;
	}

	HICON Win32BalestraConfigurationPlatform::getAppIcon()
	{
		return Win32BalestraConfigurationPlatform::appIcon;
	}

	void Win32BalestraConfigurationPlatform::setAppIcon(HICON icon)
	{
		Win32BalestraConfigurationPlatform::appIcon = icon;
	}

	int Win32BalestraConfigurationPlatform::getOperationalSystem()
	{
		return Win32BalestraConfigurationPlatform::operationalSystem;
	}
}