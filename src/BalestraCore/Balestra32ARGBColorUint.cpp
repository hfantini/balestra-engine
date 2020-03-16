// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "Balestra32ARGBColorUInt.h"

namespace BalestraEngine
{
	B32ARGBColorUInt::B32ARGBColorUInt()
	{
		B32ARGBColorUInt::alpha = 255;
		B32ARGBColorUInt::red = 0;
		B32ARGBColorUInt::green = 0;
		B32ARGBColorUInt::blue = 0;
	}

	B32ARGBColorUInt::B32ARGBColorUInt(B_UNSIGNED_BYTE alpha, B_UNSIGNED_BYTE red, B_UNSIGNED_BYTE green, B_UNSIGNED_BYTE blue)
	{
		B32ARGBColorUInt::alpha = alpha;
		B32ARGBColorUInt::red = red;
		B32ARGBColorUInt::green = green;
		B32ARGBColorUInt::blue = blue;
	}

	B_UNSIGNED_BYTE B32ARGBColorUInt::getAlpha()
	{
		return B32ARGBColorUInt::alpha;
	}

	void B32ARGBColorUInt::setAlpha(B_UNSIGNED_BYTE alpha)
	{
		B32ARGBColorUInt::alpha = alpha;
	}

	B_UNSIGNED_BYTE B32ARGBColorUInt::getRed()
	{
		return B32ARGBColorUInt::red;
	}

	void B32ARGBColorUInt::setRed(B_UNSIGNED_BYTE red)
	{
		B32ARGBColorUInt::red = red;
	}

	B_UNSIGNED_BYTE B32ARGBColorUInt::getGreen()
	{
		return B32ARGBColorUInt::green;
	}

	void B32ARGBColorUInt::setGreen(B_UNSIGNED_BYTE green)
	{
		B32ARGBColorUInt::green = green;
	}

	B_UNSIGNED_BYTE B32ARGBColorUInt::getBlue()
	{
		return B32ARGBColorUInt::blue;
	}

	void B32ARGBColorUInt::setBlue(B_UNSIGNED_BYTE blue)
	{
		B32ARGBColorUInt::blue = blue;
	}
}