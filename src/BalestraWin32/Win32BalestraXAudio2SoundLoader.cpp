// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraXAudio2SoundLoader.h"
#include "Win32BalestraPlatformUtil.h"
#include "Win32BalestraXAudio2Wave.h"
#include "Win32BalestraXAudio2Utils.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	Win32BalestraXAudio2SoundLoader::Win32BalestraXAudio2SoundLoader()
	{

	}

	Win32BalestraXAudio2SoundLoader::~Win32BalestraXAudio2SoundLoader()
	{

	}

	BalestraSound* Win32BalestraXAudio2SoundLoader::loadSound(std::string soundPath, int fileType)
	{
		WAVEFORMATEXTENSIBLE wfx = { 0 };

		HRESULT hr = S_OK;

		HANDLE hFile = CreateFile(
			Win32BalestraPlatformUtil::convertCHARtoWCHAR(soundPath.c_str()),
			GENERIC_READ,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			0,
			NULL);

		if (INVALID_HANDLE_VALUE == hFile)
		{
			hr = HRESULT_FROM_WIN32(GetLastError());
		}

		if (INVALID_SET_FILE_POINTER == SetFilePointer(hFile, 0, NULL, FILE_BEGIN))
		{
			hr = HRESULT_FROM_WIN32(GetLastError());
		}

		if (FAILED(hr))
		{
			throw new BalestraSoundException("Error at load XAudio2 sound file", "", "");
		}

		DWORD dwChunkSize;
		DWORD dwChunkPosition;
		DWORD fileSountType;

		Win32BalestraXAudio2Utils::findChunk(hFile, fourccFMT, dwChunkSize, dwChunkPosition);
		Win32BalestraXAudio2Utils::readChunkData(hFile, &fileSountType, sizeof(DWORD), dwChunkPosition);

		if (fileSountType != fourccWAVE)
		{

		}

		//FMT

		Win32BalestraXAudio2Utils::findChunk(hFile, fourccFMT, dwChunkSize, dwChunkPosition);
		Win32BalestraXAudio2Utils::readChunkData(hFile, &wfx, dwChunkSize, dwChunkPosition);

		//DATA
		Win32BalestraXAudio2Utils::findChunk(hFile, fourccDATA, dwChunkSize, dwChunkPosition);
		BYTE * pDataBuffer = new BYTE[dwChunkSize];
		Win32BalestraXAudio2Utils::readChunkData(hFile, pDataBuffer, dwChunkSize, dwChunkPosition);

		//BUFFER
		XAUDIO2_BUFFER buffer = { 0 };
		buffer.AudioBytes = dwChunkSize;
		buffer.pAudioData = pDataBuffer;
		buffer.Flags = XAUDIO2_END_OF_STREAM;
		buffer.LoopCount = XAUDIO2_LOOP_INFINITE;

		Win32BalestraXAudio2Wave* XA2Wave = new Win32BalestraXAudio2Wave();
		XA2Wave->setSource(buffer);
		XA2Wave->setFormat(wfx);

		return XA2Wave;
	}

	void Win32BalestraXAudio2SoundLoader::unloadSound(BalestraSound* sound)
	{
		Win32BalestraXAudio2Wave* convertedSound = static_cast<Win32BalestraXAudio2Wave*>(sound);
		delete convertedSound->getSource().pAudioData;
		delete convertedSound;
	}
}