// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraXAudio2Wave.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	XAUDIO2_BUFFER Win32BalestraXAudio2Wave::getSource()
	{
		return Win32BalestraXAudio2Wave::buffer;
	}

	void Win32BalestraXAudio2Wave::setSource(XAUDIO2_BUFFER source)
	{
		Win32BalestraXAudio2Wave::buffer = source;
	}

	WAVEFORMATEXTENSIBLE Win32BalestraXAudio2Wave::getFormat()
	{
		return Win32BalestraXAudio2Wave::format;
	}

	void Win32BalestraXAudio2Wave::setFormat(WAVEFORMATEXTENSIBLE source)
	{
		Win32BalestraXAudio2Wave::format = source;
	}
}