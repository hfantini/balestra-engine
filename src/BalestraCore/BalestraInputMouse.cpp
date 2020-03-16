// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraInputMouse.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BalestraInputMouse::BalestraInputMouse(BalestraConfiguration* configuration)
	{
		BalestraInputMouse::configuration = configuration;
	}

	BMouseState* BalestraInputMouse::getMouseState()
	{
		return{ 0 };
	}

	void BalestraInputMouse::updateMouseState()
	{

	}
}