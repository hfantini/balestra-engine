
// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraEnvironmentVideo.h"
#include "BalestraRenderGear.h"
#include "Balestra32ARGBColorFloat.h"
#include "BalestraCamera.h"
#include "BalestraDoubleVector.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BalestraEnvironmentVideo::BalestraEnvironmentVideo(BalestraConfiguration* configuration)
	{
		BalestraEnvironmentVideo::configuration = configuration;

		camera = new BalestraCamera();
	}

	BalestraRenderGear* BalestraEnvironmentVideo::createRenderGear()
	{
		return{ 0 };
	}

	void BalestraEnvironmentVideo::cleanDevice()
	{
		if (camera)
		{
			delete camera;
		}
	}

	void BalestraEnvironmentVideo::cleanRenderTarget(B32ARGBColorFloat* color)
	{

	}

	// == IMPLEMENTATION: Events
	// =====================================================

	void BalestraEnvironmentVideo::resize()
	{
		
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	BalestraCamera* BalestraEnvironmentVideo::getCamera()
	{
		return camera;
	}

}