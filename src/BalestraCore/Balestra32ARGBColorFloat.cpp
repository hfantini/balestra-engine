// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "Balestra32ARGBColorFloat.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	B32ARGBColorFloat::B32ARGBColorFloat()
	{
		B32ARGBColorFloat::alpha = 1;
		B32ARGBColorFloat::red = 0;
		B32ARGBColorFloat::green = 0;
		B32ARGBColorFloat::blue = 0;
	}

	B32ARGBColorFloat::B32ARGBColorFloat(float alpha, float red, float green, float blue)
	{
		B32ARGBColorFloat::alpha = alpha;
		B32ARGBColorFloat::red = red;
		B32ARGBColorFloat::green = green;
		B32ARGBColorFloat::blue = blue;
	}

	float B32ARGBColorFloat::getAlpha()
	{
		return B32ARGBColorFloat::alpha;
	}

	void B32ARGBColorFloat::setAlpha(float alpha)
	{
		B32ARGBColorFloat::alpha = alpha;
	}

	float B32ARGBColorFloat::getRed()
	{
		return B32ARGBColorFloat::red;
	}

	void B32ARGBColorFloat::setRed(float red)
	{
		B32ARGBColorFloat::red = red;
	}

	float B32ARGBColorFloat::getGreen()
	{
		return B32ARGBColorFloat::green;
	}

	void B32ARGBColorFloat::setGreen(float green)
	{
		B32ARGBColorFloat::green = green;
	}

	float B32ARGBColorFloat::getBlue()
	{
		return B32ARGBColorFloat::blue;
	}

	void B32ARGBColorFloat::setBlue(float blue)
	{
		B32ARGBColorFloat::blue = blue;
	}
}
