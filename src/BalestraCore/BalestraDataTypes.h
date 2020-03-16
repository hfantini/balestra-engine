// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#ifndef _INC_BDATA_TYPE

#define _INC_BDATA_TYPE

namespace BalestraEngine
{

// == NORMAL TYPES
// ==================================

// -- DEFAULT BOOLEAN SYSTEM --------

	typedef int B_BOOL;
	#define B_TRUE 1
	#define B_FALSE 0

// -- DEFAULT BYTE SYSTEM -----------
	typedef unsigned char B_UNSIGNED_BYTE;
	#define UNSIGNED_BYTE_MIN VALUE 0
	#define UNSIGNED_BYTE_MAX_VALUE 255

// -- DEFAULT VERTEX SYSTEM ---------

	struct BalestraVertex
	{
		float X, Y, Z;
	};

// -- MOUSE STATE -------------------

	struct BMouseState
	{
		long X;
		long Y;
		int lButtonState;
		int mButtonState;
		int rButtonState;
	};

}

#endif