// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "Balestra2DPhysics.h"
#include "BalestraRect.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	B_BOOL Balestra2DPhysics::checkBBoxCollision(BRect obj1, BRect obj2)
	{
		B_BOOL retValue = B_TRUE;

		if (retValue != B_FALSE && obj1.getX() > obj2.getWidth())
		{
			retValue = B_FALSE;
		}

		if (retValue != B_FALSE && obj1.getWidth() < obj2.getX())
		{
			retValue = B_FALSE;
		}

		if (retValue != B_FALSE && obj1.getY() > obj2.getHeight())
		{
			retValue = B_FALSE;
		}

		if (retValue != B_FALSE && obj1.getHeight() < obj2.getY())
		{
			retValue = B_FALSE;
		}

		return retValue;
	}
}