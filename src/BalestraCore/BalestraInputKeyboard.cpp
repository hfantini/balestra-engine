// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraInputKeyboard.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BalestraInputKeyboard::BalestraInputKeyboard(BalestraConfiguration* configuration)
	{
		BalestraInputKeyboard::configuration = configuration;
	}

	int BalestraInputKeyboard::getKeyState(short key)
	{
		return 0;
	}

}