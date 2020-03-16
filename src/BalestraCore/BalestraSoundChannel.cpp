// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraSoundChannel.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	void BalestraSoundChannel::play()
	{
		
	}

	void BalestraSoundChannel::stop()
	{

	}

	void BalestraSoundChannel::pause()
	{

	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	BalestraSound* BalestraSoundChannel::getCurrentSound()
	{
		return BalestraSoundChannel::currentSound;
	}

	void BalestraSoundChannel::setCurrentSound(BalestraSound* sound)
	{
		BalestraSoundChannel::currentSound = sound;
	}
}