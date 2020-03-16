// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "IBalestraDevice.h"

namespace BalestraEngine
{

	// == IMPLEMENTATION: Methods
	// =====================================================

	B_BOOL IBalestraDevice::isCompatible()
	{
		return B_FALSE;
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	BalestraConfiguration* IBalestraDevice::getConfiguration()
	{
		return configuration;
	}

}