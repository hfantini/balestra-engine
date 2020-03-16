// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "Balestra2DText.h"
#include "BalestraRenderGear.h"
#include "BalestraText.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	Balestra2DText::Balestra2DText(BalestraFont* font, std::string text)
	{
		setFont(font);
		setText(text);
	}

	Balestra2DText::~Balestra2DText()
	{
		unloadContent(currentWorld);
	}

	void Balestra2DText::loadContent(BalestraWorld* world)
	{
		Balestra2DWorldObject::loadContent(world);
	}

	void Balestra2DText::unloadContent(BalestraWorld* world)
	{
		Balestra2DWorldObject::unloadContent(world);
	}

	void Balestra2DText::update(BalestraGameTime* gameTime)
	{
		Balestra2DWorldObject::update(gameTime);

		Balestra2DWorldObject::updateOriginPoint();
	}

	void Balestra2DText::draw(BalestraRenderGear* renderGear)
	{
		Balestra2DWorldObject::draw(renderGear);

		renderGear->draw2DText(this);
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	std::string Balestra2DText::getText()
	{
		return Balestra2DText::text;
	}

	void Balestra2DText::setText(std::string text)
	{
		Balestra2DText::text = text;
	}

	BalestraFont* Balestra2DText::getFont()
	{
		return Balestra2DText::font;
	}

	void Balestra2DText::setFont(BalestraFont* font)
	{
		Balestra2DText::font = font;
	}

}