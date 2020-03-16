// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraCamera.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BalestraCamera::BalestraCamera()
	{
		BalestraCamera::X = 0;
		BalestraCamera::Y = 0;
		BalestraCamera::Z = 0;
	}

	BalestraCamera::BalestraCamera(float X, float Y, float Z)
	{
		BalestraCamera::X = X;
		BalestraCamera::Y = Y;
		BalestraCamera::Z = Z;
	}

	BalestraCamera::~BalestraCamera()
	{

	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	float BalestraCamera::getX()
	{
		return BalestraCamera::X;
	}

	void BalestraCamera::setX(float X)
	{
		BalestraCamera::X = X;
	}

	float BalestraCamera::getY()
	{
		return BalestraCamera::Y;
	}

	void BalestraCamera::setY(float Y)
	{
		BalestraCamera::Y = Y;
	}

	float BalestraCamera::getZ()
	{
		return BalestraCamera::Z;
	}

	void BalestraCamera::setZ(float Z)
	{
		BalestraCamera::Z = Z;
	}
}
