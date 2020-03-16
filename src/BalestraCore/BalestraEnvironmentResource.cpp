// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraEnvironmentResource.h"
#include "BalestraImageLoader.h"
#include "BalestraSoundLoader.h"
#include "BalestraFontLoader.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BalestraEnvironmentResource::BalestraEnvironmentResource(BalestraConfiguration* configuration, BalestraEnvironmentVideo* videoEnvironment)
	{
		BalestraEnvironmentResource::configuration = configuration;
		BalestraEnvironmentResource::videoEnvironment = videoEnvironment;
	}

	BalestraImageLoader* BalestraEnvironmentResource::createImageLoader()
	{
		return { 0 };
	}

	BalestraSoundLoader* BalestraEnvironmentResource::createSoundLoader()
	{
		return{ 0 };
	}

	BalestraFontLoader* BalestraEnvironmentResource::createFontLoader()
	{
		return{ 0 };
	}
}