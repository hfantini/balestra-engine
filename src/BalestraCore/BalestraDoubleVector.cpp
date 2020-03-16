// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraDoubleVector.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	BDoubleVector::BDoubleVector()
	{
		BDoubleVector::X = 0;
		BDoubleVector::Y = 0;
	}

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

	void BDoubleVector::incrementX(float value)
	{
		BDoubleVector::X += value;
	}

	void BDoubleVector::incrementY(float value)
	{
		BDoubleVector::Y += value;
	}

	void BDoubleVector::decrementX(float value)
	{
		BDoubleVector::X -= value;
	}

	void BDoubleVector::decrementY(float value)
	{
		BDoubleVector::Y -= value;
	}
}