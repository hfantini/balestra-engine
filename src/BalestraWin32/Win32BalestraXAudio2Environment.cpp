// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraXAudio2Environment.h"
#include "Win32BalestraXAudio2Channel.h"
#include "Win32BalestraConfiguration.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	Win32BalestraXAudio2Environment::Win32BalestraXAudio2Environment(Win32BalestraConfiguration* config) : BalestraEnvironmentSound(configuration)
	{

	}

	Win32BalestraXAudio2Environment::~Win32BalestraXAudio2Environment()
	{
		cleanDevice();
	}

	void Win32BalestraXAudio2Environment::initDevice()
	{
		HRESULT hr;

		hr = XAudio2Create(&device, 0, XAUDIO2_DEFAULT_PROCESSOR);

		if (FAILED(hr))
		{
			throw new BalestraSoundException("Error at create XAudio2 Device", "", "");
		}

		device->CreateMasteringVoice(&masterVoice);

		if (FAILED(hr))
		{
			throw new BalestraSoundException("Error at create XAudio2 MasteringVoice", "", "");
		}

	}

	B_BOOL Win32BalestraXAudio2Environment::isCompatible()
	{
		return B_TRUE;
	}

	BalestraSoundChannel* Win32BalestraXAudio2Environment::createSoundChannel()
	{
		return new Win32BalestraXAudio2Channel(this);
	}

	void Win32BalestraXAudio2Environment::cleanDevice()
	{
		if (masterVoice)
		{
			masterVoice->DestroyVoice();
		}

		if (device)
		{
			device->Release();
		}
	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	IXAudio2* Win32BalestraXAudio2Environment::getDevice()
	{
		return Win32BalestraXAudio2Environment::device;
	}

	Win32BalestraConfiguration* Win32BalestraXAudio2Environment::getW32Configuration()
	{
		return static_cast<Win32BalestraConfiguration*>(configuration);
	}
}