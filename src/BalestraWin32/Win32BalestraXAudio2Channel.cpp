// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraXAudio2Channel.h"
#include "Win32BalestraXAudio2Environment.h"
#include "Win32BalestraXAudio2Utils.h"
#include "Win32BalestraXAudio2Wave.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	Win32BalestraXAudio2Channel::Win32BalestraXAudio2Channel(Win32BalestraXAudio2Environment* audioEnv)
	{
		Win32BalestraXAudio2Channel::audioEnv = audioEnv;
	}

	Win32BalestraXAudio2Channel::~Win32BalestraXAudio2Channel()
	{
		cleanDevice();
	}

	void Win32BalestraXAudio2Channel::initDevice()
	{

	}

	B_BOOL Win32BalestraXAudio2Channel::isCompatible()
	{
		return B_TRUE;
	}

	void Win32BalestraXAudio2Channel::play()
	{
		HRESULT hr = S_OK;

		if (sourceVoice)
		{
			XAUDIO2_VOICE_STATE voiceState;
			sourceVoice->GetState(&voiceState);

			if (voiceState.BuffersQueued == 0)
			{
				Win32BalestraXAudio2Wave* XSound = static_cast<Win32BalestraXAudio2Wave*>(getCurrentSound());
				hr = sourceVoice->SubmitSourceBuffer(&(XSound->getSource()));
			}

			hr = sourceVoice->Start(0);

			if (FAILED(hr))
			{
				throw new BalestraSoundException("Error at play a sound with XAudio2", "", "");
			}
		}
		else
		{
			throw new BalestraSoundException("Error at play a sound with XAudio2", "SourceVoice pointer is NULL", "");
		}
	}

	void Win32BalestraXAudio2Channel::stop()
	{
		HRESULT hr = S_OK;

		if (sourceVoice)
		{
			hr = sourceVoice->Stop(0);

			if (FAILED(hr))
			{
				throw new BalestraSoundException("Error at stop a sound with XAudio2", "", "");
			}

			hr = sourceVoice->FlushSourceBuffers();

			if (FAILED(hr))
			{
				throw new BalestraSoundException("Error at stop a sound with XAudio2", "", "");
			}
		}
		else
		{
			throw new BalestraSoundException("Error at stop a sound with XAudio2", "SourceVoice pointer is NULL", "");
		}
	}

	void Win32BalestraXAudio2Channel::pause()
	{
		HRESULT hr = S_OK;

		if (sourceVoice)
		{
			hr = sourceVoice->Stop(0);

			if (FAILED(hr))
			{
				throw new BalestraSoundException("Error at pause a sound with XAudio2", "", "");
			}
		}
		else
		{
			throw new BalestraSoundException("Error at pause a sound with XAudio2", "SourceVoice pointer is NULL", "");
		}
	}

	void Win32BalestraXAudio2Channel::cleanDevice()
	{

	}

	// == IMPLEMENTATION: Getters and Setters
	// =====================================================

	void Win32BalestraXAudio2Channel::setCurrentSound(BalestraSound* sound)
	{
		HRESULT hr = S_OK;

		Win32BalestraXAudio2Channel::currentSound = sound;

		Win32BalestraXAudio2Wave* XSound = static_cast<Win32BalestraXAudio2Wave*>(sound);

		hr = audioEnv->getDevice()->CreateSourceVoice(&sourceVoice, (WAVEFORMATEX*)&(XSound->getFormat()));

		if (FAILED(hr))
		{
			throw new BalestraSoundException("Error at set current sount to a voice with XAudio2", "", "");
		}
	}
}