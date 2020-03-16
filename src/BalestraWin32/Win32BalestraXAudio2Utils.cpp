// == BALESTRA ENGINE FOR WINDOWS - Codecraft Productions
// ======================================================
// Copyright @2014 - Created by Henrique.F

// == REFERENCES
// =====================================================

#include "Win32BalestraPrecompiledHeader.h"
#include "Win32BalestraXAudio2Utils.h"

namespace BalestraEngine
{
	// == IMPLEMENTATION: Methods
	// =====================================================

	HRESULT Win32BalestraXAudio2Utils::findChunk(HANDLE file, DWORD fourCC, DWORD& dwChunkSize, DWORD& dwChunkDataPosition)
	{
		HRESULT hr = S_OK;

		if (INVALID_SET_FILE_POINTER == SetFilePointer(file, 0, NULL, FILE_BEGIN))
		{
			hr = HRESULT_FROM_WIN32(GetLastError());
		}

		if (FAILED(hr))
		{
			return hr;
		}

		DWORD dwChunkType;
		DWORD dwChunkDataSize;
		DWORD dwRIFFDataSize = 0;
		DWORD dwFileType;
		DWORD bytesRead = 0;
		DWORD dwOffset = 0;

		while (hr == S_OK)
		{
			DWORD dwRead;

			if (0 == ReadFile(file, &dwChunkType, sizeof(DWORD), &dwRead, NULL))
			{
				hr = HRESULT_FROM_WIN32(GetLastError());
			}

			if (0 == ReadFile(file, &dwChunkDataSize, sizeof(DWORD), &dwRead, NULL))
			{
				hr = HRESULT_FROM_WIN32(GetLastError());
			}

			switch (dwChunkType)
			{
				case fourccRIFF:

					dwRIFFDataSize = dwChunkDataSize;
					dwChunkDataSize = 4;

					if (0 == ReadFile(file, &dwFileType, sizeof(DWORD), &dwRead, NULL))
					{
						hr = HRESULT_FROM_WIN32(GetLastError());
					}

					break;

				default:

					if (INVALID_SET_FILE_POINTER == SetFilePointer(file, dwChunkDataSize, NULL, FILE_CURRENT))
					{
						return HRESULT_FROM_WIN32(GetLastError());
					}

					break;
			}

			dwOffset += sizeof(DWORD) * 2;

			if (dwChunkType == fourCC)
			{
				dwChunkSize = dwChunkDataSize;
				dwChunkDataPosition = dwOffset;
				return S_OK;
			}

			dwOffset += dwChunkDataSize;

			if (bytesRead >= dwRIFFDataSize)
			{
				return S_FALSE;
			}
		}

		return S_OK;
	}

	HRESULT Win32BalestraXAudio2Utils::readChunkData(HANDLE file, void * buffer, DWORD bufferSize, DWORD bufferOffset)
	{
		HRESULT hr = S_OK;

		if (INVALID_SET_FILE_POINTER == SetFilePointer(file, bufferOffset, NULL, FILE_BEGIN))
		{
			return HRESULT_FROM_WIN32(GetLastError());
		}

		DWORD dwRead;

		if (0 == ReadFile(file, buffer, bufferSize, &dwRead, NULL))
		{
			hr = HRESULT_FROM_WIN32(GetLastError());
		}

		return hr;
	}
}