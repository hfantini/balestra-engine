// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraD2D1Bitmap.h"

namespace BalestraEngine
{

	Win32BalestraD2D1Bitmap::Win32BalestraD2D1Bitmap() : BalestraImage()
	{

	}

	Win32BalestraD2D1Bitmap::~Win32BalestraD2D1Bitmap()
	{
		unloadResource();
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	void Win32BalestraD2D1Bitmap::unloadResource()
	{
		if (source)
		{
			source->Release();
			source = NULL;
		}
	}

	ID2D1Bitmap* Win32BalestraD2D1Bitmap::getSource()
	{
		return Win32BalestraD2D1Bitmap::source;
	}

	void Win32BalestraD2D1Bitmap::setSource(ID2D1Bitmap* source)
	{
		Win32BalestraD2D1Bitmap::source = source;
	}
}