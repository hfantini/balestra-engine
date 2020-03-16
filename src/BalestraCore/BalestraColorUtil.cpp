// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraColorUtil.h"

namespace BalestraEngine
{
	B32ARGBColorFloat BalestraColorUtil::convertToFloatColor(B32ARGBColorUInt color)
	{
		return B32ARGBColorFloat(float(color.getAlpha()) / 255, float(color.getRed()) / 255, float(color.getGreen()) / 255, float(color.getBlue()) / 255 );
	}

	B32ARGBColorUInt BalestraColorUtil::convertToUIntColor(B32ARGBColorFloat color)
	{
		return B32ARGBColorUInt(int(color.getAlpha()) * 255, int(color.getRed()) * 255, int(color.getGreen()) * 255, int(color.getBlue()) * 255);
	}

	B_BOOL BalestraColorUtil::compareColor(B32ARGBColorFloat* color1, B32ARGBColorFloat* color2)
	{
		if (color1->getAlpha() != color2->getAlpha())
		{
			return B_FALSE;
		}

		if (color1->getRed() != color2->getRed())
		{
			return B_FALSE;
		}

		if (color1->getGreen() != color2->getGreen())
		{
			return B_FALSE;
		}

		if (color1->getBlue() != color2->getBlue())
		{
			return B_FALSE;
		}

		return B_TRUE;
	}
}

