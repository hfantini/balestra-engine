// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================
#include "BalestraPrecompiledHeader.h"
#include "BalestraDataTypes.h"
#include "BalestraConfigurationGameTime.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	B_BOOL BalestraConfigurationGameTime::getRunning()
	{
		return BalestraConfigurationGameTime::isRunning;
	}

	void BalestraConfigurationGameTime::setRunning(B_BOOL value)
	{
		BalestraConfigurationGameTime::isRunning = value;
	}

	int BalestraConfigurationGameTime::getMode()
	{
		return BalestraConfigurationGameTime::mode;
	}

	void BalestraConfigurationGameTime::setMode(int mode)
	{
		BalestraConfigurationGameTime::mode = mode;
	}

	int BalestraConfigurationGameTime::getTargetFPS()
	{
		return BalestraConfigurationGameTime::targetFPS;
	}

	void BalestraConfigurationGameTime::setTargetFPS(int FPS)
	{
		BalestraConfigurationGameTime::targetFPS = FPS;
	}

	int BalestraConfigurationGameTime::getMaxFrameSkip()
	{
		return BalestraConfigurationGameTime::maxFrameSkip;
	}

	void BalestraConfigurationGameTime::setMaxFrameSkip(int FPS)
	{
		BalestraConfigurationGameTime::maxFrameSkip = FPS;
	}
}

