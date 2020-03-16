// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraEnvironmentSound.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BalestraEnvironmentSound::BalestraEnvironmentSound(BalestraConfiguration* configuration)
	{
		BalestraEnvironmentSound::configuration = configuration;
	}

	BalestraSoundChannel* BalestraEnvironmentSound::createSoundChannel()
	{
		return { 0 };
	}
}