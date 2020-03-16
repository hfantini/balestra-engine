// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraConfiguration.h"
#include "Win32BalestraConfigurationInput.h"
#include "Win32BalestraConfigurationPlatform.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================
	Win32BalestraConfiguration::Win32BalestraConfiguration()
	{
		BalestraConfiguration::BalestraConfiguration();

		inputConfiguration = new Win32BalestraConfigurationInput();
		platformConfiguration = new Win32BalestraConfigurationPlatform();

		OutputDebugStringA("Instanced");
	}

	Win32BalestraConfiguration::~Win32BalestraConfiguration()
	{
		if (inputConfiguration)
		{
			delete static_cast<Win32BalestraConfigurationInput*>(inputConfiguration);
		}

		if (platformConfiguration)
		{
			delete platformConfiguration;
		}
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	Win32BalestraConfigurationPlatform* Win32BalestraConfiguration::getPlatformConfiguration()
	{
		return Win32BalestraConfiguration::platformConfiguration;
	}

	Win32BalestraConfigurationInput* Win32BalestraConfiguration::getWin32InputConfiguration()
	{
		return static_cast<Win32BalestraConfigurationInput*>(inputConfiguration);
	}
}