// == BALESTRA ENGINE - Codecraft Productions
// =====================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "BalestraPrecompiledHeader.h"
#include "BalestraConfigurationVideo.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	int BalestraConfigurationVideo::getVideoInterface()
	{
		return BalestraConfigurationVideo::videoInterface;
	}

	void BalestraConfigurationVideo::setVideoInterface(int videoInterface)
	{
		BalestraConfigurationVideo::videoInterface = videoInterface;
	}

	int BalestraConfigurationVideo::getScreenWidth()
	{
		return BalestraConfigurationVideo::screenWidth;
	}

	void BalestraConfigurationVideo::setScreenWidth(int width)
	{
		BalestraConfigurationVideo::screenWidth = width;
	}

	int BalestraConfigurationVideo::getScreenHeight()
	{
		return BalestraConfigurationVideo::screenHeight;
	}

	void BalestraConfigurationVideo::setScreenHeight(int height)
	{
		BalestraConfigurationVideo::screenHeight = height;
	}

	int BalestraConfigurationVideo::getOnResize()
	{
		return BalestraConfigurationVideo::onResize;
	}

	void BalestraConfigurationVideo::setOnResize(int onResizeMode)
	{
		BalestraConfigurationVideo::onResize = onResizeMode;
	}

	int BalestraConfigurationVideo::getVideoMode()
	{
		return BalestraConfigurationVideo::videoMode;
	}

	void BalestraConfigurationVideo::setVideoMode(int videoMode)
	{
		BalestraConfigurationVideo::videoMode = videoMode;
	}
}