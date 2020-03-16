// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraWorld.h"
#include "BalestraEnvironment.h"
#include "BalestraEnvironmentVideo.h"
#include "BalestraRenderGear.h"
#include "BalestraDataTypes.h"
#include "BalestraConfiguration.h"
#include "BalestraGameTime.h"
#include "BalestraUserCommunication.h"
#include "Balestra2DText.h"
#include "BalestraDebugText.h"
#include "BalestraConfigurationGameTime.h"
#include "BalestraConfigurationDebug.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BalestraWorld::BalestraWorld()
	{
		
	}

	BalestraWorld::BalestraWorld(BalestraRenderGear* renderGear)
	{
		BalestraWorld::renderGear = renderGear;
	}

	BalestraWorld::~BalestraWorld()
	{
		
	}

	void BalestraWorld::loadContent()
	{
		if (!renderGear)
		{
			renderGear = env->getVideoEnvironment()->createRenderGear();
		}
	}

	void BalestraWorld::unloadContent()
	{
		if (renderGear)
		{
			delete renderGear;
			renderGear = { 0 };
		}
	}

	void BalestraWorld::update(BalestraGameTime* gameTime)
	{

	}

	void BalestraWorld::draw()
	{

	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	BalestraEnvironment* BalestraWorld::getEnvironment()
	{
		return BalestraWorld::env;
	}

	void BalestraWorld::setEnvironment(BalestraEnvironment* env)
	{
		BalestraWorld::env = env;
	}

	B32ARGBColorFloat* BalestraWorld::getBackgroundColor()
	{
		return &backgroundColor;
	}

	void BalestraWorld::setBackgroundColor(B32ARGBColorFloat color)
	{
		BalestraWorld::backgroundColor = color;
	}
}