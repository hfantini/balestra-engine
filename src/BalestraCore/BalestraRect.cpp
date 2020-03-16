// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraRect.h"

namespace BalestraEngine
{

	// == IMPLEMENTATION: Methods
	// =====================================================

	BRect::BRect()
	{
		BRect::X = 0;
		BRect::Y = 0;
		BRect::width = 0;
		BRect::height = 0;
	}

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


	// == IMPLEMENTATION: Getters and Setters
	// =====================================================
}
