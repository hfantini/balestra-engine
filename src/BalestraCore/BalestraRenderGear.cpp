// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraRenderGear.h"
#include "BalestraEnvironmentVideo.h"
#include "Balestra32ARGBColorFloat.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BalestraRenderGear::BalestraRenderGear(BalestraEnvironmentVideo* videoEnv)
	{
		BalestraRenderGear::videoEnv = videoEnv;
	}

	BalestraRenderGear::~BalestraRenderGear()
	{

	}


	void BalestraRenderGear::startDraw()
	{

	}

	void BalestraRenderGear::draw2DRect(Balestra2DRect* sprite)
	{

	}

	void BalestraRenderGear::draw2DText(Balestra2DText* text)
	{

	}

	void BalestraRenderGear::draw2DSprite(Balestra2DSprite* sprite)
	{

	}

	void BalestraRenderGear::clearRenderTarget(B32ARGBColorFloat* color)
	{

	}

	void BalestraRenderGear::stopDraw()
	{

	}

}