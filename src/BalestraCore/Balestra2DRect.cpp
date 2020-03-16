// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F,

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "Balestra2DRect.h"
#include "BalestraRenderGear.h"

// == IMPLEMENTATION: Methods
// =====================================================

namespace BalestraEngine
{
	void Balestra2DRect::loadContent(BalestraWorld* world)
	{
		Balestra2DWorldObject::loadContent(world);
	}

	void Balestra2DRect::unloadContent(BalestraWorld* world)
	{
		Balestra2DWorldObject::unloadContent(world);
	}

	void Balestra2DRect::update(BalestraGameTime* gameTime)
	{
		updateOriginPoint();
		Balestra2DWorldObject::update(gameTime);
	}

	void Balestra2DRect::draw(BalestraRenderGear* renderGear)
	{
		Balestra2DWorldObject::draw(renderGear);
		renderGear->draw2DRect(this);
	}
	
	// == IMPLEMENTATION: Getters and Setters
	// =====================================================
}
