// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraDataTypes.h"

namespace BalestraEngine
{
	// == BRect ==============================================

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	BRect::BRect(float X, float Y, float width, float height)
	{
		BRect::X = X;
		BRect::Y = Y;
		BRect::width = width;
		BRect::height = height;
	}

	float BRect::getX()
	{
		return BRect::X;
	}

	void BRect::setX(float X)
	{
		BRect::X = X;
	}

	float BRect::getY()
	{
		return BRect::Y;
	}

	void BRect::setY(float Y)
	{
		BRect::Y = Y;
	}

	float BRect::getWidth()
	{
		return BRect::width;
	}

	void BRect::setWidth(float width)
	{
		BRect::width = width;
	}

	float BRect::getHeight()
	{
		return BRect::height;
	}

	void BRect::setHeight(float height)
	{
		BRect::height = height;
	}

	// == BDoubleVector ======================================

	// == IMPLEMENTATION: Getters and Setters
	// =======================================================

	BDoubleVector::BDoubleVector(float x, float y)
	{
		BDoubleVector::X = x;
		BDoubleVector::Y = y;
	}

	float BDoubleVector::getX()
	{
		return BDoubleVector::X;
	}

	void BDoubleVector::setX(float X)
	{
		BDoubleVector::X = X;
	}

	float BDoubleVector::getY()
	{
		return BDoubleVector::Y;
	}

	void BDoubleVector::setY(float Y)
	{
		BDoubleVector::Y = Y;
	}

	// == COLOR METHODS 
	// =======================================

	float byteColorToFloat(B_BYTE color)
	{
		if (color >= 255)
		{
			//throw new BalestraMathException("An exception occurred when a color convertion function was called", "The value of color need to be minor than the max (255).", "Change the value and try again.");
		}
		else
		{
			return (float(color) / 255);
		}
	}

	B_BYTE floatColorToByte(float color)
	{
		if (color < 0)
		{
			//throw new BalestraMathException("An exception occurred when a color convertion function was called", "The value of color need to be greater than the min (0.0f).", "Change the value and try again.");
		}
		else if (color > 1.0f)
		{
			//throw new BalestraMathException("An exception occurred when a color convertion function was called", "The value of color need to be minor than the max (1.0f).", "Change the value and try again.");
		}
		else
		{
			return color * BYTE_MAX_VALUE;
		}
	}

	// == B32ARGBColor ========================================

	B32ARGBColor::B32ARGBColor(B_BYTE alpha, B_BYTE red, B_BYTE green, B_BYTE blue)
	{
		B32ARGBColor::alpha = byteColorToFloat(alpha);
		B32ARGBColor::red = byteColorToFloat(red);
		B32ARGBColor::green = byteColorToFloat(green);
		B32ARGBColor::blue = byteColorToFloat(blue);
	}

	B32ARGBColor::B32ARGBColor(float alpha, float red, float green, float blue)
	{
		B32ARGBColor::alpha = alpha;
		B32ARGBColor::red = red;
		B32ARGBColor::green = green;
		B32ARGBColor::blue = blue;
	}

	float B32ARGBColor::getAlpha()
	{
		return B32ARGBColor::alpha;
	}

	void B32ARGBColor::setAlpha(B_BYTE alpha)
	{
		B32ARGBColor::alpha = byteColorToFloat(alpha);
	}

	void B32ARGBColor::setAlpha(float alpha)
	{
		B32ARGBColor::alpha = alpha;
	}

	float B32ARGBColor::getRed()
	{
		return B32ARGBColor::red;
	}

	void B32ARGBColor::setRed(B_BYTE red)
	{
		B32ARGBColor::alpha = byteColorToFloat(red);
	}

	void B32ARGBColor::setRed(float red)
	{
		B32ARGBColor::red = red;
	}

	float B32ARGBColor::getGreen()
	{
		return B32ARGBColor::green;
	}

	void B32ARGBColor::setGreen(B_BYTE green)
	{
		B32ARGBColor::green = byteColorToFloat(green);
	}

	void B32ARGBColor::setGreen(float green)
	{
		B32ARGBColor::green = green;
	}

	float B32ARGBColor::getBlue()
	{
		return B32ARGBColor::blue;
	}

	void B32ARGBColor::setBlue(B_BYTE blue)
	{
		B32ARGBColor::blue = byteColorToFloat(blue);
	}

	void B32ARGBColor::setBlue(float blue)
	{
		B32ARGBColor::blue = blue;
	}
}
