// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraTypeConverter.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	std::string BalestraTypeConverter::convertFloatToString(float value, int precision)
	{
		std::ostringstream returnValue;

		returnValue << std::setprecision(precision) << std::fixed << value;

		return returnValue.str();
	}
}