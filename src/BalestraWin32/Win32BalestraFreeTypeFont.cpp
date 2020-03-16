// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraFreeTypeFont.h"
#include "Win32BalestraOpenGLTexture.h"

namespace BalestraEngine
{
	Win32BalestraFreeTypeFont::Win32BalestraFreeTypeFont() : BalestraFont()
	{

	}

	Win32BalestraFreeTypeFont::~Win32BalestraFreeTypeFont()
	{

	}

	void Win32BalestraFreeTypeFont::unloadResource()
	{

	}

	// == GETTERS AND SETTERS
	// ==============================================

	BalestraGlyph Win32BalestraFreeTypeFont::getCharAt(int pos)
	{
		return Win32BalestraFreeTypeFont::characterMap[pos];
	}

	void Win32BalestraFreeTypeFont::setCharAt(BalestraGlyph value, int pos)
	{
		Win32BalestraFreeTypeFont::characterMap[pos] = value;
	}

	std::string Win32BalestraFreeTypeFont::getFilePath()
	{
		return Win32BalestraFreeTypeFont::filePath;
	}

	void Win32BalestraFreeTypeFont::setFilePath(std::string value)
	{
		Win32BalestraFreeTypeFont::filePath = value;
	}

}