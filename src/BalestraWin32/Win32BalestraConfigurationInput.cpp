// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraConfigurationInput.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	B_BOOL Win32BalestraConfigurationInput::getAllowMouse()
	{
		return Win32BalestraConfigurationInput::allowMouse;
	}

	void Win32BalestraConfigurationInput::setAllowMouse(int value)
	{
		Win32BalestraConfigurationInput::allowMouse = value;
	}

	B_BOOL Win32BalestraConfigurationInput::getAllowKeyboard()
	{
		return Win32BalestraConfigurationInput::allowKeyboard;
	}

	void Win32BalestraConfigurationInput::setAllowKeyboard(int value)
	{
		Win32BalestraConfigurationInput::allowKeyboard = value;
	}

}