// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraConfigurationSound.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	int BalestraConfigurationSound::getSoundInterface()
	{
		return BalestraConfigurationSound::soundInterface;
	}

	void BalestraConfigurationSound::setSoundInterface(int soundInterface)
	{
		BalestraConfigurationSound::soundInterface = soundInterface;
	}
}