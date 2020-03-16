
// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraConfiguration.h"
#include "BalestraConfigurationPlatform.h"
#include "BalestraConfigurationVideo.h"
#include "BalestraConfigurationSound.h"
#include "BalestraConfigurationInput.h"
#include "BalestraConfigurationGameTime.h"
#include "BalestraConfigurationDebug.h"
#include "BalestraConfigurationDecoder.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	BalestraConfiguration::BalestraConfiguration()
	{
		videoConfiguration = new BalestraConfigurationVideo();
		soundConfiguration = new BalestraConfigurationSound();
		gameTimeConfiguration = new BalestraConfigurationGameTime();
		debugConfiguration = new BalestraConfigurationDebug();
		decoderConfiguration = new BalestraConfigurationDecoder();
	}

	BalestraConfiguration::~BalestraConfiguration()
	{
		if (videoConfiguration)
		{
			delete videoConfiguration;
		}

		if (soundConfiguration)
		{
			delete soundConfiguration;
		}

		if (gameTimeConfiguration)
		{
			delete gameTimeConfiguration;
		}

		if (debugConfiguration)
		{
			delete debugConfiguration;
		}

		if (decoderConfiguration)
		{
			delete decoderConfiguration;
		}
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	BalestraConfigurationVideo* BalestraConfiguration::getVideoConfiguration()
	{
		return videoConfiguration;
	}

	BalestraConfigurationSound* BalestraConfiguration::getSoundConfiguration()
	{
		return soundConfiguration;
	}

	BalestraConfigurationInput* BalestraConfiguration::getInputConfiguration()
	{
		return inputConfiguration;
	}

	BalestraConfigurationGameTime* BalestraConfiguration::getGameTimeConfiguration()
	{
		return gameTimeConfiguration;
	}

	BalestraConfigurationDebug* BalestraConfiguration::getDebugConfiguration()
	{
		return debugConfiguration;
	}

	BalestraConfigurationDecoder* BalestraConfiguration::getDecoderConfiguration()
	{
		return decoderConfiguration;
	}
}