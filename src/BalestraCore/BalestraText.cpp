// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraText.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BalestraText::BalestraText()
	{

	}

	BalestraText::BalestraText(std::string fontName, float fontSize)
	{
		BalestraText::fontName = fontName;
		BalestraText::fontSize = fontSize;
	}

	BalestraText::~BalestraText()
	{

	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	std::string BalestraText::getFontName()
	{
		return BalestraText::fontName;
	}

	void BalestraText::setFontName(std::string fontName)
	{
		BalestraText::fontName = fontName;
	}

	float BalestraText::getFontSize()
	{
		return BalestraText::fontSize;
	}

	void BalestraText::setFontSize(float fontSize)
	{
		BalestraText::fontSize = fontSize;
	}


}